## IEEE 754 floating point numbers

IEEE 754 is a standard for representing floating-point numbers.

Its use is currently ubiquitous in both software (programming languages  
implementations) and hardware (Floating Point Units (FPU) chips embedded in  
processors).

The 2 most widely used IEEE 754 formats are called the single precision (SP,  
encoded on 32 bits) and double precision (DP, encoded on 64 bits) formats.

IEEE 754 numbers are divided into 3 fields :

    a sign bit;
    an exponent encoded on 8 (SP) or 11 (DP) bits;
    a mantissa (also called significand) encoded on 23 (SP) or 52 (DP) bits.

Your task is to write a function that takes as input a floating point number,  
and returns the binary IEEE 754 encoding of this number as a string, with fields  
separated by spaces for readability. If your programming language supports both  
SP and DP, you will have 2 functions to write, one for each type.

## Example
* Single Precision

    input:
    15.875
    output:
    "0 10000010 11111100000000000000000"

* Double Precision

    input:
    15.875
    output:
    "0 10000000010 1111110000000000000000000000000000000000000000000000"
