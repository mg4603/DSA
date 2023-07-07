## Which x for that sum?

$U(n, x) = x + 2\cdot x^2 +3\cdot x^3+..+n\cdot x^n$

When $n \to \infty$ and $x \in D$, where D is the domain of convergence,  
$U(n,x)\to m$ depending on x.  

Usually given x, we try to find m. Here we will try to find x($x\in \R$  
$ x \in (0, 1)$), when m is given($m \in \R, m \in (0,\infty]$)

### Task:
Create function solve that takes m and returns x as $n\to \infty$.

### Examples:
    solve(2.0) returns 0.5 
    // since U(n, 0.5) goes to 2 when n goes to infinity.
    
    solve(8.0) returns 0.7034648345913732 
    // since U(n, 0.7034648345913732) goes to 8 when n goes to infinity.
