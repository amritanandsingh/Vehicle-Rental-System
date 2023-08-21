#include<iostream>
#include<string>
#include "../../headers/authentication/authentication.hpp"
#include "../../headers/authentication/authentication.cpp"
int main()
{
    authentication *auth_obj=new authentication; 
    std::string userid="123";
    std::string password="123";
    std::string type="staff";
    
    std::cout<<auth_obj->logIn(userid,password,type);
    std::cout<<"hello";
    return 0;
}