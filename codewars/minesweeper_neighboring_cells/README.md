## Minesweeper: neighboring cells

We started implementing the minesweeper game, we already have a module for fill-  
ing a SIZExSIZE matrix that places the mines ('o'), empty cells  (' '), cells  
that are not revealed ('D') and cells that must be filled with a number that the  
represents the number of mines in the neighboring cells ('R'). For neighboring  
cells, we assume 8-connectivity.

Design a function compute_number_mines that takes as an input a matrix like the  
one mentioned above and replaces the cells that contain a character 'R' with the  
number of bombs (mines) in the neighboring cells.

For example, given the following 5x5 matrix:

    ---------------------               
    |   |   | o | o |   |           8-connectivity       
    |   | o |   | D |   |               \ | /   
    |   | D | R |   |   |               - R -
    |   |   | o | o |   |               / | \     
    |   |   |   |   | o |                
    ---------------------                

The cell that contains the character ‘R’ must be replaced by the character '3'.
