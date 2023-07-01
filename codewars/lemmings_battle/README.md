## Lemmings Battle!


Every single lemming has a power measure that describes its ability to fight.  
When two single lemmings fight with each one, the lemming with more power  
survives and the other one dies. However, the power of the living lemming  
gets smaller after the fight, exactly in the value of the power of the lemming  
that died. If two lemmings have the same power when they fight, both of them  
die.

In the fight between the two races, there are a certain number of battlefields.  
Each race assigns one lemming for each battlefield, starting with the most  
powerful.  

The Deadly War is processed by having each race send its best soldiers as  
described to the battlefields, making a battle round. Then, all battles 
proceed at the same time, and some of the lemmings will emerge victorious  
(but with less power) and some of them will die. The surviving ones will  
return to their race’s army and then a new round will begin, with each race  
sending again its best remaining soldiers to the battlefields. If at some point  
a race does not have enough soldiers to fill all battlefields, then only the  
ones with soldiers from both races will have a fight.

The Deadly War ends when one of the races has no more lemmings or when both  
of them disappear at the same time.

### Task
Given the number of battlefields and the armies of both races, your task is to  
discover which race will win the Deadly War and show the power of the surviving  
soldiers.


### Input

You are given B, SG and SB, representing respectively the number of battlefields  
available, a vector of integers size n of lemmings in the green army and a vector  
of integers size n of lemmings in the blue army (1 ≤ B, SG, SB ≤ 100000).

The lemmings in each army do not need to come in any particular order.
Output

For each test case you should return :

• "Green and Blue died" if both races died in the same round

• "Green wins : Each surviving soldier in descending order" if the green army  
won the Deadly War

• "Blue wins : Each surviving soldier in descending order" if the blue army won  
the Deadly War

### Example

    lemmings_battle(5, {10}, {10}) == "Green and Blue died"
    lemmings_battle(2, {20,10}, {10,10,15}) == "Blue wins: 5"
    lemmings_battle(3, {50,40,30,40,50}, {50,30,30,20,60}) == "Green wins: 10 10"
