#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "../include/platform.hpp"
#include "../include/game_object_factory.hpp"
#include "../include/level_factory.hpp"
#include "../engine/include/game.hpp"
#include "../engine/include/audio.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/text.hpp"
#include "../engine/include/scene.hpp"
#include "../engine/include/level.hpp"
#include "../engine/include/animation.hpp"
#include "../include/globals.hpp"
#include "../include/background.hpp"
#include "../include/thorn.hpp"
#include "../include/coin.hpp"

using namespace engine;

int main(int,char**){
  game::LevelFactory* level_factory = new game::LevelFactory();
  
  Game& game = Game::get_instance();
  game.set_information(globals::game_name,globals::window_size);
  game.game_init();

  Level* level = level_factory->fabricate_level();
  
  game.add_scene("first level", level);
  game.change_scene("first level");
  game.run();
  return 0;
}
