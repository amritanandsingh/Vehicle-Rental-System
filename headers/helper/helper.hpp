#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BOLD    "\033[1m"

void homeMenu() {
    system("clear");
    std::cout<<"\n\n---------------------------------------------------------------------------------- \n\n";
    // Define the menu options
    std::string menuOptions[] = {
        "Exit",
        "Login",
        "Sign Up"
    };

    // Calculate the width of the box
    int boxWidth = 40;

    // Display the box and menu
    std::cout << BOLD << "+" << std::string(boxWidth, '-') << "+" << RESET << std::endl;
    std::cout << "|" << std::setw(boxWidth) << "Welcome to the Vehicle Rental System" << "|" << std::endl;
    std::cout << "|" << std::setw(boxWidth) << "" << "|" << std::endl;
    
    for (int i = 0; i < sizeof(menuOptions) / sizeof(menuOptions[0]); ++i) {
        std::cout << "|" << std::setw(3) << i << ". " << (i == 0 ? RED : (i == 1 ? GREEN : YELLOW)) << menuOptions[i] << std::setw(boxWidth - 7 - menuOptions[i].length()) << "|" << std::endl;
    }

    std::cout << "|" << std::setw(boxWidth) << "" << "|" << std::endl;
    std::cout << "+" << std::string(boxWidth, '-') << "+" << std::endl;
}



void holdScreen()
{

    // Wait for user input before clearing screen
    std::cout << "Press Enter to continue...";
    std::cin.ignore(); // Clear newline character from previous input
    std::cin.get();    // Wait for user to press Enter

}

void logInView()
{
    std::cout<<"\n\n----------------------------------------------------------------------------------\n\n";
    std::cout<<"Enter User ID"<<std::endl;
    std::cout<<"Enter Password"<<std::endl;

       
}


bool isWord(const std::string &s) // Use const reference for parameter
    {
        for (int i = 0; i < s.size(); i++) {
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
                return false;
            }
        }
        return true;
    }

    bool isNumber(const std::string &s) // Use const reference for parameter
    {
        for (int i = 0; i < s.size(); i++) {
            if (!(s[i]>='0' && s[i]<='9')) {
                return false;
            }
        }
        return true;
    }
void menuForCustomer()
{   
    std::cout<<"\n\n----------------------------------------------------------------------------------\n\n";
    std::cout<<"Enter 0 for EXIT \n";
    std::cout<<"Enter 1 for Searching Vehicle \n";
    std::cout<<"Enter 2 for Booking Vehicle \n";
    std::cout<<"Enter 3 for view All booked Vehicle \n";
}

void vehicleSearchMenu()
{   
    std::cout<<"\n\n----------------------------------------------------------------------------------\n\n";
    std::cout<<"SEARCHING :- \n";
    std::cout<<"Enter ID of Vehicle or NA \n";
    std::cout<<"Enter status(free or booked) or NA \n";
    std::cout<<"Enter type(car , bike , bicycle) or NA \n";
}

void staffMenu()
{   
    std::cout<<"\n\n----------------------------------------------------------------------------------\n\n";
    std::cout<<"Enter your input for Respective Operation \n";
    std::cout<<"Enter 0 for EXIT "<<std::endl;
    std::cout<<"Enter 1 for view all Booking "<<std::endl;
    std::cout<<"Enter 2 for view list Of Booking on Date "<<std::endl;
    std::cout<<"Enter 3 for Delete , Update , Read , Create Vehicle"<<std::endl;
}
void crudVehicle()
{   std::cout<<"\n\n----------------------------------------------------------------------------------\n\n";
    std::cout<<"Enter your input for Respective Operation \n";
    std::cout<<"Enter 0 for EXIT "<<std::endl;
    std::cout<<"Enter 1 for Delete ."<<std::endl;
    std::cout<<"Enter 2 for Update . "<<std::endl;
    std::cout<<"Enter 3 for Read ."<<std::endl;
    std::cout<<"Enter 4 for Create ."<<std::endl;
}
void updateVehicleMenu()
{
    std::cout<<"\n\n----------------------------------------------------------------------------------\n\n";
    std::cout<<"Enter Vehicle ID for update "<<std::endl;
    std::cout<<"Enter status of Vehicle(free/booked) if not NA \n";
    std::cout<<"Enter type of Vehicle(car/bike/bicycle) if not NA \n";
    std::cout<<"Enter option of Vehicle(seatbelt,tyre,helmet) if not NA \n";
    
}
#endif