#ifndef VALIDATION_HPP
#define VALIDATION_HPP
#include<iostream>
bool searchingValidation(std::string id , std::string status, std::string type)
{   
    int f=0;
    if(status=="NA" || (status=="free" || status=="booked"))
    {
        f++;
    }
    if(type=="car" || type=="bike" || type=="bicycle"  || type=="NA")
    {
        f++;
    }
    if(f==2)
    {
        return true;
    }
    return false;
}   

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    return day <= daysInMonth[month];
}
#endif