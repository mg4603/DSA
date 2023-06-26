## Steps in k-primes

A k-prime is a natural number with k-prime factors(with multiplicity).  

A natural number is thus prime iff it is 1-prime.  

### Task
Create a function:
    kprimes_step(k, step, start, nd),

where:
* $k\in \Z$, $k > 0$: type of k-prime
* $step \in \Z, step \ge 0$: step to be found between two k-primes
* $start \in \Z, start \ge 0$: start of search(start inclusive)
* $nd \in \Z, nd \ge start$: end of search(nd inclusive)

That returns an array of pairs of k-primes spaced with a step of step between  
the limits start and nd(both inclusive). 
### Example:
    kprimes_step(2, 2, 0, 50) => {{4, 6}, {33, 35}}