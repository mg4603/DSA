# Sum of Sub-array RAnges

You are given an integer array nums. The range of a sub-array of nums is the  
difference between the largest and smallest element in the sub-array.

Return the sum of all sub-array ranges of nums.

A sub-array is a contiguous non-empty sequence of elements within an array.

 

## Example 1:

    Input: nums = [1,2,3]
    Output: 4
    Explanation: 
        The 6 subarrays of nums are the following:
        [1], range = largest - smallest = 1 - 1 = 0 
        [2], range = 2 - 2 = 0
        [3], range = 3 - 3 = 0
        [1,2], range = 2 - 1 = 1
        [2,3], range = 3 - 2 = 1
        [1,2,3], range = 3 - 1 = 2
        So the sum of all ranges is 
            0 + 0 + 0 + 1 + 1 + 2 = 4.

## Example 2:

    Input: nums = [1,3,3]
    Output: 4
    Explanation: 
        The 6 subarrays of nums are the following:
        [1], range = largest - smallest = 1 - 1 = 0
        [3], range = 3 - 3 = 0
        [3], range = 3 - 3 = 0
        [1,3], range = 3 - 1 = 2
        [3,3], range = 3 - 3 = 0
        [1,3,3], range = 3 - 1 = 2
        So the sum of all ranges is 
            0 + 0 + 0 + 2 + 0 + 2 = 4.

## Example 3:

    Input: nums = [4,-2,-3,4,1]
    Output: 59
    Explanation: 
        The sum of all subarray ranges of nums is 59.

 

## Constraints:

* $1 \le nums.length \le 1000$
* $-10^9 \le nums[i] \le 10^9$

 