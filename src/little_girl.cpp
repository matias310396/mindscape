#include "../include/little_girl.hpp"
#include "../include/platform.hpp"
#include <typeinfo>
#include <algorithm>
#include <fstream>

using namespace engine;

void LittleGirl::on_collision(GameObject* other, Hitbox* p_my_hitbox, Hitbox* p_other_hitbox){
  Hitbox* my_hitbox = dynamic_cast<Hitbox *>(p_my_hitbox);
  Hitbox* other_hitbox = dynamic_cast<Hitbox *>(p_other_hitbox);

  if(state == "FALLING" && dynamic_cast<Platform *>(other)){
    on_floor = true;
    speed.second = 0;
    position.second = other_hitbox->get_coordinates().second-180;
    state = "GROUND";
  }

  if(dynamic_cast<game::Thorn *>(other)){
    printf("COLIDI COM THORN\n");
    std::fstream record("../assets/doc/record.txt");
    std::string aux;
    getline(record, aux);
    record.close();
    if(coin_count > std::stoi(aux, nullptr)){
      for(int i=0; i<10; ++i) printf("%d\n", coin_count);
      std::fstream record("../assets/doc/record.txt");
      record << std::to_string(coin_count);
    }

    printf("RECORDE: %s", aux.c_str());
    record.close();
    exit(EXIT_SUCCESS);
  }

  if(dynamic_cast<game::Coin *>(other)){
    coin_count++;
    printf("Moedas: %d\n", coin_count);
    p_other_hitbox->deactivate();
    other->images.front()->deactivate();
  }
}

void LittleGirl::update(unsigned delta){
  if(!on_floor) speed.second += 0.02 * delta;
  // printf("speed: %f\n", speed.second);
  if(speed.second > 1){
    speed.second = 1;
  }
  if(speed.second >= 0){
    state = "FALLING";
  }
  position.second += speed.second * delta;
  on_floor = false;
}

void LittleGirl::on_event(GameEvent game_event){
  std::string event_name = game_event.game_event_name;

  Image* moving_left_image = dynamic_cast<Image*>(images[1]);
  Image* moving_right_image = dynamic_cast<Image*>(images[0]);

  //Verifying if its on the ground
  if(event_name == "JUMP" && speed.second == 0){
    state = "JUMPING";
    speed.second = -3.5;
  }else if(event_name == "MOVE_LEFT"){
    moving_right_image->deactivate();
    moving_left_image->activate();

    animation_count2 +=1;
    if(animation_count2 == 5){
      moving_left_image->coordinatesOnTexture.first -= 192;
      animation_count2 = 0;
    }
    if(moving_left_image->coordinatesOnTexture.first <= 0)
      moving_left_image->coordinatesOnTexture.first = 1536;
  }else if(event_name == "MOVE_RIGHT"){
    moving_left_image->deactivate();
    moving_right_image->activate();

    animation_count +=1;
    if(animation_count == 5){
      moving_right_image->coordinatesOnTexture.first += 192;
      animation_count = 0;
    }

    if(moving_right_image->coordinatesOnTexture.first >= 1728)
      moving_right_image->coordinatesOnTexture.first = 0;

  }
}
