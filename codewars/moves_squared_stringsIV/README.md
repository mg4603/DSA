## Moves in squared string (IV)
You are given a string of n lines, each substring being n characters long:  
For example:

    s = "abcd\nefgh\nijkl\nmnop"

### Transformations:
* Symmetry with respect to the main cross diagonal: *diag2Sym*

        diag2Sym(s) => "plhd\nokgc\nnjfb\nmiea"
* Counterclockwise rotation 90 degrees: rot90Counter

        rot90Counter(s)=> "dhlp\ncgko\nbfjn\naeim"

* selfieDiag2Counterclock: It is initial string + string obtained by symmetry  
with respect to the main cross diagonal + counterclockwise rotation 90 degrees.

        s = "abcd\nefgh\nijkl\nmnop" --> 
        "abcd|plhd|dhlp\nefgh|okgc|cgko\nijkl|njfb|bfjn\nmnop|miea|aeim"

or printed for the last:

    selfie_diag2_counterclock
    abcd|plhd|dhlp
    efgh|okgc|cgko
    ijkl|njfb|bfjn
    mnop|miea|aeim

### Task

* Write these functions diag2Sym, rot90Counter, selfieDiag2Counterclock
* high-order function oper(fct, s), where fct is:  
    * diag2Sym
    * rot90Counter
    * selfieDiag2Counterclock