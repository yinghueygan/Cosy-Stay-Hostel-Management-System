#ifndef TENANT_H
#define TENANT_H
#include <iostream>
using namespace std;

class tenant
{
    string confirm;
    string name;
    string gender;
    string id;
    string phoneNo;
    string ic;
    int year;
    int term;
    int day;
    string block;
    int floor;
    int room;

public:
    tenant(string confirm, string name, string gender, string id, string phoneNo,
           string ic, int year, int term, int day, string block, int floor, int room);

    void bookingPrint();
    string getConfirm();
    string setName(string name);
    string getName() const;
    string setGender(string gender);
    string getGender() const;
    string setStuid(string id);
    string getStuid() const;
    string setPhoneNo(string phoneNo);
    string getPhoneNo() const;
    string setIC(string ic);
    string getIC() const;
    int setYear(int year);
    int getYear() const;
    int setTerm(int term);
    int getTerm() const;
    int setDay(int day);
    int getDay() const;
    void blockAPrint();
    void blockBPrint();
    void blockCPrint();
    void blockDPrint();
    string setBlock(string block);
    string getBlock() const;
    int setFloor(int floor);
    int getFloor() const;
    int setRoom(int room);
    int getRoom() const;
    void bookingInfoPrint();
    void display();
};

#endif // TENANT_H


