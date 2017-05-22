#include "../include/game.hpp"
#include <iostream>

using namespace engine;

typedef struct info{
  int x;
  int y;
  int width;
  int height;
}info;

Game* Game::instance = NULL;

void throw_error(const char* function){
  printf("Something's wrong in %s\n", function);
  exit(-1);
}

Game& Game::get_instance(){
  if(!instance){
    instance = new Game();
  }
  return *instance;
}

void Game::game_init(){
  int img_flags = IMG_INIT_PNG;

  if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0){
    throw_error("SDL_Init");
  }
  if(!(IMG_Init(IMG_INIT_PNG) & img_flags)){
    throw_error("IMG_Init");
  }

  window = SDL_CreateWindow(game_name.c_str(),SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,window_dimensions.first,
      window_dimensions.second,SDL_WINDOW_SHOWN);
  if(!window){
    throw_error("SDL_CreateWindow");
  }
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(!renderer){
    throw_error("SDL_CreateRenderer");
  }
}

bool Game::load_media(){
  bool success_on_load = true;
  std::string path_1 = "../assets/images/menina_correndo.png";
  std::string path_2 = "../assets/images/test_background.png";
  std::string path_3 = "../assets/images/attack.png";
  std::string path_4 = "../assets/images/raposa_correndo.png";

  if(!images[1]->load(path_1.c_str())){
    printf("Failed to load media at %s\n",path_1.c_str());
    success_on_load = false;
  }

  if(!images[2]->load(path_2.c_str())){
    printf("Failed to load media at %s\n",path_2.c_str());
    success_on_load = false;
  }

  if(!images[3]->load(path_3.c_str())){
    printf("Failed to load media at %s\n",path_3.c_str());
    success_on_load = false;
  }

  if(!images[4]->load(path_4.c_str())){
    printf("Failed to load media at %s\n", path_4.c_str());
    success_on_load = false;
  }

  return success_on_load;
}

void Game::close(){
  //TODO add steps to deallocate all rendered textures
  images[1]->free();
  images[2]->free();
  images[3]->free();
  images[4]->free();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  renderer = NULL;
  window = NULL;

  IMG_Quit();
  SDL_Quit();
}

void Game::run(){
  game_init();
  images[1] = new Image(renderer);
  images[2] = new Image(renderer);
  images[3] = new Image(renderer);
  images[4] = new Image(renderer);
  info inf;

  int right_cont = 0, left_cont = 0;

  inf.x = 0;
  inf.y = 0;
  inf.width = 192;
  inf.height = 192;
  std::pair<int,int> pos; pos.first =240;pos.second = 100;
  std::pair<int, int> pos_fox;
  pos_fox.first = pos.first - 120;
  pos_fox.second = pos.second + 70;

  bool jumping = false;
  bool walking_left = false;
  bool walking_rigth = false;
  bool attacking = false;
  bool crouching = false;

  if(load_media()){
    bool quit_event = false;

    SDL_Event e;
    SDL_Rect ret; SDL_Rect* rt = &ret;
    SDL_Rect ret_2; SDL_Rect* rt_2 = &ret_2;
    SDL_Rect ret_attack;
    SDL_Rect* rt_a = &ret_attack;

    SDL_Rect ret_fox;
    SDL_Rect *rt_fox = &ret_fox;

    ret.x = 0; ret.y = 0; ret.w = 192; ret.h = 192;
    ret_fox.x = 0; ret_fox.y = 0; ret_fox.w = 120; ret_fox.h = 120;
    ret_2.x = 0; ret_2.y = 0; ret_2.w = 1024; ret_2.h = 576;
    ret_attack.x = 0, ret_attack.y = 0; ret_attack.w = 418; ret_attack.h = 224;

    while(!quit_event){
      while(SDL_PollEvent( &e ) != 0){
        if(e.type == SDL_QUIT){
          quit_event = true;
        }
      }
      const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

      if( currentKeyStates[ SDL_SCANCODE_LEFT ] ){
        walking_left = true;
      } else {
        walking_left = false;
      }

      if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ){
        walking_rigth = true;
      } else {
        walking_rigth = false;
      }


      if(currentKeyStates[SDL_SCANCODE_UP] && !jumping){
        if(pos.second >= 250){
          jumping = true;
        }
      }

      if(currentKeyStates[SDL_SCANCODE_SPACE]){
          attacking = true;
        }

      if(currentKeyStates[SDL_SCANCODE_DOWN]){
          crouching = true;
        } else {
          crouching = false;
        }

      //Crouching
      if(crouching && walking_rigth == false && walking_left == false){
        left_cont++;
        if(left_cont == 5){
          if(ret.y == 140) ret.y = 0;
          ret.x+=192;
          if(ret.x == 1728) ret.x = 0;
          left_cont = 0;

        }
      }


      //Walking LEFT
      if(walking_left == true && walking_rigth == false){
        //right_cont++;
        //if(right_cont == 5){
          //if(ret.y == 0) ret.y = 140;
          //ret.x -= 108;
          //if(ret.x < 0) ret.x = 756;
          //right_cont = 0;

          //pos.first -= 20;
       //   if(pos.first < 0) pos.first = 700;
        //}
      }

      //Walking RIGHT
      if(walking_rigth == true && walking_left == false){
        left_cont++;
        if(left_cont == 5){
          if(ret.y == 140) ret.y = 0;
          if(ret_fox.y == 120) ret_fox.y = 0;
          ret.x+=192;
          ret_fox.x += 120;
          if(ret.x == 1728) ret.x = 0;
          if(ret_fox.x == 1080) ret_fox.x = 0;
          left_cont = 0;

          pos.first += 20;
          pos_fox.first = pos.first - 110;
          pos_fox.second = pos.second +70;
          if(pos.first > 1024) pos.first = -192;
          if(pos_fox.first > 1024) pos_fox.first = -192;
        }
      }


      //jumping
      if(jumping && pos.second >= 250){
          pos.second -= 20;
          //std::cout << "subiu" << std::endl;
      } else {
        jumping = false;
      }

      //gravity
      if(pos.second < 260){
        pos.second += 10;
        pos_fox.second = pos.second + 70;
      }

      //atacking
      if(attacking){

          ret_attack.y = -74;
          ret_attack.x = -418;

      }

      SDL_SetRenderDrawColor(renderer,0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderClear(renderer);
      images[2]->render(0,0,rt_2);
      images[4]->render(pos_fox.first,pos_fox.second,rt_fox);

      if(attacking){
        images[3]->render(pos.first,pos.second,rt_a);
        attacking = false;
      } else {
        images[1]->render(pos.first,pos.second,rt);
      }
      SDL_RenderPresent(renderer);
    }
  }
  else{
    printf("Medias could not be loaded\n");
  }

  close();
}

void Game::set_information(std::string name,std::pair<int,int> dimensions){
  game_name = name;
  window_dimensions = dimensions;
}
