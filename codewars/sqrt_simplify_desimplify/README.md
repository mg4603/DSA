## Square Roots: Simplify/Desimplify 

### Task:
Create two functions:
* simplify(integer): return a string like "x sqrt y" or "sqrt y" if the integer  
can't be simplified.
* desimplify(string): return an integer.


### Examples:
    simplify(1)  #=> "1"
    simplify(2)  #=> "sqrt 2"
    simplify(3)  #=> "sqrt 3"
    simplify(8)  #=> "2 sqrt 2"
    simplify(15) #=> "sqrt 15"
    simplify(16) #=> "4"
    simplify(18) #=> "3 sqrt 2"
    simplify(20) #=> "2 sqrt 5"
    simplify(24) #=> "2 sqrt 6"
    simplify(32) #=> "4 sqrt 2"
    
    desimplify("1")        #=> 1
    desimplify("sqrt 2")   #=> 2
    desimplify("sqrt 3")   #=> 3
    desimplify("2 sqrt 2") #=> 8
    desimplify("sqrt 15")  #=> 15
    desimplify("4")        #=> 16
    desimplify("3 sqrt 2") #=> 18
    desimplify("2 sqrt 5") #=> 20
    desimplify("2 sqrt 6") #=> 24
    desimplify("4 sqrt 2") #=> 32
    