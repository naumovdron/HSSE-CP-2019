#include "game.hpp"
#include <exception>
#include <stdexcept>
#include <string>

Game::Game():
  window_(sf::VideoMode(410, 410), "Fifteen", sf::Style::None),//sf::Style::Close | sf::Style::Titlebar),
  currentHandle_(&Game::handleMainMenu),
  mainMenu_(Buttons(2))
{
  window_.setVerticalSyncEnabled(true);
  sf::Image icon;
  if (!icon.loadFromFile("../resources/icon.png")) {
    throw std::invalid_argument("Can't load font icon file");
  }
  window_.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
  if (!font_.loadFromFile("../resources/Alata-Regular.ttf")) {
    throw std::invalid_argument("Can't load font from file");
  }
  if (!stepMusic_.openFromFile("../resources/step.ogg")) {
    throw std::invalid_argument("Can't load music from file");
  }
  mainMenu_[0].setFont(font_);
  mainMenu_[0].setString("Play");
  mainMenu_[0].setFillColor({0, 0, 0, 255});
  mainMenu_[0].setPosition(20, 20);
  mainMenu_[0].setCharacterSize(30);
  mainMenu_[1].setFont(font_);
  mainMenu_[1].setString("Exit");
  mainMenu_[1].setFillColor({0, 0, 0, 255});
  mainMenu_[1].setPosition(20, 50);
  mainMenu_[1].setCharacterSize(30);
}

Game::operator bool() const
{
  return window_.isOpen();
}

void Game::operator ()()
{
  (this->*currentHandle_)();
}

void Game::handleMainMenu()
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
          if (mainMenu_.currentButton_ == mainMenu_.begin()) {
            this->currentHandle_ = &Game::handleFields;
          } else {
            window_.close();
            return;
          }
          break;
        case sf::Keyboard::W:
        case sf::Keyboard::Up:
          if (mainMenu_.currentButton_ != mainMenu_.begin()) {
            --mainMenu_.currentButton_;
          }
          break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
          if (mainMenu_.currentButton_ != --mainMenu_.end()) {
            ++mainMenu_.currentButton_;
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
  window_.clear({254, 254, 254, 255});
  for (size_t i = 0; i < mainMenu_.size(); ++i) {
    window_.draw(mainMenu_[i]);
  }
  sf::CircleShape position(4);
  position.setPosition(mainMenu_.currentButton_->getPosition().x / 2 - position.getRadius() / 2,
    mainMenu_.currentButton_->getPosition().y + mainMenu_.currentButton_->getCharacterSize() / 2 + position.getRadius() / 2);
  position.setFillColor({0, 0, 0, 255});
  window_.draw(position);
  window_.display();
}

void Game::handleFields()
{
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window_.close();
      return;
    }
    if (event.type == sf::Event::KeyPressed) {
      stepMusic_.stop();
      switch (event.key.code) {
        case sf::Keyboard::W:
        case sf::Keyboard::Up:
          if (fields_.moveDown()) {
            stepMusic_.play();
          }
          break;
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
          if (fields_.moveUp()) {
            stepMusic_.play();
          }
          break;
        case sf::Keyboard::A:
        case sf::Keyboard::Left:
          if (fields_.moveRight()) {
            stepMusic_.play();
          }
          break;
        case sf::Keyboard::D:
        case sf::Keyboard::Right:
          if (fields_.moveLeft()) {
            stepMusic_.play();
          }
          break;
        case sf::Keyboard::Escape:
          this->currentHandle_ = &Game::handleMainMenu;
          return;
        default:
          break;
      }
    }
    if (fields_) {
      this->currentHandle_ = &Game::handleWin;
      return;
    }
  }
  drawFields();
}

void Game::drawFields()
{
  window_.clear({254, 254, 254, 255});
  sf::RectangleShape box({98, 98});
  box.setFillColor({0, 0, 0, 255});
  sf::CircleShape circle(45);
  circle.setFillColor({254, 254, 254, 255});
  sf::Text number;
  number.setFont(font_);
  number.setCharacterSize(45);
  number.setFillColor({0, 0, 0, 255});
  for (size_t y = 0; y < 4; ++y) {
    for (size_t x = 0; x < 4; ++x) {
      if (y * 4 + x != fields_.empty_) {
        box.setPosition(6 + 100 * x, 6 + 100 * y);
        circle.setPosition(10 + 100 * x, 10 + 100 * y);
        number.setPosition(35 + 100 * x, 35 + 100 * y);
        number.setString(std::to_string(fields_.fields_[y * 4 + x]));
        window_.draw(box);
        window_.draw(circle);
        window_.draw(number);
      }
    }
  }
  window_.display();
}

void Game::handleWin()
{
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window_.close();
      return;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
      this->currentHandle_ = &Game::handleMainMenu;
      return;
    }
  }
  drawWin();
}

void Game::drawWin()
{
  window_.clear({254, 254, 254, 255});
  sf::Text text = sf::Text("YOU WIN", font_, 50);
  text.setPosition(100, 180);
  text.setFillColor({0, 0, 0, 255});
  window_.draw(text);
  window_.display();
}
