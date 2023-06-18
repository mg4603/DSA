#include <assert.h>
#include <iostream>

#include <cmath>

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

class Engine : public IEngine
{
    public:
        bool getIsRunning()
        {
            return this->isRunning;
        }

        void Start()
        {
            this->isRunning = true;
        }
    
        void Stop()
        {
            this->isRunning = false;
        }
    
        void Consume(double liters)
        {
            
        }
};

class FuelTank : public IFuelTank
{
    public:
        FuelTank(double level)
        {
            if(level >= 60)
            {
                fillLevel = 60;
            }
            else if(level < 0)
            {
                fillLevel = 0;
            }
            else
            {
                fillLevel = level;
            }
            if(fillLevel < 5)
            {
                this->isOnReserve = true;
            }
            if(fillLevel == 60)
            {
                this->isComplete = true;
            }
        }

        void Consume(double liters)
        {
            this->fillLevel -= liters;
            if(this->fillLevel < 5)
            {
                this->isOnReserve = true;
            }
        }

        double getFillLevel()
        {
            return this->fillLevel;
        }

        void Refuel(double liters)
        {
            if(this->fillLevel + liters >= 60)
            {
                this->fillLevel = 60;
            }
            else if(liters < 0)
            {
                return;
            }
            else
            {
                this->fillLevel += liters;
            }

            if(this->fillLevel < 5)
            {
                this->isOnReserve = true;
            }

            if(this->fillLevel == 60)
            {
                this->isComplete = true;
            }
        }
    
};

class FuelTankDisplay : public IFuelTankDisplay
{
    public:
        double getFillLevel()
        {
            return round(this->fillLevel * 100) / 100.0;
        }

        void setFillLevel(double fillLevel)
        {
            this->fillLevel = fillLevel;
            if(this->fillLevel < 5)
            {
                this->isOnReserve = true;
            }
            if(this->fillLevel == 60)
            {
                this->isComplete = true;
            }
        }

        bool getIsOnReserve()
        {
            return this->isOnReserve;
        }
    
        bool getIsComplete()
        {
            return this->isComplete;
        }

};

class Car : public ICar
{
    private:
        Engine *engine;
        FuelTank *fuelTank;

    public:
        FuelTankDisplay *fuelTankDisplay;
        Car(double level = 20)
        {
            engine = new Engine();
            fuelTank = new FuelTank(level);
            fuelTankDisplay = new FuelTankDisplay();
            fuelTankDisplay->setFillLevel(fuelTank->getFillLevel());
        }

        bool getEngineIsRunning()
        {
            return engine->getIsRunning();
        }
        
        void EngineStart(){
            if(this->fuelTank->getFillLevel() == 0)
            {
                return;
            }
            engine->Start();
        }
        
        void EngineStop()
        {
            engine->Stop();
        }
        
        void Refuel(double liters)
        {
            this->fuelTank->Refuel(liters);
            this->fuelTankDisplay->setFillLevel(this->fuelTank->getFillLevel());
        }
        
        void RunningIdle()
        {
            if(!engine->getIsRunning())
            {
                return;
            }
            this->fuelTank->Consume(0.0003);
            if(this->fuelTank->getFillLevel() <= 0)
            {
                engine->Stop();
            }
            this->fuelTankDisplay->setFillLevel(this->fuelTank->getFillLevel());
        }
};

void testMotorStartAndStop()
{
    Car car;
    
    assert(car.getEngineIsRunning() == false);
    
    car.EngineStart();
    
    assert(car.getEngineIsRunning() == true);
    
    car.EngineStop();
    
    assert(car.getEngineIsRunning() == false);
}

void testFuelConsumptionOnIdle()
{
    Car car(1);
    
    car.EngineStart();
    
    for(int i = 0; i < 3000; i++)
    {
        car.RunningIdle();
    }
    
    assert(car.fuelTankDisplay->getFillLevel() == 0.10);
}

void testFuelTankDisplayIsComplete()
{
    Car car(60);
    
    assert(car.fuelTankDisplay->getIsComplete() == true);
}

void testFuelTankDisplayIsOnReserve()
{
    Car car(4);
    
    assert(car.fuelTankDisplay->getIsOnReserve() == true);
}

void testRefuel()
{
    Car car(5);
    
    car.Refuel(40);
    
    assert(car.fuelTankDisplay->getFillLevel() == 45);
}

int main()
{
    testFuelConsumptionOnIdle();
    testFuelTankDisplayIsComplete();
    testFuelTankDisplayIsOnReserve();
    testMotorStartAndStop();
    testRefuel();
}