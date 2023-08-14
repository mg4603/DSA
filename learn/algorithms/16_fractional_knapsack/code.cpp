#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>

std::pair<double, std::vector<std::pair<int, int>>> fractional_knapsack(std::vector<std::pair<int, int>> value_weights, int capacity)
{
    std::sort(value_weights.begin(), value_weights.end(), [](auto &a, auto &b)
    {
        return static_cast<double>(a.first) / a.second > static_cast<double>(b.first) / b.second;
    });

    double total_value(0.0);
    std::vector<std::pair<int, int>> knapsack;

    for(auto value_weight: value_weights)
    {
        if(capacity == 0)
        {
            break;
        }
        int item_amt = std::min(value_weight.second, capacity);
        
        capacity -= item_amt;
        total_value += (static_cast<double>(value_weight.first)/ value_weight.second * item_amt);
        knapsack.push_back(std::make_pair(item_amt, value_weight.first));
    }

    return std::make_pair(total_value, knapsack);
}

int main()
{
    std::vector<std::pair<int, int>> value_weight{
        {10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}
    };
    std::pair<double, std::vector<std::pair<int, int>>> res = 
                            fractional_knapsack(value_weight, 15);

    std::cout << "total_value: " << res.first << std::endl;
    std::cout << "knapsack: \n";
    for(auto knapsack_item: res.second)
    {
        std::cout << "\tvalue: " << std::setw(3) <<  knapsack_item.second;
        std::cout << " amount: " << knapsack_item.first << std::endl;;
    }
    return 0;
}