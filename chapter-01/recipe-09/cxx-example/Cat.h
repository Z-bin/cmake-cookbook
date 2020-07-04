#pragma once

#include "Animal.h"

class Cat final : public Animal {
public:
  Cat(const std::string &n) : Animal(n) {}

private:
  std::string name_impl() const override;
};
