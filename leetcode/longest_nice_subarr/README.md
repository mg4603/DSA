# Longest Nice Sub-array

You are given an array nums consisting of positive integers.

We call a sub-array of nums nice if the bitwise AND of every pair of  
elements that are in different positions in the sub-array is equal to 0.

Return the length of the longest nice sub-array.

A sub-array is a contiguous part of an array.

Note that sub-arrays of length 1 are always considered nice.

 

## Example 1:

    Input: nums = [1,3,8,48,10]
    Output: 3
    Explanation: 
        The longest nice sub-array is [3,8,48]. This 
            sub-array satisfies the conditions:
        - 3 AND 8 = 0.
        - 3 AND 48 = 0.
        - 8 AND 48 = 0.
        It can be proven that no longer nice sub-array can
            be obtained, so we return 3.

## Example 2:

    Input: nums = [3,1,5,11,13]
    Output: 1
    Explanation: 
        The length of the longest nice sub-array is 1. 
            Any sub-array of length 1 can be chosen.

 

## Constraints:

* $1 \le nums.length \le 10^5$
* $1 \le nums[i] \le 10^9$

