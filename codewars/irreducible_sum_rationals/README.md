## Irreducible Sum of Rationals

You have a list of rationals in the form  

    lst = [ [num1, denom1], ....[num_n, denom_n]]

which are all positive integers. You have to produce their sum N/ D in an  
irreducible form: this means that N and D have only 1 as a common divisor.  

### Return the result in the form:
* {N, D}

If the result is an integer (N % D == 0), return:  
* {n, 1}

If the input list is empty, return:
* {0, 1}