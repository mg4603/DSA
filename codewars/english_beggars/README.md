## English Beggars
Given an array of values and an amount of beggars, you are supposed to return an array with the sum of what each beggar brings home, assuming they all take regular turns, from the first to the last.

### Example: 
    [1,2,3,4,5] for 2 beggars => [9,6]
*as the first one takes [1,3,5], the second collects [2,4]*

    [1,2,3,4,5] for 3 beggars => [5,7,3]
*as they will respectively take [1,4], [2,5] and [3]*

### Note:
1. Not all beggars have to take the same amount of "offers" (length of the array is not necessarily a multiple of n);
2. length can be even shorter than n, in which case the last beggars will of course take nothing (0).
3. Do not modify the input array.