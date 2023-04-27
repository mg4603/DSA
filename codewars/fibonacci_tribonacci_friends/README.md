## Fibonacci, Tribonacci and friends
You have to build a Xbonacci function that takes a signature of X elements - and remember each next element is the sum of the last X elements - and returns the first n elements of the so seeded sequence.

    xbonacci {1,1,1,1} 10 = {1,1,1,1,4,7,13,25,49,94}
    xbonacci {0,0,0,0,1} 10 = {0,0,0,0,1,1,2,4,8,16}
    xbonacci {1,0,0,0,0,0,1} 10 = {1,0,0,0,0,0,1,2,3,6}
    xbonacci {1,1} produces the Fibonacci sequence
