## Car Park Escape:

### Task
You task is to escape from the carpark using only the staircases provided to  
reach the exit. You may not jump over the edge of the levels and the exit is  
always on the far right of the ground floor.  

### Rules:
1. You are passed the carpark data as an argument into the function.  
2. Free car parking spaces are represented by 0
3. Staircases are represented by 1
4. Your parking place (start position) is represented by 2 which could be on  
any floor.
5. The exit is always the far right element of the ground floor.
6. You must use the staircases to go down a level.
7. You will never start on a staircase
8. The start level may be any level of the car park.
9. Each floor will have only one staircase apart from the ground floor which  
will not have any staircases.  

### Return
Return an array of the quickest rout out of the carpark  

    R1 = Move Right one parking space
    L1 = Move Left one parking space
    D1 = Move Down one level

### Example
    carpark = {{1, 0, 0, 0, 2},
           {0, 0, 0, 0, 0}} => {"L4", "D1", "R4"}

- You start in the most far right position on level 1
- You have to move Left 4 places to reach the staircase => "L4"
- You then go down one flight of stairs => "D1"
- To escape you have to move Right 4 places => "R4"
