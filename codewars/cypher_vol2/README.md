## GA-DE-RY-PO-LU-KI cypher vol 2

### Introduction
The GADERYPOLUKI is a simple substitution cipher used in scouting to encrypt  
messages. The encryption is based on short, easy to remember key. The key is  
written as paired letters.  

The most frequently used key is "GA-DE-RY-PO-LU-KI".  

    G => A
    g => a
    a => g
    A => G
    D => E
    etc.

The letters, which are not the list of substitutes, stays in the encrypted   
text without changes.  

### Task
Your task is to help scouts to encrypt and decrypt their messages. Write the  
Encode and Decode functions.  

### Input/ Output  
The function should have two parameters.  
The message input string consists of lowercase and uppercase characters and  
whitespace character.  
The key input string consists of only lowercase characters.  
The substitution has to be case-sensitive.  

### Example:
    Encode("ABCD", "agedyropulik");             // => GBCE 
    Encode("Ala has a cat", "gaderypoluki");    // => Gug hgs g cgt 
    Decode("Dkucr pu yhr ykbir","politykarenu") // => Dance on the table
    Decode("Hmdr nge brres","regulaminowy")  // => Hide our beers
