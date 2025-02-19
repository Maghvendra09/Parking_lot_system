#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include <vector>
#include "ParkingSpot.h"

class ParkingFloor
{
public:
    int floorNumber;
    vector<ParkingSpot> spots;

    ParkingFloor(int floorNumber, int spotsPerFloor);

    bool isSpotAvailable(int start, int spotsNeeded);
    void occupySpot(int start, string vehicleNumber, int spotsNeeded);
    void freeSpot(int start, int spotsNeeded);
    int availableSpots();
};

#endif
