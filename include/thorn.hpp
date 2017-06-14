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
  class Thorn : public engine::GameObject {
    public:

      Thorn(std::string p_name, std::pair<int, int> position, int p): engine::GameObject(p_name, position, p,
      {
        {engine::KeyboardEvent::LEFT,"MOVE_LEFT"},
        {engine::KeyboardEvent::RIGHT,"MOVE_RIGHT"},
      }){};
      ~Thorn(){};

      void update();
      void on_event(GameEvent game_event);
  };
}


#endif
