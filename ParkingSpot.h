#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <string>
using namespace std;

class ParkingSpot
{
public:
    int floor, spotNumber;
    bool isOccupied;
    string vehicleNumber;

    ParkingSpot(int f, int s) : floor(f), spotNumber(s), isOccupied(false) {}

    void assignVehicle(string vehicle)
    {
        isOccupied = true;
        vehicleNumber = vehicle;
    }

    void removeVehicle()
    {
        isOccupied = false;
        vehicleNumber = "";
    }
};

#endif
