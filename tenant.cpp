#include "tenant.h"

#include <iomanip>
#include <iostream>
using namespace std;

tenant::tenant(string confirm, string name, string gender, string id, string phoneNo, string ic, int year, int term, int day, string block, int floor, int room)
{
    this->confirm=confirm;
    this->name=name;
    this->gender=gender;
    this->id=id;
    this->phoneNo=phoneNo;
    this->ic=ic;
    this->year=year;
    this->term=term;
    this->day=day;
    this->block=block;
    this->floor=floor;
    this->room=room;
}
void tenant::bookingPrint()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t             __      __        __                                   __________\n";
    cout<<"\t\t\t\t\t\t\t            /  \\    /  \\ ____ |  | ____  ____    _____   ____       \\___  ___/____\n";
    cout<<"\t\t\t\t\t\t\t            \\   \\/\\/   // __ \\|  |/ ___\\/  _ \\  /     \\ / __ \\         Y  Y  /  _ \\\n";
    cout<<"\t\t\t\t\t\t\t             \\        /|  ___/|  |  \\__(  <_> )|  Y Y  \\|  ___/        |  | (  <_> )    \n";
    cout<<"\t\t\t\t\t\t\t              \\__/\\__/  \\____\\|__|\\_____>____/ |__|_|__|\\____\\         |__|  \\____/\n";
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    _____  ____  _____ __   __     _____ _______ ___ __   __\n";
    cout<<"\t\t\t\t\t\t\t\t\t   / ____\\/ __ \\\\___  /\\ \\ / /    /  ___\\\\__ __// _ \\\\ \\ / / \n";
    cout<<"\t\t\t\t\t\t\t\t\t   | |   [ [  ] ]  / /  \\ Y /     | |___   Y Y / /_\\ \\\\ Y /\n";
    cout<<"\t\t\t\t\t\t\t\t\t   | |___[ [__] ] / /___ | |      \\____ \\  | | |  _  | | |\n";
    cout<<"\t\t\t\t\t\t\t\t\t   \\_____/\\____/ /_____/ |_|      \\_____/  |_| |__|__| |_|\n";
    cout<<endl<<endl;
}
string tenant::getConfirm()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t        --  To proceed, please enter (0)   -- "<< endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t      --  To make changes, please enter (1)  -- "<< endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t   Your choice: ";
    cin>>confirm;

    return confirm;
}
string tenant::setName(string name)
{
    this->name=name;
}
string tenant::getName() const
{
    return name;
}
string tenant::setGender(string gender)
{
   /* if(gender>='a' && gender<='z')
    {
        gender-=32;
    }*/
    this->gender=gender;
}
string tenant::getGender() const
{
    return gender;
}
string tenant::setStuid(string id)
{
    this->id=id;
}
string tenant::getStuid() const
{
    return id;
}
string tenant::setPhoneNo(string phoneNo)
{
    this->phoneNo=phoneNo;
}
string tenant::getPhoneNo() const
{
    return phoneNo;
}
string tenant::setIC(string ic)
{
    this->ic=ic;
}
string tenant::getIC() const
{
    return ic;
}
int tenant::setYear(int year)
{
    this->year=year;
}
int tenant::getYear() const
{
    return year;
}
int tenant::setTerm(int term)
{
    this->term=term;
}
int tenant::getTerm() const
{
    return term;
}
int tenant::setDay(int day)
{
    this->day=day;
}
int tenant::getDay() const
{
    return day;
}
void tenant::blockAPrint()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t========================================" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|                                       |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|    BLOCK A - Single Room [female]     |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|                                       |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t========================================" << endl << endl ;
    cout<<"\t\t\t\t\t\t\t\t\t\t            _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t           /                               /*\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t          /                               / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t         /                               /  |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 21 | | 22 | | 23 | | 24 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           6th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 17 | | 18 | | 19 | | 20 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           5th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 13 | | 14 | | 15 | | 16 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           4th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 09 | | 10 | | 11 | | 12 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           3rd Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 05 | | 06 | | 07 | | 08 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           2nd Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 01 | | 02 | | 03 | | 04 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |  /\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           1st Floor           | /\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *--------------------------------*\n";
}
void tenant::blockBPrint()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t========================================" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|                                       |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|    BLOCK B - Single Room [female]     |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|                                       |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t========================================" << endl << endl ;
    cout<<"\t\t\t\t\t\t\t\t\t\t            _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t           /                               /*\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t          /                               / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t         /                               /  |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 21 | | 22 | | 23 | | 24 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           6th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 17 | | 18 | | 19 | | 20 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           5th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 13 | | 14 | | 15 | | 16 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           4th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 09 | | 10 | | 11 | | 12 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           3rd Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 05 | | 06 | | 07 | | 08 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           2nd Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 01 | | 02 | | 03 | | 04 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |  /\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           1st Floor           | /\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *--------------------------------*\n";
}
void tenant::blockCPrint()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t========================================" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|                                       |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|     BLOCK C - Single Room [male]      |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|                                       |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t========================================" << endl << endl ;
    cout<<"\t\t\t\t\t\t\t\t\t\t            _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t           /                               /*\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t          /                               / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t         /                               /  |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 21 | | 22 | | 23 | | 24 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           6th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 17 | | 18 | | 19 | | 20 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           5th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 13 | | 14 | | 15 | | 16 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           4th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 09 | | 10 | | 11 | | 12 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           3rd Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 05 | | 06 | | 07 | | 08 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           2nd Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 01 | | 02 | | 03 | | 04 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |  /\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           1st Floor           | /\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *--------------------------------*\n";
}
void tenant::blockDPrint()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t========================================" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|                                       |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|     BLOCK D - Single Room [male]      |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t|                                       |"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t========================================" << endl << endl ;
    cout<<"\t\t\t\t\t\t\t\t\t\t            _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t           /                               /*\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t          /                               / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t         /                               /  |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 21 | | 22 | | 23 | | 24 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           6th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 17 | | 18 | | 19 | | 20 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           5th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 13 | | 14 | | 15 | | 16 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           4th Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 09 | | 10 | | 11 | | 12 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           3rd Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 05 | | 06 | | 07 | | 08 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           2nd Floor           | / |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *-------------------------------*   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  | 01 | | 02 | | 03 | | 04 |  |   |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |  /\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        |           1st Floor           | /\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t        *--------------------------------*\n";
}
string tenant::setBlock(string block)
{
    /*if(block>='a' && block<='z')
    {
        block-=32;
    }*/
    this->block=block;
}
string tenant::getBlock() const
{
    return block;
}
int tenant::setFloor(int floor)
{
    this->floor=floor;
}
int tenant::getFloor() const
{
    return floor;
}
int tenant::setRoom(int room)
{
    this->room=room;
}
int tenant::getRoom() const
{
    return room;
}
void tenant::bookingInfoPrint()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================" << endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<< endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |            Tenant Details            |"<< endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<< endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================" << endl << endl;
    cout<<"\t\t\t\t\t\t\t\t\t  * All the information obtained will be kept confidential"<<endl<<endl<<endl;
}

void tenant::display()
{
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |"<<"     "<<getName()<<setw(1)<<"\t\t"
                                <<getIC()<<"\t      "
                                <<getGender()<<"\t         "
                                <<getStuid()<<"\t      "
                                <<getPhoneNo()<<"\t   "
                                <<getBlock()<<"-"<<getFloor()<<"-"<<getRoom()<<"\t  "
                                <<getDay()<<"/"<<getTerm()<<"/"<<getYear()<<endl;
    cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;

}
