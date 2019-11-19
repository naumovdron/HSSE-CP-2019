#ifndef FIELDS_HPP
#define FIELDS_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Fields {
public:
  std::vector<size_t> fields_;
  size_t empty_;
  Fields();
  operator bool() const;
  bool moveUp();
  bool moveDown();
  bool moveLeft();
  bool moveRight();
};

#endif //!FIELDS_HPP
