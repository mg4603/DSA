## Array combinations

In this Kata, you will be given an array of arrays and your task will be to  
return the number of unique arrays that can be formed by picking exactly one  
element from each sub-array.

### Example:

    solve([[1,2],[4],[5,6]]) = 4,

Because, it results in only 4 possibilities. The are $[1,4,5],[1,4,6],[2,4,5],[2,4,6]$.

Make sure that you don't count duplicates;for example: 

    solve([[1,2],[4,4],[5,6,6]]) = 4, since the extra outcomes are just  
    duplicates. 

