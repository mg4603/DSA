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

### Rule 1
If an algorithm performs a certain sequence of steps f(N) times for a mathematical 
function f, it takes O(f(N)) steps
```
Integer: FindLargest(Integer: array[])
    Integer: largest = array[0]
    For i = 1 To <largest_index>
        If(array[i] > largest) largest = array[i]
    Next i
    Return largest
End FindLargest
```
The algorithm examines each of the N items in the array once, so it has O(N)
performance

### Rule 2
If an algorithm performs an operation that takes f(N) steps and then performs a
second operation that takes g(N) steps for function f and g, the algorithm's total
performance is O(f(N)+g(N)).
```
Integer: FindLargest(Integer: array[])
    Integer: largest = array[0]                             // O(1)
    For i = 1 to <largest_index>                            // O(N)
        If(array[i] > largest) largest = array[i]
    Next i
    Return largest                                          // O(1)
End FindLargest
```
There are two constant time operations:
- initializing the largest element
- returning the largest element
So the total performance of the loop: O(1 + N + 1) = O(2 + N)

### Rule 3
If an algorithm has a performance of O(f(N)+g(N)) and g(N) is smaller than f(N) for
large N, then the algorithm's performance can be simplified to O(f(N)).
In the preceding example the performance of the FindLargest fn was seen to be O(2+N),
which can be simplified to O(N) as the fn N is larger than the constant 2.
Ignoring the smaller fn allows for focus on the algorithm's asymptotic behavior
as the problem size become large.

### Rule 4
If an algorithm performs an operation that takes O(f(N)) steps and for every step in 
the operation, if it performs another O(g(N)) steps, the algorithm's total performance
is O(f(N)xg(N)).
```
Boolean: ContainsDuplicates(Integer: array[])
    For i = 0 to <largest_index>
        For j = 0 to <largest_index>
            If i != j
                If(array[i] == array[j]) Then Return True
            End If
        Next j
    Next i
    Return False
End ContainsDuplicates
```
The outer loop iterates over all N items in the array taking O(N) steps
and the inner loop runs N times for each iteration of the outer loop so it also
takes O(N) steps. Because one loop is nested inside another, the combined performance
is O(N X N) = O(N<sup>2</sup>)

### Rule 5
Ignore constant multiples. If C is a constant, O(C x f(N)) is the same as O(f(N)) and
O(f(C x N)) is the same as O(f(N))
In the previous ContainsDuplicates example, each iteration of the inner loop had 2 ops.
This means that O(N x 2 x N) ops occurred in total or performance is O(2 x N<sup>2</sup>).
According to rule 5, the 2 can be ignored to make the performance O(N<sup>2</sup>).

## Common Runtime Functions
### Constant time O(1)
Trivial fn that is independent of the input size.
```
Integer: DividingPoint(Integer: array[])
    Integer: number1 = array[0]
    Integer: number2 = array[<last index of array>]
    Integer: number3 = array[<last index of array>/2]
    If(<number1 is between number2 and number3>) Return number1
    If(<number2 is between number1 and number3>) Return number2
    Return number3
End DividingPoint
```
The algorithm picks the middle value between the values at the beginning, end and
middle of the array. Because of the fixed number of steps, it has O(1) performance
and its runtime is independent of number of inputs N.

### Log n
An algorithm with a O(logN) performance typically divides the number of items it must
consider by a fixed fraction at every step.
```
// Finding an item in balanced bst
Node: FindItem(Integer: target_value)
    Node: test_node = <root of tree>
    Do forever
        If(test_node == null) Return null
        
        If(target_value == test_node.Value) Then
            Return test_node
        If(target_value < test_node.Value) Then
            test_node = test_node.Left
        Else
            test_node = test_node.Right
        End If
    End Do
End FindItem
```
A balanced bst has roughly 2<sup>h</sup> nodes at the lowest level, where h is the 
height of the tree. The algorithm at most has to travel a single branch from root to
leaf which is h nodes long, to check if the balanced bst has the value it is looking
for. This is log(N), where N is the size of the problem
The logarithmic fn log(N) grows relatively slowly as N increases, so algorithms with 
O(logN) performance are generally fast enough to be useful.

### Sqrt N
- Grow slowly but faster than logN.
- Not very common.


### N
- Grows faster than logN and sqrtN but slowly enough to be useful.