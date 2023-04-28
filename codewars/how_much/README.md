## How Much?
I always thought that my old friend John was rather richer than he looked,  
but I never knew exactly how much money he actually had. One day (as I was  
plying him with questions) he said:

* Imagine I have between m and n Zloty... (or did he say Quetzal? I can't remember!)
* If I were to buy 9 cars costing c each, I'd only have 1 Zloty (or was it Meticals?) left.
* And if I were to buy 7 boats at b each, I'd only have 2 Ringglets (or was it Zloty?) left.


**Could you tell me in each possible case:**
1. how much money f he could possibly have ?
2. the cost c of a car?
3. the cost b of a boat?

### Notes:
* Each answer should be given as ["M: f", "B: b", "C: c"] 
* "M" stands for money, "B" for boats, "C" for cars.
* m, n, f, b, c are positive integers, where 0 <= m <= n or m >= n >= 0.  
 m and n are inclusive.

### Example:
    howmuch(1, 100)      => [["M: 37", "B: 5", "C: 4"], ["M: 100", "B: 14", "C: 11"]]
    howmuch(1000, 1100)  => [["M: 1045", "B: 149", "C: 116"]]
    howmuch(10000, 9950) => [["M: 9991", "B: 1427", "C: 1110"]]
    howmuch(0, 200)      => [["M: 37", "B: 5", "C: 4"], ["M: 100", "B: 14", "C: 11"], ["M: 163", "B: 23", "C: 18"]]