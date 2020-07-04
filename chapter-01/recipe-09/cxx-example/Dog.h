#pragma once

#include "Animal.h"

class Dog final : public Animal {
public:
  Dog(const std::string &n) : Animal(n) {}

private:
  std::string name_impl() const override;
};
