#include "ParkingFloor.h"

ParkingFloor::ParkingFloor(int floorNumber, int spotsPerFloor) : floorNumber(floorNumber)
{
    for (int i = 0; i < spotsPerFloor; i++)
    {
        spots.emplace_back(floorNumber, i);
    }
}

bool ParkingFloor::isSpotAvailable(int start, int spotsNeeded)
{
    for (int i = 0; i < spotsNeeded; i++)
    {
        if (spots[start + i].isOccupied)
            return false;
    }
    return true;
}

void ParkingFloor::occupySpot(int start, string vehicleNumber, int spotsNeeded)
{
    for (int i = 0; i < spotsNeeded; i++)
    {
        spots[start + i].assignVehicle(vehicleNumber);
    }
}

void ParkingFloor::freeSpot(int start, int spotsNeeded)
{
    for (int i = 0; i < spotsNeeded; i++)
    {
        spots[start + i].removeVehicle();
    }
}

int ParkingFloor::availableSpots()
{
    int count = 0;
    for (auto &spot : spots)
    {
        if (!spot.isOccupied)
            count++;
    }
    return count;
}
