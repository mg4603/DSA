# Can Sum

Given an integer targetSum and a vector of non-negative integers numbers,  
check if targetSum can be obtained from the numbers in the vector, with  
replacement.

## Recursive
```
    canSum(targetSum, [numbers]): -> bool
        if targetSum < 0: return false;
        if targetSum == 0: return true;

        for number in numbers:
            if canSum(targetSum - number, [numbers]): return true;
        return false; 
```

- Time Complexity:  
    $O(n^m)$,  
    where,  
        - n is the number of non-negative integers in vector  
        - m is targetSum
- Space Complexity:  
    $O(m)$

## Memoization

```
    canSum(targetSum, [numbers], memo): -> bool
        if targetSum < 0: return false;
        if targetSum == 0: return true;

        res := false;
        for number in numbers:
            res := res | canSum(targetSum - number, [numbers], memo)
            if(res)break;
        
        memo[targetSum] := res;
        return memo[targetSum]; 
```

- Time Complexity:  
    $O(n * m)$ 
- Space Complexity:  
    $O(m)$
