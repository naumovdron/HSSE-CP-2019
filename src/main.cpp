#include <exception>
#include <iostream>
#include <ctime>
#include "game.hpp"

int main(int, char**)
{
  try {
    std::srand(unsigned(std::time(0)));
    Game game;

    //main cycle
    while (game) {
      game();
    }
    return 0;
  } catch (const std::bad_alloc&) {
    return 2;
  } catch (const std::exception& exception) {
    std::cerr << exception.what();
    return 1;
  }
}
