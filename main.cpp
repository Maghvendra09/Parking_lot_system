#include "ParkingLot.h"
#include <iostream>

using namespace std;

void showCommands()
{
    cout << "\nAvailable Commands:\n";
    cout << "1. park_vehicle <vehicle_number> <type>   - Park a vehicle (Car, Bike, Truck)\n";
    cout << "2. remove_vehicle <vehicle_number>        - Remove a parked vehicle\n";
    cout << "3. available_spots                        - Show available parking spots\n";
    cout << "4. locate <vehicle_number>                - Find vehicle location\n";
    cout << "5. isFull                                 - Check if the parking lot is full\n";
    cout << "6. EXIT                                   - Quit the program\n";
}
int main()
{
    cout << "Parking Lot System\n";

    int numFloors, numSpotsPerFloor;

    cout << "Enter number of floors : ";
    cin >> numFloors;

    cout << "Enter number of spots per floor : ";
    cin >> numSpotsPerFloor;

    ParkingLot parkingLot(numFloors, numSpotsPerFloor);
    showCommands();

    string command;
    while (true)
    {
        cout << "\n> ";
        cin >> command;

        if (command == "park_vehicle")
        {
            string vehicleNumber, type;
            cin >> vehicleNumber >> type;
            parkingLot.parkVehicle(vehicleNumber, type);
        }
        else if (command == "remove_vehicle")
        {
            string vehicleNumber;
            cin >> vehicleNumber;
            parkingLot.removeVehicle(vehicleNumber);
        }
        else if (command == "available_spots")
        {
            parkingLot.displayAvailableSpots();
        }
        else if (command == "locate")
        {
            string vehicleNumber;
            cin >> vehicleNumber;
            parkingLot.locateVehicle(vehicleNumber);
        }
        else if (command == "isFull")
        {
            if (parkingLot.isFull())
            {
                cout << "Parking Lot is full.\n";
            }
            else
            {
                cout << "Parking Lot is not full.\n";
            }
        }
        else if (command == "EXIT")
        {
            cout << "Exiting Parking System.\n";
            break;
        }
        else
        {
            cout << "Invalid command! Please try again.\n";
            showCommands();
        }
    }

    return 0;
}
