## String sub pattern recognition I

In this kata you need to build a function to return true or false if a string  
can be seen as the repetition of a sub-pattern.  

### For example:
    
    hasSubpattern("a") == false; //no repeated pattern
    hasSubpattern("aaaa") == true; //created repeating "a"
    hasSubpattern("abcd") == false; //no repeated pattern
    hasSubpattern("abababab") == true; //created repeating "ab"
    hasSubpattern("ababababa") == false; //cannot be entirely reproduced  
    repeating a pattern

Strings will never empty and can be composed of any character (just consider  
upper- and lowercase letters as different entities) and can be pretty long.