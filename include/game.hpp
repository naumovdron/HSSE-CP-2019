#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.hpp"
#include "fields.hpp"

class Game {
public:
  Game();
  operator bool() const;
  void operator ()();
protected:
  sf::RenderWindow window_;
  sf::Font font_;
  sf::Music stepMusic_;
  //store current state of game
  void (Game::*currentHandle_) ();
  Menu mainMenu_;
  Fields fields_;

  void handleMainMenu();
  void drawMainMenu();

  void handleFields();
  void drawFields();

  void handleWin();
  void drawWin();
};

#endif //!GAME_HPP
