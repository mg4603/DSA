## Fibo Akin  

Let u(n) be a sequence beginning with:

    u[1]  = 1,  u[2]  = 1,  u[3]  = 2,  u[4]  = 3,  u[5]  = 3,  u[6] = 4,

    u[7]  = 5,  u[8]  = 5,  u[9]  = 6,  u[10] = 6,  u[11] = 6,  u[12] = 8,
    
    u[13] = 8,  u[14] = 8,  u[15] = 10, u[16] = 9,  u[17] = 10, u[18] = 11,
    
    u[19] = 11, u[20] = 12, u[21] = 12, u[22] = 12, u[23] = 12 etc...


### Sequence
$$u[n] = u[u[n-1]] + u[u[n-2]]$$

### Task
* create function u(n)
* create function $lengthSupUK(n, k)$ which returns the number of terms of  
series $\ge k$, amongst the first n terms
* create function comp(n) that returns the number of terms, amongst the first n  
terms that are smaller than its predecessor