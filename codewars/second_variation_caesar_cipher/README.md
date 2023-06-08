## Second Variation on Caesar Cipher
In this country soldier are poor but they need a certain level of secrecy for  
their communications so, tough they do not know Caesar cipher, they reinvent  
in the following way.  

The action of a Caesar cipher is to replace each plaintext letter (plaintext  
letters are from 'a' to 'z' or from 'A' to 'Z') with a different one a fixed  
number of places up or down the alphabet. This displacement of number of places  
is called the "shift" or the "rotate" of the message. For example, if the  
shift is 1 letter a become b and A becomes B; the shift is cyclic, so with a  
shift of 1, z becomes a and Z becomes A.  

They use ASCII, without really knowing it, but code only letters a-z and A-Z.  
Other characters are kept as such.  

They change the "rotate" each new message. This "rotate" is a prefix for their  
message once message is coded. The prefix is built of 2 letters, the second one  
being shifted from the first one by the "rotate". The first letter of the coded  
message is the first letter of the encode message in lower case. 

For example if the "rotate" is 2, if the first letter of the decoded message is  
'J' the prefix should be 'jl'.  

To lessen the risk they cut the coded message and the prefix in five pieces  
since they only have 5 runners and each runner has only one piece.  

If possible the message will be evenly split between the five runners; if not  
possible, parts 1, 2, 3, 4 will be longer and 5 will be shorter. The fifth part  
can have have length equal to the other ones or shorter. If there are many  
options on how to split, choose the option where the fifth part has the longest  
length, provided that the previous conditions are fulfilled. If the last part  
is an empty string don't put this empty string in the resulting array.  

For example, if the coded message has a length of 17 the five parts will have  
lengths of 4, 4, 4, 4, 1. The parts 1, 2, 3, 4 are evenly split and the last  
part of length 1 is shorter. If the length is 16 the parts will be of length  
4, 4, 4, 4, 0. Parts 1, 2, 3, 4 are evenly split and the fifth runner will stay  
at home since his part si the empty string and is not kept.  

### Example:
    message: "I should have know that you would have a perfect answer for me!!!"
    code:["ijJ tipvme ibw", "f lopxo uibu z", "pv xpvme ibwf ",  
    "b qfsgfdu botx", "fs gps nf!!!"]