#include <iostream>

// Define escape sequences for colors and formatting
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main() {
    int i = 1;
    do {
        std::cout << "\033[2J\033[1;1H";
        std::cout << BOLD << "Welcome to Vehicle Rental System" << RESET << std::endl;
        std::cout << "0 for " << RED << "Exit" << RESET << std::endl;
        std::cout << "1 for " << GREEN << "Login" << RESET << std::endl;
        std::cout << "2 for " << YELLOW << "SignUp" << RESET << std::endl;
        std::cout << "Enter your Input" << std::endl;
        std::cin >> i;
    } while (i != 0);

    return 0;
}
