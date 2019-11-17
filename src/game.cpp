#include "game.hpp"
#include <exception>
#include <stdexcept>

Game::Game():
  window_(sf::VideoMode(800, 400), "Gravity Defied", sf::Style::Close | sf::Style::Titlebar),
  mainMenu_(Buttons(3))
{
  window_.setVerticalSyncEnabled(true);
  sf::Image icon;
  if (!icon.loadFromFile("../resources/icon.jpg")) {
    throw std::invalid_argument("Can't load font icon file");
  }
  window_.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
  if (!font_.loadFromFile("../resources/Alata-Regular.ttf")) {
    throw std::invalid_argument("Can't load font from file");
  }
  mainMenu_[0].setFont(font_);
  mainMenu_[1].setFont(font_);
  mainMenu_[2].setFont(font_);
  mainMenu_[0].setString("Play>");
  mainMenu_[1].setString("About");
  mainMenu_[2].setString("Exit");
  mainMenu_[0].setFillColor({102, 195, 142, 255});
  mainMenu_[1].setFillColor({0, 0, 0, 255});
  mainMenu_[2].setFillColor({0, 0, 0, 255});
  mainMenu_[0].setPosition(20, 20);
  mainMenu_[1].setPosition(20, 50);
  mainMenu_[2].setPosition(20, 80);
  mainMenu_[0].setCharacterSize(20);
  mainMenu_[1].setCharacterSize(20);
  mainMenu_[2].setCharacterSize(20);
}

Game::operator bool() const
{
  return window_.isOpen();
}

void Game::operator ()()
{
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window_.close();
      return;
    }
    if (event.type == sf::Event::KeyPressed) {
      switch (event.key.code) {
        case sf::Keyboard::Enter:
          break;
        case sf::Keyboard::W:
        case sf::Keyboard::Up:
          if (mainMenu_.currentButton_ != mainMenu_.begin()) {
            mainMenu_.currentButton_->setFillColor({0, 0, 0, 255});
            --(mainMenu_.currentButton_);
            mainMenu_.currentButton_->setFillColor({102, 195, 142, 255});
          }
          break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
          if (mainMenu_.currentButton_ != --(mainMenu_.end())) {
            mainMenu_.currentButton_->setFillColor({0, 0, 0, 255});
            ++(mainMenu_.currentButton_);
            mainMenu_.currentButton_->setFillColor({102, 195, 142, 255});
          }
          break;
        case sf::Keyboard::Escape:
          window_.close();
          return;
        default:
          break;
      }
    }
  }
  drawMainMenu();
}

void Game::drawMainMenu()
{
  window_.clear({250, 250, 250, 255});
  for (size_t i = 0; i < mainMenu_.size(); ++i) {
    window_.draw(mainMenu_[i]);
  }
  window_.display();
}
