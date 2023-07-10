## String sub-pattern recognition II

### Task:
Create a function hasSubPattern that takes a string and return true if:
* a sub pattern exists(sub-pattern should be shorter than the string)
* the string can be created by shuffling string created using a sub pattern

### Example:
    hasSubpattern("a") == false; // no repeated shorter sub-pattern, just one  
                                 // character
    hasSubpattern("aaaa") == true; //just one character repeated
    hasSubpattern("abcd") == false; //no repetitions
    hasSubpattern("babababababababa") == true; //repeated "ba"
    hasSubpattern("bbabbaaabbaaaabb") == true; //same as above, just shuffled
