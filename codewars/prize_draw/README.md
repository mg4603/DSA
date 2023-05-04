## Prize Draw
To participate in a prize draw each one gives his/her name.  

Each letter of a first name has a value which is it's rank in the english  
alphabet. A and a have rank 1, B and b rank 2 and so on.

The length of the first name is added to the sum of these ranks hence a number  
`som`.  

An array of random weights is linked to the first names and each som is  
multiplied by its corresponding weight to get what they call a winning number.  

### Example:
    names: "COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH"
    weights: [1, 4, 4, 5, 2, 1]
    n: 4
    
    The function should return: "PauL"

### Notes:
* The weight array is at least as long as the number of names, it may be longer.
* If st is empty return "No participants".
* If n is greater than the number of participants then return "Not enough participants".
