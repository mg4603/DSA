## Pairs of Bears

In order to prove it's success and gain funding, the wilderness zoo needs to  
prove to environmentalists that it has x number of mating pairs of bears.

### Task:

You must check within a string to find all of the mating pairs, returning a 
array of the string containing valid mating pairs and a boolean indicating  
whether the total number of bears is greater than or equal to x.  

### Rules for a 'valid' mating pair:

1. Bears are either 'B'(male) or '8'(female).
2. Bears must be together in male/female pairs 'B8' or '8B'.
3. Mating pairs must involve two distinct bears each ('B8B' doesn't count as two  
pairs.)

Return an array containing a string of the valid mating pairs available, and a  
boolean indicating whether the total number of bears is greater than or equal  
to x.

### Example
    (6, 'EvHB8KN8ik8BiyxfeyKBmiCMj') ---> ['B88B', false];
    in this example, the number of bears(=4) is lesser than the given value of  
    x(=6)