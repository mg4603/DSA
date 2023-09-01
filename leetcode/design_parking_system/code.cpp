#include <iostream>
#include <assert.h>

#include <map>

class ParkingSystem {
    std::map<int, int> capacity;
    std::map<int, int> occupied;
public:
    ParkingSystem(int big, int medium, int small) {
        capacity[1] = big;
        capacity[2] = medium;
        capacity[3] = small;
    }
    
    bool addCar(int carType) {
        if(capacity[carType] >= occupied[carType] + 1)
        {
            occupied[carType]++;
            return true;
        }
        return false;
    }
};

int main()
{
    ParkingSystem obj(1, 1, 0);
    assert(obj.addCar(1) == true);
    assert(obj.addCar(2) == true);
    assert(obj.addCar(3) == false);
    assert(obj.addCar(1) == false);
    return 0;
}