## PI approximation

    PI / 4 = 1 - 1/3 + 1/5 - 1/7 + ... 

To have a measure of the difficulty we will count how many iterations are   
needed to calculate PI with a given precision of epsilon.

There are several ways to determine the precision of the calculus but to keep  
things easy we will calculate PI within epsilon of your language Math::PI  
constant.

In other words, given as input a precision of epsilon we will stop the iterative  
process when the absolute value of the difference between our calculation using  
the Leibniz series and the Math::PI constant of your language is less than epsilon.

### Your function returns a string with
* your number of iterations
* your approximation of PI with 10 decimals

### Example :

    Given epsilon = 0.001 your function gets an approximation of 3.140592653839794 for PI at the end of 1000 iterations : since you are within epsilon of Math::PI you return

    iter_pi(0.001) --> [1000, 3.1405926538]

### Notes :

Unfortunately, this series converges too slowly to be useful, as it takes over 300 terms to obtain a 2 decimal place precision. To obtain 100 decimal places of PI, it was calculated that one would need to use at least 10^50 terms of this expansion!