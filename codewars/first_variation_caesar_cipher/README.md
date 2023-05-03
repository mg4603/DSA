## First Variation on Caesar Cipher
The action of a caesar cipher is to replace each plaintext letter (plaintext  
letters are from 'a' to 'z' or from 'A' to 'Z') with a different one a fixed  
number of places up or down the alphabet.  

This program performs a variation of the Caesar shift. The shift increases by  
1 per increasing position, i.e., if the shift is initially 1, the first char  
of the message to be encoded will be shifted by 1, the second character will  
be shifted by 2 and so on...  

### Encoding params and return value of function "movingShift"
**Params:**
* s:        string to be encoded
* shift:    integer giving initial shift value

The function "movingShift" *first* codes the entire string  and *then* returns  
returns an array of strings containing the encoded string in 5 parts (five   
parts, since, each part of the encoded message will be given to five different  
runners, to further reduce risk of interception.)

If possible the message will be equally divided by message length between the  
five runners. If this is not possible, parts 1 to 5 will have subsequently  
non-increasing lengths, such that parts 1 to 4 are at least as long as when  
evenly divided, but at most 1 longer. If the last part is the empty string the  
this empty string must be shown in the resulting array.

For example, if the coded message has a length of 17, the five parts will have  
lengths of $4, 4, 4, 4, 1$. The parts 1 - 4 are evenly split and the last  part  
of length 1 is shorter.  
If the length is 16, the parts will be of lengths $4, 4, 4, 4, 0$. Parts 1-4 are  
evenly split and the fifth runner will stay home since his part is the empty  
string. If the length is 11, equal parts would be of length 2.2, hence parts will  
be of length 3, 3, 3, 2, 0.  

You will also implement a *demovingShfit* function with two params:
### Decoding params and return value of demovingShift:
**Params:**
* s: an array of strings(possible resulting from movingShift, with 5 strings)
* init: an initial shift.
**Return Value:**
* res: string


### Example:

    u = "I should have known that you would have a perfect answer for me!!!"
    
    movingShift(u, 1) returns :
    
    v = ["J vltasl rlhr ", "zdfog odxr ypw", " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"]

    and demovingShift(v, 1) returns u.