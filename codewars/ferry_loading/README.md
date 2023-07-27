## Ferry Loading

### Task
There is a length-meter-long ferry that crosses the river. A car may arrive at  
either river bank to be transported by the ferry to the opposite bank. The  
ferry travels continuously back and forth between the banks so long as it is  
carrying a car or there is at least one car waiting at either bank. Whenever  
the ferry arrives at one of the banks, it unloads its cargo and loads up cars  
that are waiting to cross as long as they fit on its deck. The cars are loaded  
in the order of their arrival; ferry’s deck accommodates only one lane of cars.  
The ferry is initially on the left bank where it broke and it took quite some  
time to fix it. In the meantime, lines of cars formed on both banks that await  
to cross the river.

### Input

Each test case receives an integer length and a vector pairs of integers and  
strings loads. Each $loads_i$ has the length of a car (in centimeters), and the  
bank at which the car arrives (‘left’ or ‘right’).

### Output

Return the number of times the ferry has to cross the river in order to serve  
all waiting cars.

### Example
    ferryLoading(20, 
                {{380, "left"},{720, "left"},
                {1340, "right"},{1040, "left"}}) == 3;

    ferryLoading(15, {{380, "left"},{720, "left"},
                {1340, "left"},{1040, "left"}}) == 5;