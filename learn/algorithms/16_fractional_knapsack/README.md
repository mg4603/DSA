# Knapsack Problem

Given a knapsack of limited capacity, the goal is to select a subset of items  
that can fit in the knapsack, that has the maximum possible value.

## Types:
### Fractional knapsack
* You can choose the fractional part of items
* Maximize the total value while respecting the weight capacity
* optimal solution can be found using greedy method

        Algorithm(weights, value, capacity):
            1. find ratio of value to weight
            2. sort the ratios in descending order
            3. fill in the knapsack with items of highest value to weight ratio 
                till the knapsack is full
                
### 0-1 knapsack
* You can either include or exclude an item - can't choose a fraction of the item
* Find the subset that maximizes the value, while staying within the weight  
capacity of the knapsack
* optimal solution can be found using dynamic programming
       
## Uses
* resource allocation
* finance
* manufacturing