#include "fields.hpp"

Fields::Fields()
{
  size_t number = std::rand() % 16;
  fields_.push_back(number);
  if (number == 0) {
    empty_ = 0;
  }
  for (size_t i = 1; i < 16; ++i) {
    for (size_t j = 0; j < i;) {
      if (number == fields_[j]) {
        number = std::rand() % 16;
        j = 0;
      } else {
        ++j;
      }
    }
    fields_.push_back(number);
    if (number == 0) {
      empty_ = i;
    }
  }
  //for ezy showing win
  /*fields_.push_back(1);
  fields_.push_back(2);
  fields_.push_back(3);
  fields_.push_back(4);
  fields_.push_back(5);
  fields_.push_back(6);
  fields_.push_back(7);
  fields_.push_back(8);
  fields_.push_back(9);
  fields_.push_back(10);
  fields_.push_back(11);
  fields_.push_back(12);
  fields_.push_back(13);
  fields_.push_back(14);
  fields_.push_back(0);
  empty_ = 14;
  fields_.push_back(15);*/
}

Fields::operator bool() const
{
  for (size_t i = 0; i < 15; ++i) {
    if (fields_[i] != i + 1) {
      return false;
    }
  }
  return true;
}

bool Fields::moveUp()
{
  if (empty_ <= 11) {
    fields_[empty_] = fields_[empty_ + 4];
    fields_[empty_ + 4] = 0;
    empty_ = empty_ + 4;
    return true;
  }
  return false;
}

bool Fields::moveDown()
{
  if (empty_ >= 4) {
    fields_[empty_] = fields_[empty_ - 4];
    fields_[empty_ - 4] = 0;
    empty_ = empty_ - 4;
    return true;
  }
  return false;
}

bool Fields::moveLeft()
{
  if (empty_ % 4 != 3) {
    fields_[empty_] = fields_[empty_ + 1];
    fields_[empty_ + 1] = 0;
    empty_ = empty_ + 1;
    return true;
  }
  return false;
}

bool Fields::moveRight()
{
  if (empty_ % 4 != 0) {
    fields_[empty_] = fields_[empty_ - 1];
    fields_[empty_ - 1] = 0;
    empty_ = empty_ - 1;
    return true;
  }
  return false;
}
