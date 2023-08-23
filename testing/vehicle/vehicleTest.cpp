#include<iostream>
#include "../../headers/vehicle/vehicle.hpp"

int main()
{
    Vehicle_CRUD obj;
    //obj.searching("NA","NA","bike");
    //obj.update("1234","booked");
    obj.deleteVehicle("1234");
    return 0;
}