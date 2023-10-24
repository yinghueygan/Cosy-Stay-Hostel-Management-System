#include "tenantLogin.h"
#include <iostream>
using namespace std;

tenantLogin::tenantLogin(string response, string choice, string choice2, string choice3, string choice4)
{
    this->response=response;
    this->choice=choice;
    this->choice2=choice2;
    this->choice3=choice3;
    this->choice4=choice4;
}

//choice of hostel details
string tenantLogin::getMainMenu()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |            Hostel Details            |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t        1. Room Information";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t        2. Rules and Regulations";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t Please enter your option to proceed (1 or 2): ";
    cin>>response;

    return response;
}

//choice of room information
string tenantLogin::getRoomInfo()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |             Room Details             |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t          1. Room Floor Plan"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t          2. Rental Fee List";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t Please enter your option to proceed (1 or 2): ";
    cin>>choice;

    return choice;
}

//choice of room floor plan
string tenantLogin::getSingleRoom()
{
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |             Single Room              |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t   ______________________________________________________________________________________________________________________"<<endl;
    cout<<"\t\t\t\t\t  |  _____________                     |                      WINDOWS                       |             _____________  |"<<endl;
    cout<<"\t\t\t\t\t  | |             |                    |____________________________________________________|            | |           | |"<<endl;
    cout<<"\t\t\t\t\t  | |             |                                                                                      | |           | |"<<endl;
    cout<<"\t\t\t\t\t  | |             |___                                                                                   | |           | |"<<endl;
    cout<<"\t\t\t\t\t  | |             |   |                                                                                  | |           | |"<<endl;
    cout<<"\t\t\t\t\t  | |    TABLE    |   |                                                                                  | |           | |"<<endl;
    cout<<"\t\t\t\t\t  | |             |   |                                                                                  |_| WARDROBE  | |"<<endl;
    cout<<"\t\t\t\t\t  | |             |___|                                                                                  | |           | |"<<endl;
    cout<<"\t\t\t\t\t  | |             |                                                                                      | |           | |"<<endl;
    cout<<"\t\t\t\t\t  | |             |                                                                                      | |           | |"<<endl;
    cout<<"\t\t\t\t\t  | |_____________|                                                                                      | |           | |"<<endl;
    cout<<"\t\t\t\t\t  |                                                                                                      | |           | |"<<endl;
    cout<<"\t\t\t\t\t  |                                                                                                      |_|___________| |"<<endl;
    cout<<"\t\t\t\t\t  |                                                                                                                      |"<<endl;
    cout<<"\t\t\t\t\t  |                                                                                                                      |"<<endl;
    cout<<"\t\t\t\t\t  |                                                                                                                      |"<<endl;
    cout<<"\t\t\t\t\t  |                                                                                                                      |"<<endl;
    cout<<"\t\t\t\t\t  |                                                                                                                      |"<<endl;
    cout<<"\t\t\t\t\t  |  ______________________________________________________________                                                      |"<<endl;
    cout<<"\t\t\t\t\t  | |              _____________________________________________   |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |             |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |   _______   |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |  |       |  |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |  |       |  |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |  |       |  |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |  |       |  |                BED                          |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |  |       |  |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |  |       |  |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |  |_______|  |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |             |                                             |  |                                                     |"<<endl;
    cout<<"\t\t\t\t\t  | |             |_____________________________________________|  |                                _____________________|"<<endl;
    cout<<"\t\t\t\t\t  | |______________________________________________________________|                                |        DOOR        |"<<endl;
    cout<<"\t\t\t\t\t  |_________________________________________________________________________________________________|____________________|"<<endl;

    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t  1. Move to Rental Fee List";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  2. Back to Hostel Details";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  3. Back to Main Menu";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  Which option would you like (1,2 or 3): ";
    cin>>choice2;

    return choice2;
}

