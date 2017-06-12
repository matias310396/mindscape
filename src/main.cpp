#include <iostream>
#include <unordered_map>
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

using namespace engine;

int main(int,char**){
  // Game variables
  Game& game = Game::get_instance();
  game.set_information(globals::game_name,globals::window_size);
  game.game_init();

  //Images
  Image* images1 = new Image(game.renderer, "../assets/images/menina_correndo_direita.png", true, std::make_pair(0, 0),1);
  Image* images2 = new Image(game.renderer, "../assets/images/menina_correndo_esquerda.png", false, std::make_pair(0, 0), 2);
  Image* images3 = new Image(game.renderer, "../assets/images/plataforma.png", true, std::make_pair(0,0), 2);
  Image* images4 = new Image(game.renderer, "../assets/images/individual-level.jpg", true, std::make_pair(0, 0),1);
  Image* images5 = new Image(game.renderer, "../assets/images/plataforma.png", false, std::make_pair(0,0), 2);

  images1-> set_values(std::make_pair(192, 192), std::make_pair(192, 192), std::make_pair(0, 0));
  images2-> set_values(std::make_pair(192, 192), std::make_pair(192, 192), std::make_pair(0, 0));
  images3-> set_values(std::make_pair(507, 256), std::make_pair(507, 256), std::make_pair(0, 0));
  images4-> set_values(std::make_pair(1024, 578), std::make_pair(5084, 704), std::make_pair(0, 0));

  //GameObjects variables
  mindscape::GameObjectFactory mindscape_factory = mindscape::GameObjectFactory();
  Background* background = new Background("background", std::make_pair(0,0), 1);
  GameObject* platform = new Platform("platform", std::make_pair(800, 300), 2);
  GameObject* platform2 = new Platform("platform2", std::make_pair(0, 470), 2);
  GameObject* little_girl = mindscape_factory.fabricate(mindscape::GameObjectFactory::LITTLE_GIRL);
  Hitbox* hitbox = new Hitbox("hitbox", platform->position, std::make_pair(40,70), std::make_pair(400,30), game.renderer);
  Hitbox* hitbox2 = new Hitbox("hitbox2", platform2->position, std::make_pair(40,70), std::make_pair(4000,30), game.renderer);

  // Adding Components
  platform->add_component(hitbox);
  platform->add_component(images3);
  platform2->add_component(images5);
  platform2->add_component(hitbox2);
  platform->add_component(hitbox);
  background->add_component(images4);


  // Adding objects to level
  Level* level1 = new Level();
  level1->add_object(little_girl);
  level1->add_object(background);
  level1->add_object(platform);
  level1->add_object(platform2);
  level1->activate_game_object("little_girl");
  level1->activate_game_object("background");
  level1->activate_game_object("platform");
  level1->activate_game_object("platform2");
  level1->activate_game_object("ground");

  game.add_scene("first level", level1);
  game.change_scene("first level");

  game.run();
  return 0;
}
