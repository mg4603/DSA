# Numerical Algorithms
- Randomizing values
- Breaking numbers into prime factors
- Finding GCD
- Computing geometric areas


## Randomizing Data
Allows for:
    - simulation of random processes
    - test algorithms to see how they behave with random inputs
    - search for solutions to difficult problems

### Generating Random Values
- All computer generated random numbers are pseudo-random and can be predicted as long 
as details of the algorithm and it's internal state are known.
- For truly unpredictable randomness:
    - Radiation detector that detects particles coming out of a radioactive sample
    - Dice rolls
    - Analyzing static in radio waves
    - Studying brownian motion
    - Measuring atmospheric noise

#### Generating values
- Linear congruential generator (LCG):<br>
X<sub>n+1</sub> = (A x X<sub>n</sub> + B) Mod M,<br> where A, B and M are constants 
and X<sub>0</sub> is the seed(a value used to initialize the the pseudo-random number 
generator)<br>The sequence repeats after M numbers.<br>Note: Some pseudo-random number
generation algorithms use multiple linear congruential generator with different 
constants and select from one of the several values generated at each step.

