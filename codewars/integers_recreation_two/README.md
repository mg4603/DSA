## Integers: Recreation Two 

We are still with squared integers.  

Given 4 integers a, b, c, d we form the sum of the squares of a and b and then  
the sum of squares of c and d. We multiply the two sums giving a number n and  
then we try to decompose n into a sum of squares of two numbers e and f  
($e,f \ge 0$) such that $n = e^2 + f^2$.  


We need to be able to represent e and f as the sum or differences of products  
of a, b, c, d taken pairwise without replacement, i.e.,

    abs(a*b + c*d)
    abs(a*b - c*d)
    abs(c*a + b*d)
    abs(c*a - b*d)

### Example:
    
    prod2sum(1, 2, 1, 3) should return [[1, 7], [5, 5]]
    
    prod2sum(2, 3, 4, 5) should return  [[2, 23], [7, 22]]
    
    because (2² + 3²) * (4² + 5²) = 533 = (7² + 22²) = (23² + 2²)
    
    prod2sum(1, 2, 2, 3) should return  [[1, 8], [4, 7]]
    
    prod2sum(1, 1, 3, 5) should return  [[2, 8]]