//choice of rental fee
string tenantLogin::getRentalSingle()
{
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |        Rental Fee [Single]           |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t    * The rental fee list below is applicable to Block A, B(Female) and Block C, D(Male)"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t           BLOCK A & B & C & D"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t        *-------------------------------*"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |  .----. .----. .----. .----.  |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |  | 21 | | 22 | | 23 | | 24 |  |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |"<<endl;
    cout<<"\t\t\t\t\t\t\t_____________________________________________________"<<"\t\t|           6th Floor           |"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t*-------------------------------*"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t|  .----. .----. .----. .----.  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|  NO.  |   ID   |    FLOOR    |   MONTHLY RENTAL   |"<<"\t\t|  | 17 | | 18 | | 19 | | 20 |  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t|  '----' '----' '----' '----'  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|_______|________|_____________|____________________|"<<"\t\t|           5th Floor           |"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t*-------------------------------*"<<endl;
    cout<<"\t\t\t\t\t\t\t|   1   |   P7   |   Floor 1   |  RM350 per person  |"<<"\t\t|  .----. .----. .----. .----.  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|_______|________|_____________|____________________|"<<"\t\t|  | 13 | | 14 | | 15 | | 16 |  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t|  '----' '----' '----' '----'  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|   2   |   P8   |   Floor 2   |  RM350 per person  |"<<"\t\t|           4th Floor           |"<<endl;
    cout<<"\t\t\t\t\t\t\t|_______|________|_____________|____________________|"<<"\t\t*-------------------------------*"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t|  .----. .----. .----. .----.  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|   3   |   P9   |   Floor 3   |  RM400 per person  |"<<"\t\t|  | 09 | | 10 | | 11 | | 12 |  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|_______|________|_____________|____________________|"<<"\t\t|  '----' '----' '----' '----'  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t|           3rd Floor           |"<<endl;
    cout<<"\t\t\t\t\t\t\t|   4   |   P10  |   Floor 4   |  RM400 per person  |"<<"\t\t*-------------------------------*"<<endl;
    cout<<"\t\t\t\t\t\t\t|_______|________|_____________|____________________|"<<"\t\t|  .----. .----. .----. .----.  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t|  | 05 | | 06 | | 07 | | 08 |  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|   5   |   P11  |   Floor 5   |  RM450 per person  |"<<"\t\t|  '----' '----' '----' '----'  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|_______|________|_____________|____________________|"<<"\t\t|           2nd Floor           |"<<endl;
    cout<<"\t\t\t\t\t\t\t|       |        |             |                    |"<<"\t\t*-------------------------------*"<<endl;
    cout<<"\t\t\t\t\t\t\t|   6   |   P12  |   Floor 6   |  RM450 per person  |"<<"\t\t|  .----. .----. .----. .----.  |"<<endl;
    cout<<"\t\t\t\t\t\t\t|_______|________|_____________|____________________|"<<"\t\t|  | 01 | | 02 | | 03 | | 04 |  |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |  '----' '----' '----' '----'  |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |           1st Floor           |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t         =============================================="<<endl;

    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t  1. Move to Room Floor Plan";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  2. Back to Hostel Details";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  3. Back to Main Menu";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  Which option would you like (1,2 or 3): ";
    cin>>choice3;

    return choice3;
}

//choice of rules and regulations
string tenantLogin::getRules()
{
    system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |         Rules and Regulation         |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================" <<endl << endl ;
    cout<<"\t\t\t\t\t\t\t  1. Ragging is strictly prohibited in any form; if someone found guilty, severe action will be "<<endl;
    cout<<"\t\t\t\t\t\t\t     taken.  "<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  2. Students are not allowed to consume alcoholic, narcotic drugs or any intoxicating substance"<<endl;
    cout<<"\t\t\t\t\t\t\t     in the hostel premises."<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  3. All visitors to the hostel including the parents/guardian will have to make necessary entries"<<endl;
    cout<<"\t\t\t\t\t\t\t     in the visitors' book available at the hostel entrance with the security guard."<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  4. Students should not keep any unauthorized property and unauthorized guests in his/her room. "<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  5. No person, either guest or otherwise shall be permitted to stay overnight in any part of the"<<endl;
    cout<<"\t\t\t\t\t\t\t     hostel. In case, guest want to stay overnight in the hostel, he/she should take permission"<<endl;
    cout<<"\t\t\t\t\t\t\t     from warden."<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  6. Girls are not allowed to enter between 11 PM to 6 AM at boy's hostel."<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  7. Boys are not allowed to enter at the girl's hostel without permission."<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  8. Students are responsible for the safekeeping of their valuables. Students should provide their "<<endl;
    cout<<"\t\t\t\t\t\t\t     own locks and should take proper care of their belongings."<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  9. Students should handle hostel equipments, furniture, mess property carefully and not abuse or "<<endl;
    cout<<"\t\t\t\t\t\t\t     tamper with it. If so then applicable fine will be charged by the hostel management."<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t 10. Students have to use water and electricity judiciously. If fan, tube, etc., found ON in the"<<endl;
    cout<<"\t\t\t\t\t\t\t     absence of the students at their rooms, fine will be charged by hostel authorities."<<endl<<endl;

    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t            1. Move to Room Details";
    cout<<"\n\t\t\t\t\t\t\t\t\t            2. Back to Hostel Details";
    cout<<"\n\t\t\t\t\t\t\t\t\t            3. Back to Main Menu";
    cout<<"\n\t\t\t\t\t\t\t\t\t            Which option would you like (1,2 or 3): ";
    cin>>choice4;

    return choice4;

}


