#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(int, char**)
{
  sf::RenderWindow window(sf::VideoMode(400, 400), "SFML window");
  sf::Texture texture;
  if (!texture.loadFromFile("../resources/cute_image.jpg")) {
    return EXIT_FAILURE;
  }
  sf::Sprite sprite(texture);

  sf::Font font;
  if (!font.loadFromFile("../resources/arial.ttf")) {
    return EXIT_FAILURE;
  }
  sf::Text text("Hello SFML", font, 50);

  sf::Music music;
  if (!music.openFromFile("../resources/nice_music.ogg")) {
    return EXIT_FAILURE;
  }

  music.play();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear();
    window.draw(sprite);
    window.draw(text);
    window.display();
  }
  return EXIT_SUCCESS;
}
