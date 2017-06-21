#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include "../engine/include/game_object.hpp"
#include "../engine/include/audio.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/text.hpp"
#include "../engine/include/level.hpp"
#include "../engine/include/game.hpp"
#include "background.hpp"
#include "game_object_factory.hpp"
#include "platform.hpp"
#include "little_girl.hpp"
#include "thorn.hpp"
#include "coin.hpp"
#include <iostream>
#include <string>


namespace game {
  class LevelFactory {
    public:
      LevelFactory(){};
      ~LevelFactory(){};

      engine::Level* fabricate_level();
  };
}

#endif
