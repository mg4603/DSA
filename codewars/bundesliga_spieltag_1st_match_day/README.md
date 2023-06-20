## Bundesliga 1. Spieltag - First Match Day

In this kata you get an array with 9 strings, which contain the matches from  
the first match day. Every string has this format, where x and y are the number  
of goals for the teams, if the match has already been played:  

    x:y [Team 1] - [Team 2]
    
    Example:
    6:0 FC Bayern München - Werder Bremen
    -:- Eintracht Frankfurt - Schalke 04

The team, which has shot more goals than the other team, wins the match.  

### Task:
Return the league table as one string.
Each Line:
1. Position in the table with two char and a dot(" 1.", "12.") 
2. space
3. Name of the club padded right(spaces) up to 30 chars.
4. Number of matches played(one digit in this kata)
5. Two spaces
6. Number of matches won(one digit in this kata)
7. Two spaces
8. Number of draws(one digit in this kata)
9. Two spaces.
10. Number of matches lost(one digit in this kata)
11. Two spaces
12. Differences of goals (shot vs. gotten)
13. Two spaces
14. Count of points (3 points for match won and 1 point for tie.)

### Table sort criteria:
1. Points
2. Goal diff if points are same.
3. More number of goals if goal diff is same
4. Share same place but ordered by team name

### Example:

 1. FC Bayern München             1  1  0  0  6:0  3 
 2. Eintrach Frankfurt            0  0  0  0  0:0  0
 2. Schalke 04                    0  0  0  0  0:0  0
 4. Werder Bremen                 1  0  0  1  0:6  0