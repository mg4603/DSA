# Greedy Method

* used to solve optimization problems

## General Algorithm
* Problem should be solved in stages
* where *a* contains the inputs of size n

        Greedy(a, n)
        {
            for i = 1 to n do
            {
                // select some feature based on some criterion and check if it  
                // is feasible
                
                // if feasible add to solution
                x = select(a);
                if Feasible(x) then
                {
                    solution = solution + x;
                }
            }
        }