## Binaries

Let us take a string composed of decimal digits: "1011213". We want to code  
this string as a sting of 0 and 1 and after that be able to decode it.

To code we decompose the given in its decimal digits (in the above example:  
1 0 1 1 1 2 1 3) and we will code each digit.  

### Coding process to code a number n expressed in base 10
For each digit d of n
1. Let k be the number of bits of d
2. write k-1 times the digit 0 followed by the digit 1
3. write digit d as a binary string, with the right bit being the least  
significant
4. Concatenate the result of step 2 and 3 to get the coding of d

At last concatenate all the results got for digits of n.


### Task:
* Given str a string of digits representing a decimal number the function  
code(str) should return the coding of st as explained above.
* Given a string str resulting from the previous coding, decode it to get  
the corresponding decimal string.

### Examples:
    code("77338855") --> "001111001111011101110001100000011000001101001101"
    code("77338")  --> "0011110011110111011100011000"
    code("0011121314") --> "1010111111011011011111001100"
    
    decode("001111001111011101110001100000011000001101001101") -> "77338855"
    decode("0011110011110111011100011000") -> "77338"
    decode("1010111111011011011111001100") -> "0011121314"
