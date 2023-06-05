## Simpson's Rule - Approximate Integration

An integral:  
$\int^b_af(x)dx$

can be approximated by the so-called Simpson's rule:

$$\frac{b-a}{3n}(f(a) + f(b) + 4 \sum_{i=1}^{n/2}f(a + (2i-1)h) + 2\sum_{i=1}^{n/2-1}f(a + 2ih))$$
<br>
<br>

Here,  
$$h=\frac{(b-a)}{n}$$
* n being an even integer
* $a \le b$

We want to try Simpson's rule with the function f:
$$f(x) = \frac{3}{2}sin(x)^3$$

The task is to write a function called simpson with parameter n which returns  
the value of the integral of f on the interval $[0, pi]$

### Notes:
* n will always be even
* Don't round or truncate results
