#ifndef COIN_H
#define COIN_H


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

      Coin(std::string p_name, std::pair<int, int> position, int p): engine::GameObject(p_name, position, p,
      {
        {engine::KeyboardEvent::LEFT,"MOVE_LEFT"},
        {engine::KeyboardEvent::RIGHT,"MOVE_RIGHT"},
      }){};

      ~Coin(){};

      void update();
      void on_event(GameEvent game_event);
  };
}


#endif
