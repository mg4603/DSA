## Constructing a car #1 - Engine and Fuel Tank  

You have to construct a car. Step by step. Kata by kata.   
First you have to implement the engine and the fuel tank.  

The default fuel level of a car is 20 liters.  
The maximum size of the tank is 60 liters.  
Of course every car's life begins with an engine not running.  

Every call of a method from the car correlates to 1 second.  

The fuel consumption in running idle is 0.0003 liter/ second.  
For convenience the start of the engine consumes nothing and we don't care, if  
the engine is warm or cold.  

The fuel tank is on reserve, if the level is under 5 liters. The fuel tank  
display shows the level as rounded for 2 decimal places.  
Internally an accuracy up to 10 decimal places should be more than enough.  
In difference to most real cars, the fuel tank display is always showing its  
information, also when the engine is not running.  

And consider the logical things about fuel and engine.  
In all tests only the whole car will be tested. Feel free to write your own  
tests for the other classes. 

    class ICar
    {
    public:
        
        virtual void EngineStart() = 0;
        
        virtual void EngineStop() = 0;
        
        virtual void Refuel(double liters) = 0;
        
        virtual void RunningIdle() = 0;
    
    protected:
        
        bool engineIsRunning = false;
    };
    
    class IEngine
    {
    public:
        
        virtual void Consume(double liters) = 0;
        
        virtual void Start() = 0;
        
        virtual void Stop() = 0;
        
    protected:
        
        bool isRunning = false;
    };
    
    class IFuelTank
    {
    public:
        
        virtual void Consume(double liters) = 0;
        
        virtual void Refuel(double liters) = 0;
        
    protected:
    
        double fillLevel = 0.0;
        
        bool isOnReserve = false;
        
        bool isComplete = false;
    };
    
    class IFuelTankDisplay
    {
    protected:
        
        double fillLevel = 0.0;
        
        bool isOnReserve = false;
        
        bool isComplete = false;
    };