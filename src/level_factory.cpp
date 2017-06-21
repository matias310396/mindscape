#include "level_factory.hpp"
#include <fstream>

using namespace engine;

Level* game::LevelFactory::fabricate_level(){
  engine::Game& game = engine::Game::get_instance();
  Level* first_level = new Level();
  game::GameObjectFactory* factory = new game::GameObjectFactory();

  // Record logic
  std::fstream record("../assets/doc/record.txt");
  std::string aux;
  getline(record, aux);
  Text* p_record = new Text("Recorde: " + aux, "../assets/fonts/FFF_Tusj.ttf", 35, game.renderer);
  GameObject* previous_record = new GameObject("previous_record", std::make_pair(10,0), 2, {{}});
  previous_record->add_component(p_record);

  // Music
  Audio* music = new Audio("../assets/audios/Sonic.mp3", Audio::audio_type::music);
  GameObject * audio_loop =  new GameObject("audio_loop", std::make_pair(0,0),1,{});
  audio_loop->add_component(music);

  // Background
  Image* level_design = new Image(game.renderer, "../assets/images/individual-level.jpg", true, std::make_pair(0, 0),1);
  level_design-> set_values(std::make_pair(1024, 578), std::make_pair(5084, 704), std::make_pair(0, 0));
  Background* background = new Background("background", std::make_pair(0,0), 1);
  background->add_component(level_design);

  // Floor
  Image* ground_design = new Image(game.renderer, "../assets/images/plataforma.png", false, std::make_pair(0,0), 2);
  GameObject* ground = new Platform("ground", std::make_pair(0, 470), 2);
  Hitbox* ground_hitbox = new Hitbox("ground_hitbox", ground->position, std::make_pair(40,70), std::make_pair(5500,30), game.renderer);
  ground->add_component(ground_hitbox);
  ground->add_component(ground_design);

  first_level->add_object(background);
  first_level->add_object(previous_record);
  first_level->add_object(ground);
  first_level->add_object(audio_loop);
  first_level->add_object(factory->fabricate("little_girl", std::make_pair(0, 0), "girl"));

  // Thorns
  first_level->add_object(factory->fabricate("thorn", std::make_pair(1200, 431), "thorn1"));
  first_level->add_object(factory->fabricate("thorn", std::make_pair(1300, 431), "thorn2"));
  first_level->add_object(factory->fabricate("thorn", std::make_pair(3000, 431), "thorn3"));
  first_level->add_object(factory->fabricate("thorn", std::make_pair(3100, 431), "thorn4"));
  first_level->add_object(factory->fabricate("thorn", std::make_pair(3200, 431), "thorn5"));
  first_level->add_object(factory->fabricate("thorn", std::make_pair(3300, 431), "thorn6"));
  first_level->add_object(factory->fabricate("thorn", std::make_pair(4100, 280), "thorn7"));
  first_level->add_object(factory->fabricate("thorn", std::make_pair(4600, 431), "thorn8"));
  first_level->add_object(factory->fabricate("thorn", std::make_pair(4900, 431), "thorn9"));

  // Platforms
  first_level->add_object(factory->fabricate("platform", std::make_pair(800, 300), "platform1"));
  first_level->add_object(factory->fabricate("platform", std::make_pair(1300, 300), "platform2"));
  first_level->add_object(factory->fabricate("platform", std::make_pair(2500, 300), "platform3"));
  first_level->add_object(factory->fabricate("platform", std::make_pair(2800, 100), "platform4"));
  first_level->add_object(factory->fabricate("platform", std::make_pair(3800, 300), "platform5"));
  first_level->add_object(factory->fabricate("platform", std::make_pair(4200, 100), "platform6"));
  first_level->add_object(factory->fabricate("platform", std::make_pair(4900, 300), "platform7"));

  // Coins
  first_level->add_object(factory->fabricate("coin", std::make_pair(920, 300), "coin1"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(1000, 300), "coin2"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(1080, 300), "coin3"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(1400, 300), "coin4"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(2000, 480), "coin5"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(2100, 480), "coin6"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(2200, 480), "coin7"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(2900, 100), "coin8"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(3000, 100), "coin9"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(4300, 100), "coin10"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(4380, 100), "coin11"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(4460, 100), "coin12"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(4920, 300), "coin13"));
  first_level->add_object(factory->fabricate("coin", std::make_pair(4980, 300), "coin14"));

  return first_level;
}
