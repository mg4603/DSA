## Estimating Amounts of Subsets

Given a set of elements (integers or string characters, characters only in  
RISC-V), where any element occur more than once, return the number of subsets  
that do not contain a repeated element.  

### Example 1:

    set numbers = {1, 2, 3, 4}

    subsets = {{1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4},  
    {1,2,3}, {1,2,4}, {1,3,4}, {2,3,4}, {1,2,3,4}}

There are 15 subsets. As you can see, the empty set, {}, is not counted.  

### Example 2:

    set letters = {a, b, c, d, d}

    subsets = {{a}, {b}, {c}, {d}, {a,b}, {a,c}, {a,d}, {b,c}, {b,d}, {c,d},  
    {a,b,c}, {a,b,d}, {a,c,d}, {b,c,d}, {a,b,c,d}}

The are 15 subsets. Subsets with repeated elements are not considered.  

### Task:
The function est_subsets() will calculate the number of these subsets.  

It will receive the array as an argument and to its features will output the  
amount of subsets that do not contain a repeated element.  

    est_subsets([1, 2, 3, 4]) == 15
    est_subsets(['a', 'b', 'c', 'd', 'd']) == 15

### Features of random tests:
* Low performance tests: 40
    * length of the arrays are between 6 and 15

* High performance tests: 80
    * length of the arrays are between 15 and 63