## Reducing by steps
Data: an array of integers, a function f of two variable and init value.  

    eg: a = [2, 4, 6, 8, 10, 20], f(x, y) = x + y; init = 0

Output: an array of integers, say r, such that

    r = [r[0] = f(int, a[0]), r[1] = f(r[0], a[1]), r2 = f(r[1], a[2])....]
    eg: r = [2, 6, 12, 20, 30, 50]

### Task:
Write the following functions of two variables:
* som:(x, y) => x + y
* mini:(x, y) => min(x, y)
* lcmu:(x, y) => lcm(abs(x), abs(y))
* gcdi: (x, y) => gcd(abs(x), abs(y))

* oper_array(fct, arr, init), where:
    * fct - som, mini, lcmu or gcdi
    * init is the initial value

### Examples:

    a = [18, 69, -90, -78, 65, 40]
    oper_array(gcd, a, a[0]) => [18, 3, 3, 3, 1, 1]
    oper_array(lcm, a, a[0]) => [18, 414, 2070, 26910, 26910, 107640]
    oper_array(sum, a, 0) => [18, 87, -3, -81, -16, 24]
    oper_array(min, a, a[0]) => [18, 18, -90, -90, -90, -90]
    oper_array(max, a, a[0]) => [18, 69, 69, 69, 69, 69]

