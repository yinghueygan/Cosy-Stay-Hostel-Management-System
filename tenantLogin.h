#ifndef TENANT_LOGIN_H
#define TENANT_LOGIN_H
#include <iostream>
using namespace std;

class tenantLogin{
    string response;
    string choice;
    string choice2;
    string choice3;
    string choice4;

public:
    tenantLogin(string response, string choice, string choice2, string choice3, string choice4);

    string getMainMenu();
    string getRoomInfo();
    string getSingleRoom();
    string getRentalSingle();
    string getRules();
};

#endif // TENANT_LOGIN_H


