#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "menu.hpp"

class Game {
public:
  Game();
  operator bool() const;
  void operator ()();
  void drawMainMenu();

protected:
  sf::RenderWindow window_;
  Menu mainMenu_;
  sf::Font font_;
};

#endif //!GAME_HPP
