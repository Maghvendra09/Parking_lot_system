#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int numFloors, int spotsPerFloor) : numFloors(numFloors), spotsPerFloor(spotsPerFloor)
{
    for (int i = 0; i < numFloors; i++)
    {
        floors.emplace_back(i, spotsPerFloor);
    }
}

bool ParkingLot::parkVehicle(string vehicleNumber, string type)
{
    if (vehicleLocation.find(vehicleNumber) != vehicleLocation.end())
    {
        cout << "Error: Vehicle " << vehicleNumber << " is already parked!\n";
        return false;
    }
    Vehicle *vehicle;
    if (type == "Car")
        vehicle = new Car(vehicleNumber);
    else if (type == "Bike")
        vehicle = new Bike(vehicleNumber);
    else if (type == "Truck")
        vehicle = new Truck(vehicleNumber);
    else
    {
        cout << "Invalid vehicle type\n";
        return false;
    }

    int spotsNeeded = vehicle->requiredSpots;

    for (int i = 0; i < numFloors; i++)
    {
        for (int j = 0; j <= spotsPerFloor - spotsNeeded; j++)
        {
            if (floors[i].isSpotAvailable(j, spotsNeeded))
            {
                floors[i].occupySpot(j, vehicle->vehicleNumber, spotsNeeded);
                vehicleLocation[vehicle->vehicleNumber] = {i, j, type};

                cout << "Vehicle " << vehicle->vehicleNumber << " parked at Floor " << i << ", Spot(s) ";
                if (spotsNeeded == 2)
                    cout << j << " & " << j + 1;
                else
                    cout << j;
                cout << endl;

                delete vehicle;
                return true;
            }
        }
    }

    cout << "No available parking spot for " << vehicle->vehicleNumber << endl;
    delete vehicle;
    return false;
}

void ParkingLot::removeVehicle(string vehicleNumber)
{
    if (vehicleLocation.find(vehicleNumber) == vehicleLocation.end())
    {
        cout << "Vehicle not found in parking lot.\n";
        return;
    }

    auto [floor, spot, type] = vehicleLocation[vehicleNumber];
    int spotsNeeded = (type == "Truck") ? 2 : 1;
    cout << "Removing Vehicle " << vehicleNumber << " from Floor " << floor << ", Spot(s) ";
    if (spotsNeeded == 2)
        cout << spot << " & " << spot + 1;
    else
        cout << spot;
    cout << endl;

    floors[floor].freeSpot(spot, spotsNeeded);
    vehicleLocation.erase(vehicleNumber);
}

void ParkingLot::displayAvailableSpots()
{
    for (int i = 0; i < numFloors; i++)
    {
        cout << "Floor " << i << ": " << floors[i].availableSpots() << " available spots\n";
    }
}

bool ParkingLot::isFull()
{
    for (auto &floor : floors)
    {
        if (floor.availableSpots() > 0)
            return false;
    }
    return true;
}

void ParkingLot::locateVehicle(string vehicleNumber)
{
    if (vehicleLocation.find(vehicleNumber) == vehicleLocation.end())
    {
        cout << "Vehicle " << vehicleNumber << " not found in parking lot.\n";
    }
    else
    {
        auto [floor, spot, type] = vehicleLocation[vehicleNumber];
        int spotsNeeded = (type == "Truck") ? 2 : 1;

        cout << "Vehicle " << vehicleNumber << " is at Floor " << floor << ", Spot(s) ";
        if (spotsNeeded == 2)
            cout << spot << " & " << spot + 1;
        else
            cout << spot;
        cout << endl;
    }
}
