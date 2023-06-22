## String Pyramid 

### Task:
Create methods:

    std::string watchPyramidFromTheSide(std::string characters)

Shows the pyramid from the side

    std::string watchPyramidFromAbove(std::string characters)
Shows the pyramid from above

    int countVisibleCharactersOfThePyramid(std::string characters)
Returns the count of characters visible from outside

    int countAllCharactersOfThePyramid(std::string characters)
return count of all characters of pyramid.

* Each characters will be used for building one layer of the pyramid.
* The length of the given string be the height of the pyramid.
* Every layer will be built with stones from the given character.
* There is no limit of stones.  
* The pyramid should have perfect $45 deg$ angles.

### Example:
string: "abc"

From the side:

      c
     bbb
    aaaaa

From above:

    aaaaa
    abbba
    abcba
    abbba
    aaaaa

Count of visible stones:

    25

Count of all used stones:

    35

