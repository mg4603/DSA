### Tic-Tac-Toe-like table Generator  

Do you have in mid the good old TicTacToe?  

Assuming that you get all the data in one array, you put a space around  
each value, | as a columns separator and multiple - as rows separator,  
with something like ["O", "X", " ", " ", "X", " ", "X", "O", " "], you  
should be returning this structure (inclusive of new lines):

     O | X |   
    -----------
       | X |   
    -----------
     X | O |   

Now, to spice up things a bit, we are going to expand our board well beyond  
a trivial 3x3 square and we will accept rectangles.  

### Example
Input:
    ["O", "X", " ", " ", "X", " ", "X", "O", " ", "O"],  
    width = 5

     O | X |   |   | X 
    -------------------
       | X | O |   | O 

