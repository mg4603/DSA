## Moves in squared strings (III)

You are given a string of n lines, each substring being n characters long.
For example:

    s = "abcd\nefgh\nijkl\nmnop"

We will study some transformations of this square of strings.

* symmetry with respect to the main diagonal: diag_1_sym

        diag_1_sym(s) => "aeim\nbfjn\ncgko\ndhlp"

* clockwise rotation 90 degress: rot_90_clock:

        rot_90_clock(s) => "miea\nnjfb\nokgc\nplhd"

* selfie_and_diag1(s). It's intial string + string obtained by symmetry with  
respect to the main diagonal

    selfie_and_diag(s) => "abcd|aeim\nefgh|bfjn\nijkl|cgko\nmnop|dhlp"

### Task:
* Write these functions diag_1_sym, rot_90_clock, selfie_and_diag1
* high-order function oper(fct, s) where,
    * fct is the function of one variable f to apply to the string s (fct will  
    be one of diag_1_sym, rot_90_clock, selfie_and_diag1)

