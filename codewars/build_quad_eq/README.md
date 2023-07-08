## Build a quadratic equation

### Task:
Given a string in the form "(mx+n)(px+q)":
* return a string of the form $ax^2 + bx + c, a, b, c \in \Z$
* if a or b are 1, omit the 1 in the resultant string


### Examples:
    KataSolution.quadraticBuilder("(x+2)(x+3)");  //return "x^2+5x+6"
    KataSolution.quadraticBuilder("(x-2)(x+7)");  //return "x^2+5x-14"
    KataSolution.quadraticBuilder("(3y+2)(y+5)");  //return "3y^2+17y+10"
    KataSolution.quadraticBuilder("(-h-7)(4h+3)");  //return "-4h^2-31h-21"
