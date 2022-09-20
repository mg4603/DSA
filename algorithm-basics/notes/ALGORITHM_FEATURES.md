# Algorithm Features
### Correctness
Algorithms must accomplish what they are designed to. As an exception to this
some algorithms like Fermat's primality test are correct only some of the time
and need to be run multiple times to increase confidence that the algorithm is
working.

### Maintainability
- It can be dangerous to use non-maintainable code in a program. 
- Convoluted, intricate and confusing algorithms can be notoriously difficult to 
implement and then to debug in the case of an error.

### Efficiency
- Efficiency in-terms of memory and time are important.
- Questions to ask:
    - What is the worst case performance
    - how likely is it that the worst case will occur
    - what is the average case performance on a large set of random data

## Big O Notation
- asymptotic notation
- relation between problem size and worst case performance as size grows very large
- Rules:
    1. If an algorithm performs a certain sequence of steps f(N) times for a mathematical
    function f, it takes O(f(N)) steps
    2. If an algorithm performs an operation that takes f(N) steps and then performs a 
    second operation that takes g(N) steps for function f and g, the algorithm's total
    performance is O(f(N)+g(N)).
    3. If an algorithm has a performance of O(f(N)+g(N)) and the function f(N) is larger 
    than g(N) for large N, the algorithm's performance can be simplified to (f(N))
    4. If an algorithm performs an operation that takes f(N) steps, and for every step
    in that operation it performs another g(N) steps the algorithm's total performance
    is O(f(N)xg(N))
    5. Ignore constant multiples. If C is a constant, O(Cxf(N)) is the same as O(f(N))
    and O(f(CxN)) is the same as O(f(N))
