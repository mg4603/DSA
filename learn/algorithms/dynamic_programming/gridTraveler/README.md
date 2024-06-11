# Grid Traveler

Find number of ways to get from start(1, 1) to end(n, m) of a n x m grid,  
when you can only travel to the right or down.

## Recursive
```
    gridTraveler(n, m): [int]
        if n = 1 and m = 1: return 1
        if n = 0 or m = 0: return 0
        return gridTraveler(n - 1, m) + gridTraveler(n, m - 1)
```
- Time Complexity:  
    $O(2^{n + m})$
- Space Complexity:  
    $O(n + m)$

## Memoization
```
    gridTraveler(n, m, memo): [int]
        if n = 1 and m = 1: return 1
        if n = 0 or m = 0: return 0

        if (n, m) memo:return memo[n, m]
        memo[(n, m)] = memo[(m, n)] = gridTraveler(n - 1, m, memo) +
                                    gridTraveler(n, m - 1, memo)
        return memo[(n, m)]
```

- Time Complexity:  
    $O(n+m)$
- Space Complexity:  
    $O(n + m)$