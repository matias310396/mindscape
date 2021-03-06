#include "game_object_factory.hpp"

using namespace game;

engine::GameObject* GameObjectFactory::fabricate(std::string name, std::pair<int, int> position, std::string object_name=""){
  if(name == "little_girl"){
    return fabricate_little_girl(position, object_name);
  }else if(name == "thorn"){
    return fabricate_thorn(position, object_name);
  }else if(name == "coin"){
    return fabricate_coin(position, object_name);
  }else if(name == "platform"){
    return fabricate_platform(position, object_name);
  }else{
    return NULL;
  }
}

engine::GameObject* GameObjectFactory::fabricate_platform(std::pair<int, int> position, std::string object_name){
  engine::Game& game = engine::Game::get_instance();
  engine::Image* platform_image = new engine::Image(game.renderer, "../assets/images/plataforma.png", true, std::make_pair(0,0), 2);
  platform_image-> set_values(std::make_pair(507, 256), std::make_pair(507, 256), std::make_pair(0, 0));

  engine::GameObject* platform = new engine::Platform(object_name, position, 2);
  engine::Hitbox* hitbox = new engine::Hitbox("hitbox", platform->position, std::make_pair(40,70), std::make_pair(400,30), game.renderer);
  platform->add_component(platform_image);
  platform->add_component(hitbox);
  return platform;
}

engine::GameObject* GameObjectFactory::fabricate_thorn(std::pair<int, int> position, std::string object_name){
  engine::Game& game = engine::Game::get_instance();
  engine::Image* thorn_image = new engine::Image(game.renderer, "../assets/images/thorn.png", true, std::make_pair(0,0), 2);
  thorn_image-> set_values(std::make_pair(144, 109), std::make_pair(144, 109), std::make_pair(0,0));

  engine::GameObject* thorn = new Thorn(object_name, position, 2);
  engine::Hitbox* hitbox= new engine::Hitbox("hitbox", thorn->position, std::make_pair(0, 0), std::make_pair(120, 109), game.renderer);
  thorn->add_component(thorn_image);
  thorn->add_component(hitbox);
  return thorn;
}

engine::GameObject* GameObjectFactory::fabricate_coin(std::pair<int, int> position, std::string object_name){
  engine::Game& game = engine::Game::get_instance();
  engine::Image* coin_image = new engine::Image(game.renderer, "../assets/images/coin.png", true, std::make_pair(0,0), 2);
  coin_image-> set_values(std::make_pair(50, 50), std::make_pair(278, 236), std::make_pair(0,0));

  engine::GameObject* coin = new game::Coin(object_name, position, 2);
  engine::Hitbox* hitbox= new engine::Hitbox("hitbox", coin->position, std::make_pair(0, 0), std::make_pair(50, 50), game.renderer);
  coin->add_component(coin_image);
  coin->add_component(hitbox);
  return coin;
}

engine::GameObject* GameObjectFactory::fabricate_little_girl(std::pair<int, int>, std::string object_name){
  engine::Game& game = engine::Game::get_instance();

  std::pair<int, int> place (416, 335);

  //Creating running right image
  engine::Image* image_running_right = new engine::Image(
    game.renderer,
    "../assets/images/menina_correndo_direita.png",
    true,
    std::make_pair(0, 0),
    2
  );
  image_running_right->set_values(
    std::make_pair(192, 192),
    std::make_pair(192, 192),
    std::make_pair(0, 0)
  );

  //Creating running right image
  engine::Image* image_running_left = new engine::Image(
    game.renderer,
    "../assets/images/menina_correndo_esquerda.png",
    false,
    std::make_pair(0, 0),
    2
  );
  image_running_left->set_values(
    std::make_pair(192, 192),
    std::make_pair(192, 192),
    std::make_pair(0, 0)
  );

  engine::GameObject* little_girl = new engine::LittleGirl("little_girl", place, 52);
  engine::Hitbox* hitbox= new engine::Hitbox("hitbox", little_girl->position, std::make_pair(60, 180), std::make_pair(50,40), game.renderer);
  engine::Hitbox* dorso= new engine::Hitbox("dorso", little_girl->position, std::make_pair(60, 150), std::make_pair(50,40), game.renderer);

  little_girl->collidable = true;
  little_girl->add_component(image_running_right);
  little_girl->add_component(image_running_left);
  little_girl->add_component(hitbox);
  little_girl->add_component(dorso);

  return little_girl;
}
