#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <list>
#include <memory>
#include <fstream>
#include <vector>  // Added for std::vector
#include <algorithm>  // Added for std::transform
#include <sstream>

class Vehicle {
public:
    std::string id;
    std::string status;
    Vehicle(std::string id, std::string status)
    {
        this->id = id;
        this->status = status;
    }
    virtual std::string& getType(){std::string s ;  return s;}
    virtual std::string& getOther(){std::string s ; return s;}
    
};

class Car: public Vehicle {
public:
    std::string type; 
    std::string seatbelt;
    Car(std::string id, std::string status, std::string type, std::string seatbelt): Vehicle(id, status), type(type), seatbelt(seatbelt)
    {
        this->type = type;
        this->seatbelt= seatbelt;
    }
    std::string& getType(){
        return this->type;
    }
    std::string& getOther()
    {
        return this->seatbelt;
    }
};

class Bike : public Vehicle {
public:
    std::string type;
    std::string helmet;
    Bike(std::string id, std::string status, std::string type, std::string helmet): Vehicle(id, status), type(type), helmet(helmet)
    {
        this->type = type;
        this->helmet = helmet;
    }
    std::string& getType(){
        return this->type;
    }
    std::string& getOther()
    {
        return this->helmet;
    }
};

class Bicycle : public Vehicle {
public:
    std::string type;
    std::string wheeltype;
    Bicycle(std::string id, std::string status, std::string type, std::string wheeltype): Vehicle(id, status), type(type), wheeltype(wheeltype)
    {
        this->type = type;
        this->wheeltype = wheeltype;
    }
    std::string& getType(){
        return this->type;
    }
    std::string& getOther()
    {
        return this->wheeltype;
    }
};

class VehicleFactory {
public:
    Vehicle* createVehicle(std::string id, std::string status, std::string type, std::string other) {
        if (type == "car") {
            return new Car(id, status, type, other);
        } else if (type == "bike") {
            return new Bike(id, status, type, other);
        } else if (type == "bicycle") {
            return new Bicycle(id, status, type, other);
        }
        // Return a default-constructed Vehicle if the type is invalid
        return nullptr;
    }
};

class Vehicle_CRUD {
private:
    std::string convertToLower(std::string inputString) {
        std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        return inputString;
    }

public:
    std::list<Vehicle* > head;

    std::vector<std::string> takeInputForCreate()
    {
        std::string s;
        std::vector<std::string> vehicleInfo;
        std::cout << "what is Number of vehicle \n";
        std::cin >> s;
        vehicleInfo.push_back(s);
        std::cout << "what is status of vehicle (free or booked) \n";
        std::cin >> s;
        s = convertToLower(s);
        vehicleInfo.push_back(s);
        std::cout << "what is type vehicle(bike , car , bicycle ) \n";
        std::cin >> s;
        s = convertToLower(s);
        vehicleInfo.push_back(s);
        if (s == "bike")
        {
            std::cout << "what is of helmet of bike\n";
            std::cin >> s;
            s = convertToLower(s);
            vehicleInfo.push_back(s);
        }
        if (s == "bicycle")
        {
            std::cout << "what is type wheeel of bicycle \n";
            std::cin >> s;
            s = convertToLower(s);
            vehicleInfo.push_back(s);
        }
        if (s == "car")
        {
            std::cout << "what is number of seatbelt in car \n";
            std::cin >> s;
            s = convertToLower(s);
            vehicleInfo.push_back(s);
        }
        return vehicleInfo;  // Add this line
    }
    std::vector<std::string> convertSentenceToVector(const std::string& sentence) {
        std::vector<std::string> sentences;
        std::istringstream iss(sentence);
        std::string sentenceToken;

        while (std::getline(iss, sentenceToken, ',')) {
            sentences.push_back(sentenceToken);
        }

        return sentences;
    }
    Vehicle_CRUD()
    {
        std::fstream obj;
        obj.open("../../csv/vehicle.csv",std::ios::in);
        if(obj.is_open())
        {
            std::string line;
            while (getline(obj, line))
            {
                std::vector<std::string> words_of_line = convertSentenceToVector(line);
                VehicleFactory factory_obj;
                Vehicle *new_vehicle = factory_obj.createVehicle(words_of_line[0], words_of_line[1], words_of_line[2], words_of_line[3]);
                head.push_back(new_vehicle);
            }
        }
        else{
            std::cout<<"Error in opening File \n";
        }
    }

