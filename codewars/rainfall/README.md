## Rainfall
data is a string with rainfall records of a few cities for months from January  
to December. The records of towns are separated by **"\n"**. The name of each  
town is followed by **":"**.

data and towns can be seen in "Your Test Cases:".

### Task:

* function: mean(town, strng) should return the average of rainfall for the city  
**town** and the data **strng**.
* function: variance(town, strng) should return the variance of rainfall for the  
city **town** and the data **strng**.

### Examples:

    mean("London", data), 51.19(9999999999996) 
    variance("London", data), 57.42(833333333374)

### Notes:

* if functions mean or variance have as parameter **town** a city which has no  
records return -1 or -1.0 
* Don't truncate or round: the tests will pass if:
$|your\_result - test\_result|  \le 1e^{-2} $
or  
$|\frac{(your\_result - test\_result)}{test\_result}| \le 1e^{-6}$