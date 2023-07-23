# How to write and analyze algorithms

## Writing algorithms
1. abstract away from program specific syntax like declaration
2. smallest possible, that is well defined and doesn't cause ambiguity
3. no fixed syntax -> the primary goal is understandability

## Analysis
1. The primary goal of algorithm design is to create space and time efficient  
    functions.
2. Analysis of algorithms is done using platform and hardware independent  
    functions, rather than absolute values.
3. Criteria for analysis:
    1. Space (generally most important)
    2. Time (generally most important)
    3. Data transfer (requirement for bandwidth)
    4. Power consumption
    5. CPU registers required (while designing drivers)

### Time:
1. Every simple statement in an algorithm is considered to take 1 unit of time  
    regardless of complexity of statement

### Space:
1. number of variables + size of collections created in algorithm