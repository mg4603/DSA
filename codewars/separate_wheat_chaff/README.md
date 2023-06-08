## Separate The Wheat From The Chaff

### Scenario
With cereal crop like wheat or rice, before we can eat the grain kernel, we  
need to remove the inedible husk, or separate the wheat from the chaff.  

### Task
Given sequence of integers, separate the negative numbers (chaff) from the  
positive ones(wheat).  

### Notes:
* Sequence size is at least 3
* Return a new sequence, such that negative numbers come first, then positive  
numbers.
* There will be no zeros.  
* Repetition of numbers in the input sequence could occur, so duplications are  
included when separating.  
* If a misplaced positive number is found in the from part of the sequence,  
replace it with the last misplaced negative number (the one number found near  
the end of the input) and so on. Negative numbers found near the beginning of  
the sequence **should be kept in place**.

<hr>

### Examples:
    wheatFromChaff ({7, -8, 1 ,-2}) ==> return ({-2, -8, 1, 7}) 
### Explanation
* **Since** 7 **is a positive number**, it should not be located at the  
beginning so it need to be swapped with the **last negative number** -2.

<hr>

    wheatFromChaff ({-31, -5, 11 , -42, -22, -46, -4, -28 }) ==> return  
    ({-31, -5,- 28, -42, -22, -46 , -4, 11})

### Explanation
* Since, {-31, -5} **are negative numbers** found at the beginning of the  
sequence we keep them in place.
* Since 11 is a positive number, it is replaced by the last negative number  
which is -28, and so on till the separation is complete.

    wheatFromChaff ({-25, -48, -29, -25, 1, 49, -32, -19, -46, 1}) ==> return  
    ({-25, -48, -29, -25, -46, -19, -32, 49, 1, 1})

### Explanation:
* **Since** {-25, -48, -29, -25} are **negative numbers** found at the beginning  
of the sequence, we keep them in place.
* Since 1 is positive number, it is replaced by the last negative which is -46,  
and so on till the separation is complete.  
* Remember, duplication are included when separating, that's why the number 1  
appeared twice at the end of the output.