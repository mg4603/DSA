## Surrounding Primes for a value

We need a function primeBefAft that give the largest prime below a certain given value n, befPrime and the smallest prime larger than this value, aftPrime.  

The result should be output in a list like the following:

    primeBefAft == {befPrime, aftPrime}

If n is a prime number it it will give two primes, n will not be included in the result.

### Examples:
    PrimeBefAft(100) --> {97, 101}
    
    PrimeBefAft(97) --> {89, 101}
    
    PrimeBefAft(101) --> {97, 103}

### Note:
* Range for random tests: $1000 \le n \le 200000$