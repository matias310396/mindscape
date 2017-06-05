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
  class Sonic : public engine::GameObject {
    public:

      Sonic(std::pair<int, int> position, int priority){
        GameObject("Sonic", position, priority,
        {
          {engine::KeyboardEvent::LEFT, "MOVE_LEFT"},
          {engine::KeyboardEvent::RIGHT, "MOVE_RIGHT"},
          {engine::KeyboardEvent::UP, "JUMP"}
        });
      };

      ~Sonic(){};

      void update();
      void on_event(GameEvent game_event);
  };
}


#endif
