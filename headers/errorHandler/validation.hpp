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
#endif