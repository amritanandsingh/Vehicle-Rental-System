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
                                        case 3:
                                            {
                                                bookingOps bookingOpsObj;
                                                bookingOpsObj.userSummary(id);
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
                                    int input=0;
                                    do{
                                        staffMenu();
                                        std::cin>>input;
                                        switch (input)
                                        {
                                        case 0:
                                            std::cout<<"You Have successfully logout \n";
                                            break;
                                        case 1:
                                            {
                                                bookingOps bookingOpsObj;
                                                bookingOpsObj.ListAllBooking();
                                            }
                                            break;
                                        case 2:
                                            {
                                                bookingOps bookingOpsObj;
                                                bookingOpsObj.listOfBookingOnDay();
                                            }
                                            break;
                                        case 3:
                                            {
                                                int choice;
                                                do{
                                                    crudVehicle();
                                                    std::cin>>choice;
                                                    switch (choice)
                                                    { 
                                                        case 0:
                                                            std::cout<<"Menu is Exit \n";
                                                            break;  
                                                        case 1:
                                                            {
                                                                Vehicle_CRUD Vehicle_CRUD_obj;
                                                                std::cout<<"Enter Vehicle ID for Delete "<<std::endl;
                                                                string id;
                                                                std::cin>>id;
                                                                Vehicle_CRUD_obj.deleteVehicle(id);   
                                 
                                                            }
                                                            break;
                                                        case 2:
                                                            {
                                                                std::string x,a,b,c;
                                                                updateVehicleMenu();
                                                                std::cin>>x>>a>>b>>c;
                                                                Vehicle_CRUD Vehicle_CRUD_obj;
                                                                Vehicle_CRUD_obj.update(x,a,b,c);
                                                            }
                                                            break;
                                                        case 3:
                                                            {
                                                                Vehicle_CRUD Vehicle_CRUD_obj;
                                                                std::cout<<"Enter Vehicle ID for Searching "<<std::endl;
                                                                string id;
                                                                std::cin>>id;
                                                                Vehicle_CRUD_obj.searching(id);   
                        
                                                            }
                                                            break;
                                                        case 4:
                                                            {
                                                                Vehicle_CRUD Vehicle_CRUD_obj;
                                                                Vehicle_CRUD_obj.create();
                                                            }
                                                            break;
                                                        default:
                                                            break;
                                                    }
                                                }while(choice!=0);
                                            }
                                        default:
                                            break;
                                        }

                                    }while(input!=0);



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