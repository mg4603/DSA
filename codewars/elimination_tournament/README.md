## Elimination tournament

In this kata you will be given an array representing ranks. You must eliminate  
contestants in a series of rounds comparing consecutive pairs of ranks and store  
all initial and intermediate results in an array.  

During one round, the lowest rank of a pair is eliminated while the highest  
proceeds to the next round. This goes on until only one contestant is left.  
If the number of contestants is odd, the last one of the current array become  
the first of the next round.  

At the end of the competition, return the results of all the rounds in the form  
of an array of arrays.  

### Example:
    input = [9, 5, 4, 7, 6, 3, 8, 2];
    
    output = [
    [9, 5, 4, 7, 6, 3, 8, 2],  // first round is initial input
    [9, 7, 6, 8],              // results of 9 vs 5, 4 vs 7, 6 vs 3, and 8 vs 2 
    [9, 8],                    // results of 9 vs 7 and 6 vs 8
    [9]                        // results of 9 vs 8
    ];

### Notes:
* Array length will always be $\ge 2 \& \le 100$
* Elements of the array will always be $\ge 1 \& \le 100$
* Input must not be altered.