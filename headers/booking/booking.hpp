#ifndef BOOKING_HPP
#define BOOKING_HPP

#include<iostream>
#include<list>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include "./date.hpp"

class booking
{   
    public:
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
        booking(std::string customerId, std::string VehicleId, Date from, Date to, std::string type): start(from), end(to) // Initialize Date members using initializer list
        {
            this->customerId = customerId;
            this->VehicleId = VehicleId;
            this->type = type;
            this->cost = bill();
            std::cout<<"Total Fare Will Be "<<this->cost<<std::endl;
        }

};
class bookingOps{
        std::vector<std::string> convertSentenceToVector(const std::string& sentence) {
        std::vector<std::string> sentences;
        std::istringstream iss(sentence);
        std::string sentenceToken;

        while (std::getline(iss, sentenceToken, ',')) {
            sentences.push_back(sentenceToken);
        }

        return sentences;
    }
    public:
        
        void makeBooking(std::string  customerId, std::string vehicleId , std::string type) // for making booking for customer
        {
            try {
                std::cout << "Enter start Date of booking (in DD,MM,YYYY) " << std::endl;
                int dd, mm, yyyy;
                std::cin >> dd >> mm >> yyyy;
                std::cout << "Enter End Date of booking (in DD,MM,YYYY) " << std::endl;
                Date startDate(dd, mm, yyyy);
                std::cin >> dd >> mm >> yyyy;
                Date endDate(dd, mm, yyyy);
                booking bookingObj(customerId, vehicleId, startDate, endDate, type);

                std::fstream obj;
                obj.open("../../csv/booking.csv", std::ios::app);
                if (obj.is_open()) {
                    obj << bookingObj.customerId << "," << bookingObj.VehicleId << "," << bookingObj.type << "," << bookingObj.cost << ","
                        << bookingObj.start.dd << "," << bookingObj.start.mm << "," << bookingObj.start.yyyy << ","
                        << bookingObj.end.dd << "," << bookingObj.end.mm << "," << bookingObj.end.yyyy << "\n";
                    obj.close();
                } else {
                    std::cout << "Error in Opening File" << std::endl;
                }
            }
            catch(int i)
            {
                std::cout<<"Vehicle is Already booked \n ";
            }
            catch(...)
            {
                std::cout<<"Something Went Wrong \n ";
            }
            

        }
        void userSummary(std::string customerId) //all booking  summary for customer only
        {
            std::fstream obj;
            obj.open("../../csv/booking.csv", std::ios::in);
            if(obj.is_open())
            {
                std::string s;
                while(getline(obj,s))
                {
                    std::vector<std::string> words = convertSentenceToVector(s);
                    if(words[0]==customerId)
                    {
                        std::cout<<"Vehical ID : "<<words[1]<<std::endl;
                        std::cout<<"Type of Vehical : "<<words[2]<<std::endl;
                        std::cout<<"Total Cost Will be : "<<words[3]<<std::endl;
                        std::cout<<"Trip Starts on :"<<words[4]<<"/"<<words[5]<<"/"<<words[6]<<std::endl;
                        std::cout<<"Trip End on : "<<words[7]<<"/"<<words[8]<<"/"<<words[9]<<std::endl;
                        std::cout<<"---------------------------------------------------------------------------------------\n";
                    }
                }
            }
            else{
                std::cout<<"Error in Opening File Booking.csv \n";
            }
        }
        void ListAllBooking() // printing all  list for admin
        {
            std::fstream obj;
            double total = 0;
            obj.open("../../csv/booking.csv", std::ios::in);
            if(obj.is_open())
            {
                std::string s;
                std::cout<<"List of All Booked Vehicle"<<std::endl;
                while(getline(obj,s))
                {
                    std::vector<std::string> words = convertSentenceToVector(s);
                    {
                        std::cout<<"Vehical ID : "<<words[1]<<std::endl;
                        std::cout<<"Type of Vehical : "<<words[2]<<std::endl;
                        std::cout<<"Total Cost Will be : "<<words[3]<<std::endl;
                        total += stod(words[3]);
                        std::cout<<"Trip Starts on :"<<words[4]<<"/"<<words[5]<<"/"<<words[6]<<std::endl;
                        std::cout<<"Trip End on : "<<words[7]<<"/"<<words[8]<<"/"<<words[9]<<std::endl;
                        std::cout<<"---------------------------------------------------------------------------------------\n";
                    }
                }
                std::cout<<"Total Revenue : "<<total<<std::endl;
            }
            else{
                std::cout<<"Error in Opening File Booking.csv \n";
            }
        }
        void listOfBookingOnDay(Date date )  // booking on specific day for admin
        {

        }
        std::list<booking> head;
        /*
        bookingOps()
        {   
            std::fstream obj;
            obj.open("../../csv/booking.csv",std::ios::in);
            if(obj.is_open())
            {
                std::string line;
                while(getline(obj,line))
                {
                    //std::cout<<line<<std::endl;
                }
            }   
            else{
                std::cout<<"Error in opening booking.csv "<<std::endl;
            } 

        }
        ~bookingOps()
        {   
            
        }
        */
};
#endif