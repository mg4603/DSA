# Recurrence Relation

## Master theorem for decreasing functions:
### General form of a recurrence relation
$T(n) = aT(n-b) + f(n)$  
where,  
* $a > 0, b > 0$
* $f(n) = n^klog^Pn $

### if a < 1
$T(n) = O(f(n))$
### if a=1
$T(n) = O(n\cdot f(n))$
### if a > 1
$T(n) = O(a^{n/b} \cdot f(n))$

## Master theorem for dividing function
### General form of a recurrence relation
$T(n) = aT(n/b) + f(n)$  
where, 
* $a \ge 1, b > 1$
* $f(n) = n^klog^Pn $

### if $log^a_b > k$
$T(n) = O(n^{log_b^a})$

### If $log^a_b = k$
* If $p > -1$:  
    $T(n) = O(n^klog^{p+1}n)$
* If $p = -1$:  
    $T(n) = O(n^kloglogn)$
* If $p < -1$:  
    $T(n)=O(n^k)$

### If $log^a_b <k$:
* If $p \ge 0$:  
    $T(n) = O(n^klog^pn)$
* If $p < 0$:  
    $T(n) = O(n^k)$