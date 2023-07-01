## Add all (Bad desc on site - minimal cost connecting ropes problem)

### Task:
Create a function that given an array of n numbers, sums them into one number  
at the least cost.

### Example:
    addAll({1, 2, 3}) => 9
    1 + 2 = 3, cost 3
    3 + 3 = 6, cost 6
    Total cost = 9
----------------------
    addAll({1, 2, 3, 4}) => 19
    1 + 2 = 3, cost 3
    3 + 3 = 6, cost 6
    4 + 6 = 10, cost 10
    Total cost = 19

----------------------
    addAll({1, 2, 3, 4, 5}) => 33
    1 + 2 = 3, cost 3
    3 + 3 = 6, cost 6
    4 + 5 = 9, cost 9
    9 + 6 = 15, cost 15
    Total cost = 33
