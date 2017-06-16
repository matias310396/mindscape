#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "../include/platform.hpp"
#include "../include/game_object_factory.hpp"
#include "../engine/include/game.hpp"
#include "../engine/include/audio.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/text.hpp"
#include "../engine/include/scene.hpp"
#include "../engine/include/level.hpp"
#include "../engine/include/animation.hpp"
#include "../include/globals.hpp"
#include "../include/background.hpp"
#include "../include/fox.hpp"
#include "../include/select_arrow.hpp"
#include "../include/button.hpp"
#include "../include/thorn.hpp"
#include "../include/coin.hpp"

using namespace engine;

int main(int,char**){
  // Game variables
  std::fstream record("../assets/doc/record.txt");
  std::string aux;
  getline(record, aux);

  Game& game = Game::get_instance();
  game.set_information(globals::game_name,globals::window_size);
  game.game_init();

  //Images
  Image* images1 = new Image(game.renderer, "../assets/images/menina_correndo_direita.png", true, std::make_pair(0, 0),1);
  Image* images2 = new Image(game.renderer, "../assets/images/menina_correndo_esquerda.png", false, std::make_pair(0, 0), 2);
  Image* images3 = new Image(game.renderer, "../assets/images/plataforma.png", true, std::make_pair(0,0), 2);
  Image* images4 = new Image(game.renderer, "../assets/images/individual-level.jpg", true, std::make_pair(0, 0),1);
  Image* images5 = new Image(game.renderer, "../assets/images/plataforma.png", false, std::make_pair(0,0), 2);
  // Image* images6 = new Image(game.renderer, "../assets/images/coin.png", true, std::make_pair(0,0), 2);
  // Image* images7 = new Image(game.renderer, "../assets/images/thorn.png", true, std::make_pair(0,0), 2);

  images1-> set_values(std::make_pair(192, 192), std::make_pair(192, 192), std::make_pair(0, 0));
  images2-> set_values(std::make_pair(192, 192), std::make_pair(192, 192), std::make_pair(0, 0));
  images3-> set_values(std::make_pair(507, 256), std::make_pair(507, 256), std::make_pair(0, 0));
  images4-> set_values(std::make_pair(1024, 578), std::make_pair(5084, 704), std::make_pair(0, 0));
  Text* p_record = new Text("Recorde: " + aux, "../assets/fonts/FFF_Tusj.ttf", 35, game.renderer);
  // images6-> set_values(std::make_pair(50, 50), std::make_pair(278, 236), std::make_pair(0,0));
  // images7-> set_values(std::make_pair(144, 109), std::make_pair(144, 109), std::make_pair(0,0));

  //GameObjects variables

  game::GameObjectFactory sonic_factory = game::GameObjectFactory();
  Background* background = new Background("background", std::make_pair(0,0), 1);
  GameObject* platform = new Platform("platform", std::make_pair(800, 300), 2);
  GameObject* platform2 = new Platform("platform2", std::make_pair(0, 470), 2);
  GameObject* little_girl = sonic_factory.fabricate("little_girl", std::make_pair(0,0), "");

  GameObject* previous_record = new GameObject("previous_record", std::make_pair(10,0), 2, {{}});
  // GameObject* coin = new game::Coin("coin", std::make_pair(850, 320), 2);

  // Ground y is 431
  // GameObject* thorn = new game::Thorn("thorn", std::make_pair(1200, 431), 2);

  Hitbox* hitbox = new Hitbox("hitbox", platform->position, std::make_pair(40,70), std::make_pair(400,30), game.renderer);
  Hitbox* hitbox2 = new Hitbox("hitbox2", platform2->position, std::make_pair(40,70), std::make_pair(4000,30), game.renderer);


  // Adding Components
  platform->add_component(hitbox);
  platform->add_component(images3);
  platform2->add_component(images5);
  platform2->add_component(hitbox2);
  platform->add_component(hitbox);
  previous_record->add_component(p_record);
  background->add_component(images4);
  // coin->add_component(images6);
  // thorn->add_component(images7);
  GameObject* thorn = sonic_factory.fabricate("thorn", std::make_pair(1200, 431), "thorn");
  GameObject* coin = sonic_factory.fabricate("coin", std::make_pair(850, 320), "coin");
  // Adding objects to level

  Level* level1 = new Level();
  level1->add_object(little_girl);
  level1->add_object(coin);
  level1->add_object(background);
  level1->add_object(platform);
  level1->add_object(platform2);
  level1->add_object(thorn);
  level1->add_object(previous_record);
  level1->activate_game_object("little_girl");
  level1->activate_game_object("coin");
  level1->activate_game_object("thorn");
  level1->activate_game_object("previous_record");
  level1->activate_game_object("background");
  level1->activate_game_object("platform");
  level1->activate_game_object("platform2");
  level1->activate_game_object("ground");
  for(auto object : level1->objects){
    printf("%s and %d\n", object->name.c_str(), object->active_game_object);
  }

  game.add_scene("first level", level1);
  game.change_scene("first level");

  game.run();
  return 0;
}
