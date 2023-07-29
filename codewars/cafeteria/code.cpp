#include <assert.h>
#include <iostream>

#include <vector>
#include <string>

struct Milk {
  float fat;
  bool operator!=(const Milk other) const
  {
    if(this->fat == other.fat)
    {
        return false;
    }
    return true;
  }
  bool operator==(const Milk other) const
  {
    if(this->fat != other.fat)
    {
        return false;
    }
    return true;
  }
};

struct Sugar {
  std::string sort;
  bool operator!=(const Sugar other) const
  {
    if(this->sort == other.sort)
    {
        return false;
    }
    return true;
  }
  bool operator==(const Sugar other) const
  {
    if(this->sort != other.sort)
    {
        return false;
    }
    return true;
  }
};

struct Coffee {
  std::string sort;
  std::vector<Milk> milk;
  std::vector<Sugar> sugar;
  bool operator == (const Coffee other) const;
};

bool Coffee::operator==(const Coffee other) const
{
    if(this->sort != other.sort)
    {
        return false;
    }
    if(this->milk != other.milk)
    {
        return false;
    }
    if(this->sugar != other.sugar)
    {
        return false;
    }
    return true;
}

class CoffeeBuilder {
    Coffee coffee;
  public:
    CoffeeBuilder() {}
  
    CoffeeBuilder set_black_coffee() {
        this->coffee.sort = "Black";
        return *this;
    }

    CoffeeBuilder set_cubano_coffee() {
        this->coffee.sort = "Cubano";
        this->with_sugar("Brown");
        return *this;
    }
    CoffeeBuilder set_antoccino_coffee() {
        this->coffee.sort = "Americano";
        this->with_milk(0.5);
        return *this;
    }
  
    CoffeeBuilder with_milk(float fat) {
        Milk milk;
        milk.fat = fat;
        this->coffee.milk.push_back(milk);
        return *this;
    }
    CoffeeBuilder with_sugar(const std::string &sort) {
        Sugar sugar;
        sugar.sort = sort;
        this->coffee.sugar.push_back(sugar);
        return *this;
    }
  
    Coffee build() {
        return this->coffee;
    }
};




int main()
{
    {
      Coffee actual = CoffeeBuilder().set_black_coffee().with_sugar("Regular").with_milk(3.2).build();
      Coffee expected = {"Black", {{3.2}}, {{"Regular"}}};
      assert(actual == expected);
    }
    
    {
      Coffee actual = CoffeeBuilder().set_antoccino_coffee().build();
      Coffee expected = {"Americano", {{0.5}}, {}};
      assert(actual == expected);
    }
    
    {
      Coffee actual = CoffeeBuilder().set_cubano_coffee().build();
      Coffee expected = {"Cubano", {}, {{"Brown"}}};
      assert(actual == expected);
    }
    return 0;
}