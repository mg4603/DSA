# Asymptotic notation

## Big-oh notation ($O$)
1. Upper bound  
2. $f(n) = O(g(n))$,  
    iff $\exists +ve$ constants $c$ & $n_0$ $\ni$ $f(n) \leq c \cdot g(n)$  
    $\forall$  $n\geq n_0$

## Big-omega notation ($\Omega$ )
1. Lower bound  
2. $f(n) = \Omega(g(n)),$  
    iff $\exists +ve$ constants $c$ & $n_0$ $\ni$ $f(n) \geq c\cdot g(n)$  
    $\forall$  $n\geq n_0$

## Theta notation ($\Theta$)
1. Average bound  
2. $f(n) = \Theta(g(n))$,  
    iff $\exists +ve$ constants $c_1, c_2 $ & $n_0$ $\ni$ $c_1\cdot g(n)  
    \leq f(n) \leq c_2 \cdot g(n)$  
    $\forall$  $n\geq n_0$

## Properties:
1. If $f(n) = O(g(n))$ then $a\times f(n) = O(g(n))$
2. **Reflexive Property**:
    1. Given $f(n)$, $f(n) = O(f(n))$. (every function is an upper bound of  
    itself)
    2. Given $f(n)$, $f(n) = \Omega(f(n))$ (every function is a lower bound of  
    itself)
3. **Transitive Property**:  
    &emsp;If $f(n) = O(g(n))$ & $g(n) = O(h(n))$, then $f(n) = O(h(n))$
4. **Symmetric Property**: (only true for $\Theta$ notation)  
    &emsp;If $f(n) = \Theta(g(n))$, then $g(n) = \Theta(f(n))$
5. **Transpose symmetric property**: 
    &emsp;If $f(n) = O(g(n))$, then $g(n) = \Omega(f(n))$
6. If $f(n) = \Omega(g(n))$ & $f(n) = O(g(n))$, then $f(n) = \Theta(g(n))$
7. If $f(n) = O(g(n))$ and $d(n) = O(e(n))$,  
    &emsp;$f(n) + d(n) = O(g(n) + d(n))$
8. If $f(n) = O(g(n))$ and $d(n) = O(e(n))$,  
    &emsp;$f(n) \cdot d(n) = O(g(n) \cdot d(n))$