#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>

using Buttons = std::vector<sf::Text>;

class Menu {
public:
  Buttons buttons_;
  Buttons::iterator currentButton_;
  explicit Menu(const Buttons& buttons);
  sf::Text& operator[](size_t index);
  size_t size() const;
  Buttons::iterator begin();
  Buttons::iterator end();
};

#endif //!MENU_HPP
