#include "login.h"
#include <iostream>
using namespace std;

login::login(string opt)
{
    this->opt=opt;
};

//login CS hostel
void login::print()
{
    cout<<endl<<"\n\n\n\t\t\t\t\t\t\t             __      __        __                                   __________\n";
    cout<<"\t\t\t\t\t\t\t            /  \\    /  \\ ____ |  | ____  ____    _____   ____       \\___  ___/____\n";
    cout<<"\t\t\t\t\t\t\t            \\   \\/\\/   // __ \\|  |/ ___\\/  _ \\  /     \\ / __ \\         Y  Y  /  _ \\\n";
    cout<<"\t\t\t\t\t\t\t             \\        /|  ___/|  |  \\__(  <_> )|  Y Y  \\|  ___/        |  | (  <_> )    \n";
    cout<<"\t\t\t\t\t\t\t              \\__/\\__/  \\____\\|__|\\_____>____/ |__|_|__|\\____\\         |__|  \\____/\n";
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t                 _ _____________                 ____________\n";
    cout<<"\t\t\t\t\t\t\t\t                / \\_____________\\              /_____________/\\\n";
    cout<<"\t\t\t\t\t\t\t\t               / /               \\            /              \\ \\\n";
    cout<<"\t\t\t\t\t\t\t\t              / /                 \\          |     ________   \\ \\\n";
    cout<<"\t\t\t\t\t\t\t\t             / /       ______      \\         |    /        \\___\\/\n";
    cout<<"\t\t\t\t\t\t\t\t            | |       /      \\_____/         |   \\\n";
    cout<<"\t\t\t\t\t\t\t\t            | |      |       ______           \\    \\___________\n";
    cout<<"\t\t\t\t\t\t\t\t            | |      |\\_____/\\_____\\           \\ __________   \\ \\\n";
    cout<<"\t\t\t\t\t\t\t\t             \\|       \\______/     /          ___          |   | |\n";
    cout<<"\t\t\t\t\t\t\t\t               \\                  /          \\   \\_________|   | |\n";
    cout<<"\t\t\t\t\t\t\t\t                \\                /            \\                |/\n";
    cout<<"\t\t\t\t\t\t\t\t                 \\______________/              \\ ____________ / \n";
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t    -----------------------------------------------------------------------------------------\n\n";
    cout<<"\t\t\t\t\t\t\t              Good day! Welcome to CS(Cozy Stay) hostel management system.\n\n";
    cout<<"\t\t\t\t\t\t\t    Thinking about a super fast and easy hostel renting? Cozy Stay is now available to turn\n";
    cout<<"\t\t\t\t\t\t\t    the operation of hostel into an organised and effective manner. In this system, you are\n";
    cout<<"\t\t\t\t\t\t\t    able to book a room, make payment and also know more about the details of hostel.\n\n";
    cout<<"\t\t\t\t\t\t\t                    Give it a try now and you will be amazed by it!"<<endl;
    system("pause");
    system("cls");

}
//login access menu
string login::accessLogin()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t            _____\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t           /     \\   ____   ____    __ __\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t          /  \\ /  \\_/ __ \\ /     \\ |  |  |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t         /    Y    \\  ___/|   |   \\|  |  |\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t         \\____|____/\\____>____|____|_____| \n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       1. Hostel Details";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       2. Administrator Access";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       3. Exit";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t    Please enter your option to proceed (1,2 or 3): ";
    cin>>opt;

    return opt;
}


