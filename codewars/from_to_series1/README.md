## From..To..Series #1: from m to n. From the maximum range

### Task
Given an array of strings of the form "from m to n" return an array of the  
strings with the largest range.

### Note:
* $m,n \in \Z$
* m can be greater than, less than or equal to n.  

### Examples:
    findMaxRange(["from 1 to 3","from 2 to 4","from 1 to 1"])
    should return:
    ["from 1 to 3","from 2 to 4"]

    findMaxRange(["from 1 to 10","from 10 to 1","from -1 to -10"])
    should return:
    ["from 1 to 10","from 10 to 1","from -1 to -10"]

    findMaxRange(["from 1 to 10","from 10.1 to 1","from -1 to -10"])
    should return:
    ["from 10.1 to 1"]

    findMaxRange([]) should return: []