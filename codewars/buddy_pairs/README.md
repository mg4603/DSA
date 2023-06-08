## Buddy pairs

You know what divisors of a number are. The divisors of a positive integer  
n are said to be proper when you consider only the divisor other than n itself.  
In the following description, divisors will mean proper divisors. For example  
for 100, they are: 1, 2, 4, 5, 10, 20, 25 and 50.  

Let s(n) be the sum of these proper divisors of n. Two positive integers are  
considered buddies if the sum of divisors of one is one more than the other.

i.e.,

    (n, m) are buddies if s(m) = n + 1 and s(n) = m + 1

For example 48 and 75 are one such pair:
* Divisors of 48: 1, 2, 3, 4, 6, 8, 12, 16, 24 ==> s(48) = 76 = 75 + 1
* Divisors of 75: 1, 3, 5, 15, 25 ==> s(75) = 49 = 48 + 1

### Task:
Given two positive integers start and limit, the function buddy(start, limit)  
should return the first pair (n, m) of buddy pairs such that n(positive integer)  
is between start and limit(inclusive); m can be greater than limit and has to be  
greater than n

### Example:

    buddy(10, 50) => "(48 75)"
    buddy(48, 50) => "(48 75)"