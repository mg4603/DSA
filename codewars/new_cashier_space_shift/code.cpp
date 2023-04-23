#include <assert.h>
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

std::string get_order(std::string cashier_order){
    std::vector<std::string> items{
        "burger",
        "fries",
        "chicken",
        "pizza",
        "sandwich",
        "onionrings",
        "milkshake",
        "coke"
    };
    std::string kitchen_order;
    for(auto x: items){
        auto it = cashier_order.find(x);
        while(it != std::string::npos){
            kitchen_order += toupper(x.at(0));
            kitchen_order += std::string(x.begin() + 1, x.end());
            kitchen_order += " ";
            it = cashier_order.find(x, it + x.size());
        }
    }

    kitchen_order.pop_back();
    return kitchen_order;
}

int main(){
    assert(get_order("milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza")
        == "Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke");
    
    assert(get_order("pizzachickenfriesburgercokemilkshakefriessandwich")
        == "Burger Fries Fries Chicken Pizza Sandwich Milkshake Coke");
}









