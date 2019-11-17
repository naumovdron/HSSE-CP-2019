#include "menu.hpp"

Menu::Menu(const Buttons& buttons):
  buttons_(buttons),
  currentButton_(buttons_.begin())
{}

sf::Text& Menu::operator[](size_t index)
{
  return buttons_[index];
}

size_t Menu::size() const
{
  return buttons_.size();
}

Buttons::iterator Menu::begin()
{
  return buttons_.begin();
}

Buttons::iterator Menu::end()
{
  return buttons_.end();
}
