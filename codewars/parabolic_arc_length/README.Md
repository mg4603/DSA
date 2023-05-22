## Parabolic Arc Length

We want to approximate the length of a curve representing a function $y = f(x)$  
with  $a \le x \le b$. First, we split the interval $[a, b]$ into n sub-intervals  
with widths $h_1, h_2, ... , h_n$ by defining points $x_1, x_2 , ... , x_{n-1}$  
between a and b. This defines points $P_0, P_1, P_2, ... , P_n$ on the curve  
whose x-coordinates are $a, x_1, x_2 , ... , x_{n-1}, b$ and y-coordinates  
$f(a), f(x1), ..., f(xn-1), f(b)$. By connecting these points, we obtain a  
polygonal path approximating the curve.

Our task is to approximate the length of a parabolic arc representing the curve  
y = x * x with x in the interval [0, 1]. We will take a common step h between  
the points xi: $h_1, h_2, ... , h_n = h = 1/n$ and we will consider the points   
$P_0, P_1, P_2, ... , P_n$ on the curve. The coordinates of each $P_i$ are 
$(x_i, y_i = x_i * x_i)$.

The function len_curve (or similar in other languages) takes n as parameter  
(number of sub-intervals) and returns the length of the curve.

![graph](pic.png)

### Note:

When you "Attempt" tests are done with a tolerance of 1e-06 