#ifndef SONIC_H
#define SONIC_H


#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../engine/include/game_object.hpp"
#include "../engine/include/keyboard_event.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/game_object.hpp"

namespace game {
  class Coin : public engine::GameObject {
    public:

      Coin(std::pair<int, int> position, int priority){
        GameObject("Coin", position, priority, {});
      };

      ~Coin(){};

      void update();
      void on_event(GameEvent game_event);
  };
}


#endif
