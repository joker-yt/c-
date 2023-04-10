#pragma once
#include <memory>
#include "HotDrink.h"
#include "HotDrinkFactory.h"

struct HotDrink;

struct TeaFactory : HotDrinkFactory
{
  unique_ptr<HotDrink> make() const override
  {
    return make_unique<Tea>();
  }
};
