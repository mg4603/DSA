## Remove a Specific Element of an Array  

You will be given an array of n unique non-zero integers, such that n > 4.  

For each sub array of size $(n-1)$, calculate the absolute value of quotient of  
product and sum of element($q = \frac{SubProduct}{SubSum}$). Select the sub  
array with lowest value of $|q|$.  

### Task:
Given an array arr, return the index of element to be removed, along with the  
element to be removed to obtain the sub-array with the smallest absolute value  
of q.  

### Example:

    arr = [1, 23, 2, -8, 5]


Sub Arrays | SubSum | SubProduct | \|q\|  
---------- |:--------:|:------------:|:-----
[23, 2, -8, 5]| 22 | -1840 |  83.636363  
[1, 2, -8, 5]|0|-80|No value
[1, 23, -8, 5]|21|-920|43.809524
[1, 23, 2, 5]|31|230|7.419355  <--- selected array
[1, 23, 2, -8]|18|368|20.444444


    select_subarray([1, 23, 2, -8, 5]) == [3, -8]

------------------------
    select_subarray([10, 20, -30, 100, 200]) == [[3, 100], [4, 200]]
