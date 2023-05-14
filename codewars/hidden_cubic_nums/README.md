## Hidden "Cubic" numbers
Non-negative integers, with at most 3 digits, such that the sum of the cubes of  
their digits is the number itself are called "cubic" numbers.  

    153 is such a "cubic" number : 1^3 + 5^3 + 3^3 = 153

Cubic numbers of at most 3 digits are easy to find, even by hand, so they are  
"hidden" in a string.

The task is to find the "cubic" numbers in the string, if any, get their sum 
and return a string:

    "number1 number2 ... sumOfCubicNumbers Lucky"

if "cubic" numbers number1, number2, ... were found.

The numbers in the output are to be in the order in which they are encountered  
in the input string.

If no cubic numbers are found return the string: 

    "Unlucky"

### Examples:

    - s = "aqdf&0#1xyz!22[153(777.777" 
        the groups of at most 3 digits are 0 and 1 (one digit), 22 (two digits),  
        153, 777, 777 (3 digits)
        
        Of these only 0, 1, 153 are cubic and their sum is 154
        Return: "0 1 153 154 Lucky"

    - s = "QK29a45[&erui9026315"
        the groups are 29, 45, 902, 631, 5. 

        None is of these are cubic.
        Return: "Unlucky"

### Notes

* In the string "001234" where 3 or more contiguous digits, "001" forms the  
first group and "234" forms the second. 

* When string of more than 3 contiguous digits exists, the string is split into  
groups of 3 from the left. The last grouping could have 3, 2 or 1 digits.

    e.g "24172410" becomes 3 groups: "241", "724" and "10"

    e.g "0785" becomes 2 groups: "078" and "5".
