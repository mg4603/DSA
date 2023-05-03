## All Star Code Challenge #15
Your family runs a shop and have just bought a Scrolling Text Machine to help  
get some more business.  

The scroller works by replacing the current text string with a similar text  
string, but with the first letter shifted to the end; this simulates movement.  

Your father is too busy with the business to worry about such details, so,  
naturally, he's making you come up with text strings.  

Create a function named rotate() that accepts a string argument and returns an  
array of strings with each letter from the input string being rotated to the  
end.

    rotate("Hello") => {"elloH", "lloHe", "loHel", "oHell", "Hello"}

### Note:
* The original string should be included in the output array.
* The order matters.
* Each element of the output array should be a rotated version of the previous  
element.
* The output should be of the same length as the input string.
* For a zero length string "", the function should return an empty array.