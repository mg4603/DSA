## Coding with Squared Strings

A squared string has n lines, each substring being n characters long: 

    s = "abcd\nefgh\nijkl\nmnop" is a squared string of size 4.

We will use squared strings to code and decode texts. To make things easier we  
suppose that our original text doesn't include the character '\n'.

### Coding

Input:

* A text t of length l.
* Consider the smallest integer n such that n * n be greater or equal to l.
* Complete t with the char of ascii code 11 (we suppose that this char is not in  
our original text) until the length of t is n * n.
* From now on we can transform the new t in a squared string s of size n by  
inserting '\n' where needed.
* Apply a clockwise rotation of 90 degrees to s: that's it for the coding part.

### Decoding

Input:

* a squared string s resulting from the coding
* Apply a counter-clockwise rotation of 90 degrees to s
* Do some cleaning to have the original text t

### Example:

    t = "I.was.going.fishing.that.morning.at.ten.o'clock"

    code(t) -> "c.nhsoI\nltiahi.\noentinw\ncng.nga\nk..mg.s\n\voao.f.\n\v'trtig"

    decode(code(t)) == "I.was.going.fishing.that.morning.at.ten.o'clock"

(Dots indicate spaces since they are quite invisible).