## Braking well

Braking distance d1 is the distance a vehicle will go from the point when it  
brakes to when it come to a complete stop. It depends on the original speed v  
and on the coefficient of friction mu. between the tires and teh road surface.  

The braking distance is one of two principal components of the total stopping  
distance. The other component is the reaction distance, which is the product of  
the speed and the perception-reaction time of the driver.  

The kinetic energy E is $0.5 \times m \times v^2$, the work W given by braking is  
$mu \times m \times g \times d1$. Equalling E and W gives the braking distance:  

$$d1 = \frac{v \times v}{2 \times mu \times g}$$ 

where g is the gravity of Earth and m the vehicle's mass.  

We have v in $\frac{km}{h}$, g as $9.81\frac{m}{s^{2}}$ and in the following we  
suppose that the ration time is constant and equal to 1s. The coefficient mu is  
dimensionless.  

### Tasks:
* The first one is the calculate the total stopping distance in meters given v,  
mu (and the reaction time t = 1).

        dist(v, mu) => d = total stopping distance
* The second task is to calculate v in $\frac{km}{h}$ knowing d in meters and mu  
with supposition that the ration time is still $t=1$.
        
        speed(d, mu) => v such that dist(v, mu) = d

### Examples:

    dist(100, 0.7) -> 83.9598760937531
    
    speed(83.9598760937531, 0.7) -> 100.0

### Notes:
* Remember to convert the velocity from $\frac{km}{h}$ to $\frac{m}{s}$ or from  
$\frac{m}{s}$ to $\frac{km}{h}$ when necessary. 
* Don't forget the reaction time t: t = 1
* Don't truncate or round your results.