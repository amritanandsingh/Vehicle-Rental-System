#include<iostream>
#include "../../headers/helper/helper.hpp"
#include "../../headers/authentication/authentication.hpp"
#include "../../headers/signup/signup.hpp"
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
                            
                            std::cout<<"logged in ";

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