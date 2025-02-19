#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
public:
    string vehicleNumber;
    int requiredSpots;

    Vehicle(string number, int spots) : vehicleNumber(number), requiredSpots(spots) {}
    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
public:
    Car(string number) : Vehicle(number, 1) {}
};

class Bike : public Vehicle
{
public:
    Bike(string number) : Vehicle(number, 1) {}
};

class Truck : public Vehicle
{
public:
    Truck(string number) : Vehicle(number, 2) {}
};

#endif
