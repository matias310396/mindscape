#include "../include/thorn.hpp"

using namespace game;

void Thorn::on_event(GameEvent game_event){
  std::string event_name = game_event.game_event_name;
  engine::Image* platform_image = dynamic_cast<engine::Image*>(images[0]);

  if(event_name == "MOVE_LEFT" && !GameObject::on_limit_of_level){
    position.first += 10;
  }else if(event_name == "MOVE_RIGHT" && !GameObject::on_limit_of_level){
    position.first -= 10;
  }
}

void Thorn::update(){}
