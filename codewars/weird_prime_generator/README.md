## Weird prime generator

    a(1) = 7
    ..
    a(n) = a(n-1) + gcd(n, a(n-1)) , n>=2 

    g(1) = 1
    g(2) = g(2) - g(1)
    g(3) = g(3) - g(2)
    ....
    g(n) = g(n) - g(n-1)


p: sequence g without the ones.


### Task:
Write functions
1. an(n) with param n: returns the first n terms of the series a(n)
2. gn(n) with param n: returns the first n terms of the series g(n)
3. countOnes(n) with param n: return the number of ones in the series gn(n)
4. p(n) with param n: return an array with the first n distinct primes in gn(n)
5. maxPn(n) with param n: return the largest prime in p(n)
6. anOver(n) with param n: return an array of a(i)/i for every i such that  
g(i) != 1
7. anOverAverage(n) with param n: returns and integer(the avg of anOver(n))
