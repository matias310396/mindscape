#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include "../engine/include/game_object.hpp"
#include "../engine/include/audio.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/text.hpp"
#include "../engine/include/game.hpp"
#include "platform.hpp"
#include "little_girl.hpp"
#include "thorn.hpp"
#include "coin.hpp"
#include <iostream>
#include <string>

namespace game {
  class GameObjectFactory {
    public:
      GameObjectFactory(){};
      ~GameObjectFactory(){};

      engine::GameObject* fabricate(std::string, std::pair<int, int>, std::string);

    private:
      engine::GameObject* fabricate_platform(std::pair<int, int>, std::string);
      engine::GameObject* fabricate_thorn(std::pair<int, int>, std::string);
      engine::GameObject* fabricate_coin(std::pair<int, int>, std::string);
      engine::GameObject* fabricate_little_girl(std::pair<int, int>, std::string);
  };
}

#endif
