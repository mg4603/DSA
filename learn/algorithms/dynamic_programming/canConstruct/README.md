# CanConstruct

Given a string targetString and an array of words wordBank, return true if  
targetString can be formed by concatenating strings in wordBank with  
replacement.

**Base Case:** Empty targetString

## Recursive 
```
    canConstruct(targetString, [wordBank]): -> bool
        if targetString is empty: return true

        for word in wordBank
            if word is prefix of targetString:
                suffix := targetString after removing word from the 
                        beginning

                if canConstruct(suffix, wordBank) == true:
                    return true;
        return false
```
- Time Complexity:  
    $O(n^m\times m)$  
    where,
    - n is the number of words in wordBank
    - m is the length of targetString
- In the worst case, where word is a single letter, m becomes the height of  
    tree.

- Space Complexity:    
    $O(m^2)$  
    - where size of call stack is m and suffix takes takes m space

## Memo:
```
    memoCanConstruct(targetString, [wordBank], memo): -> bool
        if targetString is empty: return true
        if targetString in memo: return memo[targetString]

        canConstruct := false

        for word in wordBank:
            if word is prefix of targetString:
                suffix := targetString after removing word from  
                        beginning
                
                canConstruct = memoCanConstruct(suffix,  
                                    [wordBank], memo)
                if canConstruct = true:
                    break
        memo[targetString] = canConstruct
        return canConstruct

```

- Time Complexity:  
    $O(n \times m^2)$  
    where,
    - n is the number of words in wordBank
    - m is the length of targetString
- In the worst case, where word is a single letter, m becomes the height of  
    tree.
- Getting suffix takes m time, and the program runs $n \times m$ times

- Space Complexity:    
    $O(m^3)$  
    - where size of call stack is m, suffix takes takes m space and memo  
        takes m space