    void create()
    {
        std::vector<std::string> info = takeInputForCreate();  // Fix the spelling here
        VehicleFactory factory_obj;
        Vehicle *new_vehicle = factory_obj.createVehicle(info[0], info[1], info[2], info[3]);
        head.push_back(new_vehicle);
    }
    void searching(std::string id="NA" , std::string status="NA" , std::string type = "NA")
    {
        std::list<Vehicle*>::iterator ptr ;
        for ( ptr = head.begin(); ptr != head.end(); ptr++)
        {
            //std::cout<<(*ptr)->getType();
            if(id == ((*ptr)->id) || status==((*ptr)->status) || type== ((*ptr)->getType()))
            {
                std::cout << ((*ptr)->id) << " " << ((*ptr)->status) << " " << ((*ptr)->getType()) << " "<< ((*ptr)->getOther())<<std::endl;
            }
        }
    }
    void update(std::string id="NA" , std::string status="NA" , std::string type = "NA" , std::string option = "NA")
    {   
        int flag= 0;
        std::list<Vehicle*>::iterator ptr ;
        for ( ptr = head.begin(); ptr != head.end(); ptr++)
        {
            //std::cout<<(*ptr)->getType();
            if(id == ((*ptr)->id) )
            {   flag=1;
                if(status!="NA")
                {
                    ((*ptr)->status) = status;
                }
                if(type != "NA")
                {
                    (*ptr)->getType() = type;
                }
                if(option != "NA")
                {
                    (*ptr)->getOther()= option;
                }
            }
        }
        if(flag)
        {
            std::cout<<"Update is Done \n";
        }
        else{
            std::cout<<"Update is failed or Error \n";
        }
    }
    void deleteVehicle(std:: string id)
    {
        int flag= 0;
        std::list<Vehicle*>::iterator ptr , temp ;
        for ( ptr = head.begin(); ptr != head.end(); ptr++)
        {
            //std::cout<<(*ptr)->getType();
            
            if(id == ((*ptr)->id) )
            {   
                if(((*ptr)->status)=="booked")
                {
                    std::cout<<"Can't Delete Vehical because it was already Booked by some Customer"<<std::endl;
                    return ;
                }
                flag=1;
                temp = ptr;
            }
        }

        if(flag)
        {   
            head.erase(temp);
            std::cout<<"Delete is Done \n";
        }
        else{
            std::cout<<"Delete is failed or Error \n";
        } 
    }
    ~Vehicle_CRUD()
    {
        std::fstream obj;
        obj.open("../../csv/newVehicle.csv", std::ios::out);  // Use correct absolute path
        if (obj.is_open())
        {
            std::list<Vehicle*>::iterator ptr ;
            for ( ptr = head.begin(); ptr != head.end(); ptr++)
            {
                //std::cout<<(*ptr)->getType();
                obj << ((*ptr)->id) << "," << ((*ptr)->status) << "," << ((*ptr)->getType()) << ","<< ((*ptr)->getOther());
                obj << "\n";  // Add a newline
            }
            obj.close();
            std::remove("../../csv/vehicle.csv");  // Use correct absolute paths
            std::rename("../../csv/newVehicle.csv", "../../csv//vehicle.csv");  // Use correct absolute paths
            
            for ( ptr = head.begin(); ptr != head.end(); ptr++)
            {
               delete *ptr;
            }
        }
        else
        {
            std::cout << "error in opening file \n";
        }
    }
    std::string statusOfVehicle(std::string vehicleID)
    {
        std::list<Vehicle*>::iterator ptr ;
        for ( ptr = head.begin(); ptr != head.end(); ptr++)
        {
            //std::cout<<(*ptr)->getType();
            if(vehicleID == ((*ptr)->id) && ((*ptr)->status)=="free")
            {
               return ((*ptr)->status);
            }
        }
        return "Not Found";
    }
    void toggleStatusOfVehicle(std::string vehicleID)
    {
        int i=0;
        std::list<Vehicle*>::iterator ptr ;
        for ( ptr = head.begin(); ptr != head.end(); ptr++)
        {
            //std::cout<<(*ptr)->getType();
            if(vehicleID == ((*ptr)->id) )
            {   i=1;
                if(((*ptr)->status)=="free") 
                {
                    (*ptr)->status="booked";
                }
                else if(((*ptr)->status)=="booked") 
                {
                    (*ptr)->status="free";
                }
            }
        }
        if(i)
        std::cout<<"Toggle is Done\n";
        else{
            std::cout<<"Vehicle Not Found\n";
        }
    }
    std::string getVehicleType(std::string vehicleID)
    {
        std::list<Vehicle*>::iterator ptr ;
        for ( ptr = head.begin(); ptr != head.end(); ptr++)
        {
            //std::cout<<(*ptr)->getType();
            if(vehicleID == ((*ptr)->id) )
            {
               return (*ptr)->getType();
            }
        }
        return "Not Found";
    }

    
};

#endif
