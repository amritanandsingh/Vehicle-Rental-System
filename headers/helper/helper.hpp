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

    std::cout<<"Enter 0 for EXIT \n";
    std::cout<<"Enter 1 for Searching Vehical \n";
    std::cout<<"Enter 2 for Booking Vehical \n";

}
void vehicleSearchMenu()
{   
    std::cout<<"SEARCHING :- \n";
    std::cout<<"Enter ID of Vehicle or NA \n";
    std::cout<<"Enter status(free or booked) or NA \n";
    std::cout<<"Enter type(car , bike , bicycle) or NA \n";
}
#endif