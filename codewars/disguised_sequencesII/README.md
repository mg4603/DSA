## Disguised sequences (II)

$$v(n, p) = \sum_{k=0}^{n}(-1)^k \times p \times 4^{n-k} \times \binom{2n-k}{k}$$
$$u(n, p) = \sum_{k=0}^{n}(-1)^k \times p \times 4^{n-k} \times \binom{2-k+1}{k}$$

### Task:
1. Calculate v(n, p) and u(n, p) with two brute-force functions v1(n, p) and u1(n, p)
2. Try v1(n, p) and u1(n, p) for small values of n and p and look for patterns
3. create efficient functions for v(n, p) and u(n, p) that work for bigger n and p.  

### Examples:
v1(12, 70) --> 1750
u1(13, 18) --> 252