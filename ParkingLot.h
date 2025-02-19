#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include <unordered_map>
#include "ParkingFloor.h"
#include "Vehicle.h"

class ParkingLot
{
private:
    int numFloors;
    int spotsPerFloor;
    vector<ParkingFloor> floors;
    unordered_map<string, tuple<int, int, string>> vehicleLocation;

public:
    ParkingLot(int numFloors, int spotsPerFloor);

    bool parkVehicle(string vehicleNumber, string type);
    void removeVehicle(string vehicleNumber);
    void displayAvailableSpots();
    bool isFull();
    void locateVehicle(string vehicleNumber);
};

#endif
