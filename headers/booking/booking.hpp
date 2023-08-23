#ifndef BOOKING_HPP
#define BOOKING_HPP

#include<iostream>
#include<list>
#include "./date.hpp"
class booking
{   
    private:
        double bill()
        {   double total=0;

            if(type=="bike")
            {
                total = 500; // base
                total += (end.dd - start.dd)*100 + (end.mm - start.mm)*100*30 + (end.mm - start.mm)*100*365 ;
            }
            else if(type=="car")
            {
                total = 1000; // base
                total += (end.dd - start.dd)*500 + (end.mm - start.mm)*500*30 + (end.mm - start.mm)*500*365 ;
            }
            else{
                total = 100;
                 total += (end.dd - start.dd)*50 + (end.mm - start.mm)*50*30 + (end.mm - start.mm)*50*365 ;
            }

            return total;
        }
        
        std::string customerId ;
        std::string VehicleId ;
        Date start;
        Date end;
        double cost ;
        std::string type;
    public:
        void booked(std::string customerId , std::string VehicleId , Date from , Date to , std::string type)
        {
            this->customerId = customerId;
            this->VehicleId = VehicleId;
            this->start = from;
            this->end = to;
            this->type = type;
            this->cost = bill();
        }

};
class bookingOps{
    public:
        
        void makeBooking() // for making booking
        {

        }
        void summary(std::string customerId) //all booking  summary for customer only
        {

        }
        void ListAllBooking() // printing all linked list for admin
        {
           
        }
        void listOfBookingOnDay(Date date )  // booking on specific day for admin
        {

        }
        std::list<booking> head;
        bookingOps()
        {   
            
        }
        ~bookingOps()
        {   
            
        }

};
#endif