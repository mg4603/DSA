## up AND down

You are given a string s made up of substring s(1), s(2), ..., s(n) separated by  
whitespaces. Example: "after be arrived two My so"

### Task

Return a string t having the following property:

$length( t(O)) \le length (t(1)) \ge length (t(2)) \le length (t(3)) \ge length (t(4)) .... (P)$

where the t(i) are the substring of s; 

### Rule
* at each step from left to right, you can only move either already consecutive  
strings or strings that became consecutive after a previous move. 
* The number of moves should be minimum.

### Example:

$length("after") > length("be")$ => "be after arrived two My so"

$length("after") < length("arrived")$ => "be arrived after two My so"

$length("after") > length("two")$ => "be arrived two after My so"

$length("after") > length("My") 

length("My") = length("so")

*So:*

$length (s(0)) \le length (s(1)) \ge length (s(2)) \le length (s(3)) \ge length ((s4)) \le length (s(5))$

Hence given a string s of substrings s(i) the function arrange with the previous  
process should return a unique string t having the property (P).

It is kind of roller coaster or up and down. When you have property (P), to make  
the result more "up and down" visible t(0), t(2), ... will be lower cases and the  
others upper cases.

    arrange("after be arrived two My so") should return "be ARRIVED two AFTER my SO"

### Notes:

* The string "My after be arrived so two" has the property (P) but can't be  
obtained by the described process so it won't be accepted as a result. The  
property (P) doesn't give unicity by itself.
* Process: go from left to right, move only consecutive strings when needed.
* For the first fixed tests the needed number of moves to get property (P) is  
given as a comment so that you can know if your process follows the rule.
