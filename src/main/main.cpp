#include<iostream>
#include "../../headers/helper/helper.hpp"
#include "../../headers/errorHandler/validation.hpp"
#include "../../headers/authentication/authentication.hpp"
#include "../../headers/signup/signup.hpp"
#include "../../headers/vehicle/vehicle.hpp"
#include "../../headers/booking/booking.hpp"
int main()
{   
    int choice ;
    do {
        homeMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        // Handle User Choice
        switch (choice) {
            case 0:
                std::cout << "Thank you. Exiting the program." << std::endl;
                break;
            case 1:
                {  
                    {
                        logInView();
                        std::string id,password;
                        std::cin>>id>>password;
                        std::string type="NULL" ;
                        {
                            unique_ptr<authentication> Oauth_obj(new authentication) ;
                            type = Oauth_obj->logIn(id,password);
                        }
                        if(type != "NULL")
                        {   
                            std::cout<<"You Have logged as "<<type<<std::endl;
                            if(type == "customer")
                            {   int input=0;
                                do{
                                    menuForCustomer(); // menu for Customer
                                    std::cin>>input;
                                    switch (input)
                                    {   case 0:
                                            std::cout<<"You Have successfully logout \n";
                                            break;
                                        case 1:
                                            {   
                                                vehicleSearchMenu();
                                                
                                                std::string id, status , type;
                                                std::cin>>id>>status>>type;
                                                if(searchingValidation(id,status,type))
                                                {
                                                    Vehicle_CRUD obj;
                                                    std::cout<<"Searching Result is :-\n\n";
                                                    obj.searching(id , status , type );
                                                    std::cout<<"------------\n"<<endl;
                                                }
                                                else{
                                                    std::cout<<"Invalid Entry "<<std::endl;
                                                }
                                            }
                                            break;
                                        case 2:
                                            {
                                                string vehicleId;
                                                Vehicle_CRUD Vehicle_CRUD_obj;
                                                std::cout<<"Enter Vehical ID for Booking \n";
                                                cin>>vehicleId;
                                                std::string status = Vehicle_CRUD_obj.statusOfVehicle(vehicleId);
                                                if(status!="Not Found" || status == "free")
                                                {
                                                    bookingOps bookingObj;
                                                    std::string type = Vehicle_CRUD_obj.getVehicleType(vehicleId);
                                                    bookingObj.makeBooking(id,vehicleId,type);
                                                    Vehicle_CRUD_obj.toggleStatusOfVehicle(vehicleId);
                                                }
                                                else{
                                                    std::cout<<"Invalid Vehical ID or already Booked"<<endl;
                                                }

                                            }
                                            break;
                                        default:
                                            std::cout<<" WRONG INPUT \n ";
                                            break;
                                    }
                                }while(input!=0);
                            }
                            else{
                                if(type=="staff")
                                {

                                }
                            }
                        }
                        else{
                            std::cout<<"wrong credentials"<<std::endl;
                        }
                    }
                }
                break;
            case 2:
                {
                    SignUp signUp_obj;
                    signUp_obj.form();
                }
                break;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
                break;
        }
        holdScreen();
    } while (choice != 0);
    return 0;
    
}