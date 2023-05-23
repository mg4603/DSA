## Some Egyptian fractions

Given a rational number n  

$n \ge 0$, with denominator strictly positive  as two strings  

decompose this number as a sum of rational with numerators equal to one and  
without repetitions   

$$\frac{2}{3} = \frac{1}{2} + \frac{1}{6}$$

is correct, but not
$$\frac{2}{3} = \frac{1}{3} + \frac{1}{3}$$
as $\frac{1}{3}$ is repeated

The algorithm must be "greedy", so at each stage the new rational obtained in  
the decomposition must have a denominator as small as possible. In this manner  
the sum of a few fractions in the decomposition gives a rather good approximation  
of the rational to decompose.  

$$\frac{2}{3} = \frac{1}{3} + \frac{1}{3}$$

doesn't fit because of the repetition but also because the first $\frac{1}{3}$  
has a denominator bigger than the one in $\frac{1}{2}$ in the decomposition

$$\frac{2}{3} = \frac{1}{2} + \frac{1}{6}$$

### Example
    decompose("21", "23") => "[1/2, 1/3, 1/13, 1/359, 1/644046]"

### Notes:

1. The decomposition of $\frac{21}{23}$ as
$$\frac{21}{23} = \frac{1}{2} + \frac{1}{3} + \frac{1}{13} + \frac{1}{598} + \frac{1}{897}$$
is exact but doesn't fulfill our requirement because 598 is bigger than 359. Same  
for 
$$\frac{21}{23} = \frac{1}{2} + \frac{1}{3} + \frac{1}{23} + \frac{1}{46} + \frac{1}{69}$$ 
23 is bigger than 13
or 
$$\frac{21}{23} = \frac{1}{2} + \frac{1}{3} + \frac{1}{15} + \frac{1}{110} + \frac{1}{253} $$
15 is bigger than 13

2. The rational given to decompose could be greater than one or equal to one, in  
which case the first "fraction" will be an integer (with an implicit denominator  
of 1). 

3. If the numerator parses to zero the function "decompose" returns "[]"  

4. The number could also be a decimal which can be expressed as a rational.
