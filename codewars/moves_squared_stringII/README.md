## Moves in squared strings (II)

You are given a string of n lines, each substring begin n characters long:
For example:

    s = "abcd\nefgh\nijkl\nmnop"

We will study some transformation of this square of strings.
* Clock rotation 180 degrees: rot

        rot(s) => "ponm\nlkji\nhgfe\ndcba"

* selfie_and_rot(s). It is the initial string  + string obtained by clock  
rotation 180 degrees with dots interspersed in order to better show the  
rotation when printed

        s = "abcd\nefgh\nijkl\nmnop" --> 
        "abcd....\nefgh....\nijkl....\nmnop....\n....ponm\n....lkji\n....hgfe\n....dcba"

### Task:
* Write these two functions rot and selfie_and_rot
* high-order function oper(fct, s):
    * fct is the function of one variable f to apply to the string s

### Examples:
    s = "abcd\nefgh\nijkl\nmnop"
    oper(rot, s) => "ponm\nlkji\nhgfe\ndcba"
    oper(selfie_and_rot, s) => "abcd....\nefgh....\nijkl....\nmnop....\n....ponm\n....lkji\n....hgfe\n....dcba"

