## Play with two Strings

Your task is to Combine two Strings. 

### Input:
- two strings a & b

### Task:
- For every character in string a swap the casing of every occurrence of the  
same character in string b. Then do the same casing swap with the inputs reversed.  
Return a single string consisting of the changed version of a followed by the  
changed version of b.  

### Examples:

    Input: "abc" and "cde"      => Output: "abCCde" 
    Input: "ab" and "aba"       => Output: "aBABA"
    Input: "abab" and "bababa"  => Output: "ABABbababa"

- swap the case of characters in string b for every occurrence of that character  
in string a char 'a' occurs twice in string a, so we swap all 'a' in string b  
twice.  

        This means we start with "bababa" then "bAbAbA" => "bababa"  
- char 'b' occurs twice in string a and so string b moves as follows:  

        start with "bababa" then "BaBaBa" => "bababa"

- then, swap the case of characters in string a for every occurrence in string b
- char 'a' occurs 3 times in string b. So string a swaps cases as follows:

        start with "abab" then => "AbAb" => "abab" => "AbAb"
- char 'b' occurs 3 times in string b. So string a swaps as follow:

        start with "AbAb" then => "ABAB" => "AbAb" => "ABAB".
- merge new strings a and b

        return "ABABbababa"