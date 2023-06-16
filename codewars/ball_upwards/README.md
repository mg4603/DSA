## Ball Upwards

You throw a ball vertically upwards with an initial speed v(km/h). The height h  
of the ball at time t is given by $h=v\times t - 0.5\times g \times t^2$ where g  
is Earth's gravity ($g \sim 9.81 m/s^2$). A device is recording at every tenth  
of second the height of the ball. For example, with v = 15km/h the device gets  
something of the following form:  
(0, 0.0), (1, 0.367...), (2, 0.637...), (3, 0.808...), (4, 0.881..) ...  
Where teh first number is the time in tenth of second and the second number is  
the height in meter.  

### Task
Write a function max_ball with parameter v(km/h) that return time in tenth of  
second of the maximum height recorded by the device.  

### Examples  
    max_ball(15) should return 4
    
    max_ball(25) should return 7

