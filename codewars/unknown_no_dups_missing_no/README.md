## Unknown amount of duplicates. One missing number.  

In this kata, we have an unsorted sequence of consecutive numbers from a to b,  
such that a < b always (remember a, is the minimum, and b the maximum value).

They were introduced an unknown amount of duplicates in this sequence and we  
know that there is an only missing value such that all the duplicate values and  
the missing value are between a and b, but never coincide with them.

Find the missing number with the duplicate numbers (duplicates should be output  
in a sorted array).

Let's see an example:

    find_dups_miss([10,9,8,9,6,1,2,4,3,2,5,5,3]) == [7,[2,3,5,9]]

