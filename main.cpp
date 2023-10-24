#include <iostream> //cout cin
#include <cstdlib> //clear screen: system("pause")
#include <windows.h> //background color, text color, beep sound
#include <cctype> //check string boolean
#include <iomanip> //decimal manipulation
#include <fstream> //file handling
#include <sstream> //file handling
#include <stack> //display record for searching
#include <vector> //store user data
#include <queue> //display record for sorting
#include <stdexcept> //runtime error
#include <climits> //INT_MAX
#include <string> //stoi

#include "tenant.cpp"
#include "login.cpp"
#include "tenantLogin.cpp"

using namespace std;

//------------------------------- ----------------------------global variables-----------------------------------------------------------------
char *l = " ---------------------------------------------------------------------------------------------------------------------------------------------\n";
char *w = " =============================================================================================================================================\n";

//for asking choice, reply and answers
string opt, confirm, record;
string choice, choice2, choice3, choice4;
string response, response2, response3;
char r, answer, answer2, answer3;

//c is index count to specific tenant
int c;

//for tenant information
string name, id, phoneNo, ic;
string gender, block;
int floor, room;
int year, term, day;

vector<tenant> data;
tenant t(confirm, name, gender, id, phoneNo, ic, year, term, day, block, floor, room);

//---------------------------------------------------------file handling-------------------------------------------------------------------------------
void readfile()
{
    //create an input filestream
    ifstream inFile("record.txt");

    //make sure the file is open
    if(!inFile.is_open())
        throw runtime_error("Sorry, it is unable to open the file.");

    if (inFile.is_open())
    {
        string gender, block, floor, room, day, term ,year;
        inFile.ignore(INT_MAX,'\n');

        while(inFile.good()) //check if the stream has raised any error or not
        {
            while(inFile.peek()!=EOF) //check if the stream has raised any "end of file" error
            {
                getline(inFile, name, ',');
                t.setName(name);

                getline(inFile, ic, ',');
                t.setIC(ic);

                getline(inFile, gender, ',');
                t.setGender(gender);

                getline(inFile, id, ',');
                t.setStuid(id);

                getline(inFile, phoneNo, ',');
                t.setPhoneNo(phoneNo);

                getline(inFile, block, '-');
                t.setBlock(block);

                getline(inFile, floor, '-');
                t.setFloor(stoi(floor));

                getline(inFile, room, ',');
                t.setRoom(stoi(room));

                getline(inFile, day, '/');
                t.setDay(stoi(day));

                getline(inFile, term, '/');
                t.setTerm(stoi(term));

                getline(inFile, year, '\n');
                t.setYear(stoi(year));

                data.push_back(t);
            }
            inFile.close();
        }
    }
}
void writefile()
{
    ofstream outFile;
    outFile.open("record.txt");
    outFile<<"NAME, IC, GENDER, STUDENT ID, PHONE NUMBER, ROOM NO., MOVE IN DATE"<<endl;
    for(unsigned int i=0; i<data.size(); i++)
        //send data to the stream
        outFile<<data[i].getName()<<","
               <<data[i].getIC()<<","
               <<data[i].getGender()<<","
               <<data[i].getStuid()<<","
               <<data[i].getPhoneNo()<<","
               <<data[i].getBlock()<<"-"<<data[i].getFloor()<<"-"<<data[i].getRoom()<<","
               <<data[i].getDay()<<"/"<<data[i].getTerm()<<"/"<<data[i].getYear()<<endl;
    outFile.close(); //close the file
}
//-----------------------------------------------boolean functions------------------------------------------------------------------------------
bool isLetters(string input)
{
    for (unsigned int i=0; i<input.size(); i++)
    {
        if (isalpha(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isNumbers(string input)
{
    for (unsigned int i=0; i<input.size(); i++)
    {
        if (isdigit(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isPunct(string input)
{
    for (unsigned int i=0; i<input.size(); i++)
    {
        if (ispunct(input[i]))
        {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------void function-----------------------------------------------------------------------
void addRecord();
void delRecord();

void verifyEdit();
void editRecord();
void printEdit(vector<tenant>& data);

void viewRecord(vector<tenant>& data);

void searchRecord();
void searchByName(string name);
void searchByStuid(string id);
void searchByBlock(string block);
void searchByDate(int day, int term, int year);
void printSearch(stack<tenant> myStack);

void sortRecord();
void sortByName(vector<tenant>& data);
void sortByStuid(vector<tenant>& data);
void sortByBlock(vector<tenant>& data);
void sortByDate(vector<tenant>& data);
void printSort(queue<tenant> myQueue);

//-------------------------------------------------------void for add tenant-------------------------------------------------------------------
//get input of student id
void stuidIn()
{
    do{
            cout<<"\n\t\t\t\t\t\t\t\t\t  Please enter Student ID (1191100123): ";
            cin>>id;
            t.setStuid(id);

        if (!isLetters(id) && isNumbers(id) && !isPunct(id) && id.size()==10)
        {
            return;
        }
        else
        {
            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, Student ID must have 10 digits without dash and space."<<endl;
            Beep(300,500);
            cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
        }

    }while(true);
}

//get input of phone number
void phoneNoIn()
{
    do{
            cout<<"\n\t\t\t\t\t\t\t\t\t  Please enter your phone number (01110345678): ";
            cin>>phoneNo;
            t.setPhoneNo(phoneNo);

        if (!isLetters(phoneNo) && isNumbers(phoneNo) && !isPunct(phoneNo) && phoneNo.size()>=10 && phoneNo.size()<=11)
        {
            return;
        }
        else
        {
            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, phone number must have 10 or 11 digits without dash."<<endl;
            Beep(300,500);
            cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
        }

    }while(true);
}

//get input of identity card number
void icIn()
{
    do{
            cout<<"\n\t\t\t\t\t\t\t\t\t  Please enter your Identity Card Number (010203011234): ";
            cin>>ic;
            t.setIC(ic);

        if (!isLetters(ic) && isNumbers(ic) && !isPunct(ic) && ic.size()==12)
        {
            return;
        }
        else
        {
            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, IC must have 12 digits without dash."<<endl;
            Beep(300,500);
            cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
        }

    }while(true);
}

//get the input of move in year
void yearIn()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |         Move In Date Details         |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t    Which year are you in (xxxx): ";
    cin>>year;
    t.setYear(year);

    while((year!=2021)&&(year!=2022))
    {
        if(year<=2020)
        {
            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Invalid input, please enter a valid year."<<endl;
            Beep(300,500);
            cout<<"\t\t\t\t\t\t\t\t\t\t    Please try again."<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
            cout<<"\n\t\t\t\t\t\t\t\t\t\t    Which year are you in (xxxx): ";
            cin>>year;
            t.setYear(year);
        }
        if(year>2022)
        {
            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Sorry, we are not ready for that."<<endl;
            Beep(300,500);
            cout<<"\t\t\t\t\t\t\t\t\t\t    Please try again."<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
            cout<<"\n\t\t\t\t\t\t\t\t\t\t    Which year are you in (xxxx): ";
            cin>>year;
            t.setYear(year);
        }
    }
}

//get the input of the term(month) and day
void termDayIn()
{
    do{
            cout<<"\n\t\t\t\t\t\t\t\t\t\t    Which term are you in (4,7 or 11): ";
            cin>>term;
            t.setTerm(term);

            if(term==7)
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t\t    Which day (1-31): ";
                cin>>day;
                t.setDay(day);

                while(!((day>=1) && (day<=31)))
                {
                    cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Invalid input, please enter a valid day."<<endl;
                    Beep(300,500);
                    cout<<"\t\t\t\t\t\t\t\t\t\t    Please try again."<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
                    cout<<"\n\t\t\t\t\t\t\t\t\t\t    Which day (1-31): ";
                    cin>>day;
                    t.setDay(day);
                }
            }
            else if(term==4 || term==11)
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t\t    Which day (1-30): ";
                cin>>day;
                t.setDay(day);

                while(!((day>=1) && (day<=30)))
                {
                    cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Invalid input, please enter a valid day."<<endl;
                    Beep(300,500);
                    cout<<"\t\t\t\t\t\t\t\t\t\t    Please try again."<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
                    cout<<"\n\t\t\t\t\t\t\t\t\t\t    Which day (1-30): ";
                    cin>>day;
                    t.setDay(day);
                }
            }
            else
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Invalid input, please enter a valid month."<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t\t    Choose from (4,7 or 11). "<<endl;
                Beep(300,500);
                cout<<"\t\t\t\t\t\t\t\t\t\t    Please try again."<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
                system("pause");
            }
    }while(term!=4 && term!=7 && term!=11);
}

//get the input of block, floor, room
void blockIn()
{
choose_block:

    do{
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t========================================" << endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t|                                      |"<< endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t|         ROOM DETAILS  [BLOCK]        |"<< endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t|                                      |"<< endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t========================================" << endl << endl ;
            cout<<"\t\t\t\t\t\t\t\t\t\t.----------------------------.----------------------------.\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t|           FEMALE           |            MALE            |\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t|                            |                            |\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t.----------------------------.----------------------------.\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t|   Block A | Single Rooms   |   Block C | Single Rooms   |\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t.----------------------------.----------------------------.\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t|   Block B | Single Rooms   |   Block D | Single Rooms   |\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t'----------------------------'----------------------------.\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter your choice (A,B,C or D): ";
            cin>>block;

            for (unsigned int i=0; i<block.length(); i++)
            {
                block[i] = toupper(block[i]); //change from uppercase to lowercase
            }

            t.setBlock(block);

            if(block=="a" || block=="A")
            {
                do{
                        system("cls");
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t===================================================="<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t     You have selected <Block A> as your choice    "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t===================================================="<<endl<<endl;
                        confirm=t.getConfirm();

                        if(confirm=="0")
                        {
                            goto blockA;
                        }
                        else if(confirm=="1")
                        {
                            goto choose_block;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                            system("pause");
                        }
                }while(confirm!="0" && confirm!="1");
            }
            else if(block=="b" || block=="B")
            {
                do{
                        system("cls");
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t===================================================="<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t     You have selected <Block B> as your choice    "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t===================================================="<<endl<<endl;
                        confirm=t.getConfirm();

                        if(confirm=="0")
                        {
                            goto blockB;
                        }
                        else if(confirm=="1")
                        {
                            goto choose_block;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                            system("pause");
                        }
                }while(confirm!="0" && confirm!="1");
            }
            else if(block=="c" || block=="C")
            {
                do{
                        system("cls");
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t===================================================="<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t     You have selected <Block C> as your choice    "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t===================================================="<<endl<<endl;
                        confirm=t.getConfirm();

                        if(confirm=="0")
                        {
                            goto blockC;
                        }
                        else if(confirm=="1")
                        {
                            goto choose_block;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                            system("pause");
                        }
                }while(confirm!="0" && confirm!="1");
            }
            else if(block=="d" || block=="D")
            {
                do{
                        system("cls");
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t===================================================="<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t     You have selected <Block D> as your choice    "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t===================================================="<<endl<<endl;
                        confirm=t.getConfirm();

                        if(confirm=="0")
                        {
                            goto blockD;
                        }
                        else if(confirm=="1")
                        {
                            goto choose_block;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                            system("pause");
                        }
                }while(confirm!="0" && confirm!="1");
            }
            else
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\tInvalid option. "<<endl;
                Beep(300,500);
                cout<<"\t\t\t\t\t\t\t\t\t\tChoose from (A,B,C, or D). "<<endl<<endl;
                system("pause");
                system("cls");
            }
    }while(block!="a" || block!="A" ||block!="b" || block!="B" || block!="c" || block!="C" ||block!="d" || block!="D");

blockA:

    do{
            system("cls");
            t.blockAPrint();
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter the floor (1,2,3,4,5 or 6): ";
            cin>>floor;
            t.setFloor(floor);

            if (floor==1)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (1,2,3 or 4): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=1 && room<=4)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block A-Floor 1-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockA;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2,3 or 4). "<<endl<<endl;
                        }
                }while(!((room>=1) && (room<=4)));
            }
            else if (floor==2)
            {
                do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (5,6,7 or 8): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=5 && room<=8)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block A-Floor 2-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockA;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (5,6,7 or 8). "<<endl<<endl;
                        }
                }while(!((room>=5) && (room<=8)));
            }
            else if (floor==3)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (9,10,11 or 12): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=9 && room<=12)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block A-Floor 3-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockA;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (9,10,11 or 12). "<<endl<<endl;
                        }
                }while(!((room>=9) && (room<=12)));
            }
            else if (floor==4)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (13,14,15 or 16): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=13 && room<=16)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block A-Floor 4-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockA;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (13,14,15 or 16). "<<endl<<endl;
                        }
                }while(!((room>=13) && (room<=16)));
            }
            else if (floor==5)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (17,18,19 or 20): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=17 && room<=20)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block A-Floor 5-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockA;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (17,18,19 or 20). "<<endl<<endl;
                        }
                }while(!((room>=17) && (room<=20)));
            }
            else if (floor==6)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (21,22,23 or 24): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=21 && room<=24)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block A-Floor 6-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                    goto blockA;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (21,22,23 or 24). "<<endl<<endl;
                        }
                }while(!((room>=21) && (room<=24)));
            }
            else
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                Beep(300,500);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2,3,4,5 or 6). "<<endl<<endl;
                system("pause");
                system("cls");
            }

    }while(!((floor>=1 && floor<=6)));

blockB:

    do{
            system("cls");
            t.blockBPrint();
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter the floor (1,2,3,4,5 or 6): ";
            cin>>floor;
            t.setFloor(floor);

            if (floor==1)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (1,2,3 or 4): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=1 && room<=4)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block B-Floor 1-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                    goto blockB;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2,3 or 4). "<<endl<<endl;
                        }
                }while(!((room>=1) && (room<=4)));
            }
            else if (floor==2)
            {
                do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (5,6,7 or 8): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=5 && room<=8)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block B-Floor 2-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                    goto blockB;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (5,6,7 or 8). "<<endl<<endl;
                        }
                }while(!((room>=5) && (room<=8)));
            }
            else if (floor==3)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (9,10,11 or 12): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=9 && room<=12)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block B-Floor 3-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                    goto blockB;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (9,10,11 or 12). "<<endl<<endl;
                        }
                }while(!((room>=9) && (room<=12)));
            }
            else if (floor==4)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (13,14,15 or 16): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=13 && room<=16)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block B-Floor 4-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                    goto blockB;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (13,14,15 or 16). "<<endl<<endl;
                        }
                }while(!((room>=13) && (room<=16)));
            }
            else if (floor==5)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (17,18,19 or 20): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=17 && room<=20)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block B-Floor 5-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                    goto blockB;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (17,18,19 or 20). "<<endl<<endl;
                        }
                }while(!((room>=17) && (room<=20)));
            }
            else if (floor==6)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (21,22,23 or 24): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=21 && room<=24)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block B-Floor 6-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                    goto blockB;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (21,22,23 or 24). "<<endl<<endl;
                        }
                }while(!((room>=21) && (room<=24)));
            }
            else
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                Beep(300,500);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2,3,4,5 or 6). "<<endl<<endl;
                system("pause");
                system("cls");
            }
    }while(!((floor>=1 && floor<=6)));

blockC:
    do{
            system("cls");
            t.blockCPrint();
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter the floor (1,2,3,4,5 or 6): ";
            cin>>floor;
            t.setFloor(floor);

            if (floor==1)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (1,2,3 or 4): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=1 && room<=4)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block C-Floor 1-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockC;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2,3 or 4). "<<endl<<endl;
                        }
                }while(!((room>=1) && (room<=4)));
            }
            else if (floor==2)
            {
                do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (5,6,7 or 8): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=5 && room<=8)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block C-Floor 2-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockC;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (5,6,7 or 8). "<<endl<<endl;
                        }
                }while(!((room>=5) && (room<=8)));
            }
            else if (floor==3)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (9,10,11 or 12): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=9 && room<=12)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block C-Floor 3-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockC;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (9,10,11 or 12). "<<endl<<endl;
                        }
                }while(!((room>=9) && (room<=12)));
            }
            else if (floor==4)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (13,14,15 or 16): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=13 && room<=16)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block C-Floor 4-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockC;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (13,14,15 or 16). "<<endl<<endl;
                        }
                }while(!((room>=13) && (room<=16)));
            }
            else if (floor==5)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (17,18,19 or 20): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=17 && room<=20)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block C-Floor 5-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockC;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (17,18,19 or 20). "<<endl<<endl;
                        }
                }while(!((room>=17) && (room<=20)));
            }
            else if (floor==6)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (21,22,23 or 24): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=21 && room<=24)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block C-Floor 6-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockC;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (21,22,23 or 24). "<<endl<<endl;
                        }
                }while(!((room>=21) && (room<=24)));
            }
            else
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                Beep(300,500);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2,3,4,5 or 6). "<<endl<<endl;
                system("pause");
                system("cls");
            }
    }while(!((floor>=1 && floor<=6)));

blockD:
    do{
            system("cls");
            t.blockDPrint();
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t Enter the floor (1,2,3,4,5 or 6): ";
            cin>>floor;
            t.setFloor(floor);

            if (floor==1)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (1,2,3 or 4): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=1 && room<=4)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block D-Floor 1-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockD;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2,3 or 4). "<<endl<<endl;
                        }
                }while(!((room>=1) && (room<=4)));
            }
            else if (floor==2)
            {
                do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (5,6,7 or 8): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=5 && room<=8)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block D-Floor 2-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockD;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (5,6,7 or 8). "<<endl<<endl;
                        }
                }while(!((room>=5) && (room<=8)));
            }
            else if (floor==3)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (9,10,11 or 12): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=9 && room<=12)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block D-Floor 3-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockD;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (9,10,11 or 12). "<<endl<<endl;
                        }
                }while(!((room>=9) && (room<=12)));
            }
            else if (floor==4)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (13,14,15 or 16): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=13 && room<=16)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block D-Floor 4-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockD;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (13,14,15 or 16). "<<endl<<endl;
                        }
                }while(!((room>=13) && (room<=16)));
            }
            else if (floor==5)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (17,18,19 or 20): ";
                        cin>>room;

                        if(room>=17 && room<=20)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block D-Floor 5-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockD;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (17,18,19 or 20). "<<endl<<endl;
                        }
                }while(!((room>=17) && (room<=20)));
            }
            else if (floor==6)
            {
                 do{
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t Enter the room number (21,22,23 or 24): ";
                        cin>>room;
                        t.setRoom(room);

                        if(room>=21 && room<=24)
                        {
                            do{
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                                    cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t    You have selected <Block D-Floor 6-Room "<<room<<"> as your choice"<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                                    cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                                    confirm=t.getConfirm();

                                    if(confirm=="0")
                                    {
                                        goto final_confirm;
                                    }
                                    else if(confirm=="1")
                                    {
                                        goto blockD;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t         Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t\t\t      Choose from (0 or 1). "<<endl<<endl;
                                        system("pause");
                                    }
                            }while(confirm!="0" && confirm!="1");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (21,22,23 or 24). "<<endl<<endl;
                        }
                }while(!((room>=21) && (room<=24)));
            }
            else
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                Beep(300,500);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2,3,4,5 or 6). "<<endl<<endl;
                system("pause");
                system("cls");
            }
    }while(!((floor>=1 && floor<=6)));

final_confirm:
    cout<<endl;
}

//-------------------------------------------------------------------------------------------------------------------------------------
int main(){

    Sleep(100);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\n\t\t\t\t\t\t\t\t\t\t\tL";
    Sleep(100);
    cout<<"O";
    Sleep(100);
    cout<<"A";
    Sleep(100);
    cout<<"D";
    Sleep(100);
    cout<<"I";
    Sleep(100);
    cout<<"N";
    Sleep(100);
    cout<<"G";
    Sleep(100);

    for (int i=0; i<20; i++)
    {
        cout<<".";
        Sleep(100);
    }
    system ("cls");

    Sleep(800 + rand()%250);

    system ("color F0");

    login login(opt);
    login.print();

home_page:
    do{
            opt=login.accessLogin();

            if(opt=="1")
            {

hostel_details:
                do{
                        system("cls");
                        tenantLogin tl(response, choice, choice2, choice3, choice4);
                        response=tl.getMainMenu();

                        if(response=="1")
                        {
                            goto room_info;
                        }
                        else if(response=="2")
                        {
                            goto rules;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t Choose from (1 or 2). "<<endl<<endl;
                            system("pause");
                        }
                }while(response!="1" && response!="2");

room_info:

                do{
                        system("cls");
                        tenantLogin tl(response, choice, choice2, choice3, choice4);
                        choice=tl.getRoomInfo();

                        if(choice=="1")
                        {
                            goto floorplan_single;
                        }
                        else if(choice=="2")
                        {
                            goto rental_single;
                        }
                        else
                        {
                             cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1 or 2). "<<endl<<endl;
                            system("pause");
                            system("cls");
                        }
                }while(choice!="1" && choice!="2");


floorplan_single:

                do{
                        system("cls");
                        tenantLogin tl(response, choice, choice2, choice3, choice4);
                        choice2=tl.getSingleRoom();

                        if(choice2=="1")
                        {
                            goto rental_single;
                        }
                        else if(choice2=="2")
                        {
                            goto hostel_details;
                        }
                        else if(choice2=="3")
                        {
                            goto home_page;
                        }
                        else{
                             cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2 or 3). "<<endl<<endl;
                            system("pause");
                            system("cls");
                        }
                }while(choice2!="1" && choice2!="2" && choice2!="3");

rental_single:

                do{
                        system("cls");
                        tenantLogin tl(response, choice, choice2, choice3, choice4);
                        choice3=tl.getRentalSingle();

                        if(choice3=="1")
                        {
                            goto floorplan_single;
                        }
                        else if(choice3=="2")
                        {
                            goto hostel_details;
                        }
                        else if(choice3=="3")
                        {
                            goto home_page;
                        }
                        else
                        {
                             cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t Choose from (1,2 or 3). "<<endl<<endl;
                            system("pause");
                            system("cls");
                        }
                }while(choice3!="1" && choice3!="2" && choice3!="3");

rules:

                do{
                        system("cls");
                        tenantLogin tl(response, choice, choice2, choice3, choice4);
                        choice4=tl.getRules();

                        if(choice4=="1")
                        {
                            goto room_info;
                        }
                        else if(choice4=="2")
                        {
                            goto hostel_details;
                        }
                        else if(choice4=="3")
                        {
                            goto home_page;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t            Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t            Choose from (1,2 or 3). "<<endl<<endl;
                            system("pause");
                            system("cls");
                        }
                }while(choice4!="1" && choice4!="2" && choice4!="3");
            }
            else if(opt=="2")
            {
                readfile();
                do{
                    do{

                        system("cls");
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t  |         Administrator Access         |"<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl<<endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t    _ _ _ _ _ _ _ _ _ _ "  << endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   |                    |"  << endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   |   Tenant Record    |"  << endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   |_ _ _ _ _ _ _ _ _ _ |"  << endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   |                    |  "<< endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   | 1. Add Record      |  "<< endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   | 2. Edit Record     |  "<< endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   | 3. Delete Record   |  "<< endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   | 4. View Record     |  "<< endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   | 5. Search Record   |  "<< endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   | 6. Sort Record     |  "<< endl;
                        cout <<"\t\t\t\t\t\t\t\t\t\t\t   |_ _ _ _ _ _ _ _ _ _ |  "<< endl;
                        cout <<"\n\t\t\t\t\t\t\t\t\t\t  PLease enter your choice (1,2,3,4,5 or 6): ";
                        cin >>record;

                        if (record=="1")
                        {
                            addRecord();
                        }
                        else if(record=="2")
                        {
                            do{
                                    system("cls");
                                    verifyEdit();
                                    cout<<"\n\t\t\t\t\t\t\t\t       Do you want to continue editing (Y/N): ";
                                    cin>>answer2;
                                    system("cls");

                            }while(answer2=='Y' || answer2=='y');
                        }
                        else if(record=="3")
                        {
                            delRecord();
                        }
                        else if(record=="4")
                        {
                            viewRecord(data);
                            system("pause");
                        }
                        else if(record=="5")
                        {
                            system("cls");
                            searchRecord();
                            system("pause");
                        }
                        else if(record=="6")
                        {
                            sortRecord();
                            system("pause");
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t\t  Choose from (1,2,3,4,5 or 6). "<<endl<<endl;
                            system("pause");
                            system("cls");
                        }
                    }while(record!="1" && record!="2" && record!="3" && record!="4" && record!="5" && record!="6");


                        system("cls");
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t               Do you want go back to tenant record?"<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;

                        cout<<"\t\t\t\t\t\t\t\t\t\t        --  To proceed, please enter (Y)   -- "<< endl;
                        cout<<"\t\t\t\t\t\t\t\t\t\t      --  To main menu, please enter (N)  -- "<< endl;
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t   Your choice: ";
                        cin>>answer3;

                }while(answer3=='Y' || answer3=='y');

                if(answer3=='N' || answer3=='n')
                {
                    writefile();
                    goto home_page;
                }
            }
            else if(opt=="3")
            {
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
                cout<<"\n\t\t\t\t\t\t\t\t\t================================================================="<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t               Thank you and have a nice day ^-^ "<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t                                                   "<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl;
                exit(0);
            }
            else
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t       Invalid option. "<<endl;
                Beep(300,500);
                cout<<"\t\t\t\t\t\t\t\t\t\t\t       Choose from (1, 2 or 3). "<<endl<<endl;
                system("pause");
                system("cls");
            }
    }while(opt!="1" && opt!="2" && opt!="3");
}


//--------------------------------------------add tenant function------------------------------------------------------------------
void addRecord()
{
    do{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |              Add Tenant              |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  |                                      |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ========================================"<<endl<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t    Enter name: ";
    cin.ignore();
    getline(cin,name);

    for (unsigned int i=0; i<name.length(); i++)
    {
        name[i] = toupper(name[i]); //change from uppercase to lowercase
    }
    t.setName(name);

    cout<<"\n\t\t\t\t\t\t\t\t\t\t    Enter your gender (M/F): ";
    cin>>gender;

    for (unsigned int i=0; i<gender.length(); i++)
    {
        gender[i] = toupper(gender[i]); //change from uppercase to lowercase
    }
    t.setGender(gender);

    while(gender!="m" && gender!="M" && gender!="f" && gender!="F")
    {
        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Invalid option. "<<endl;
        Beep(300,500);
        cout<<"\t\t\t\t\t\t\t\t\t\t    Choose from (M,m or F,f). "<<endl<<endl<<"\t\t\t\t\t"<<l<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t    Enter your gender (M/F): ";
        cin>>gender;

        for (unsigned int i=0; i<gender.length(); i++)
        {
            gender[i] = toupper(gender[i]); //change from uppercase to lowercase
        }
        t.setGender(gender);
    }

    t.bookingInfoPrint();
    stuidIn();
    phoneNoIn();
    icIn();
    yearIn();
    termDayIn();
    blockIn();

    do{
            cout<<"\t\t\t\t\t"<<l<<"\n\t\t\t\t\t\t\t\t\t\t    Do you confirm all the information (Y/N): ";
            cin>>r;
            if(r=='Y' || r=='y')
            {
                data.push_back(t);
            }
            else if(r=='N' || r=='n')
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    No tenant added.";
            }
            else
            {
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Invalid option. "<<endl;
                Beep(300,500);
                cout<<"\t\t\t\t\t\t\t\t\t\t    Choose from (Y,y or N,n). "<<endl<<endl<<"\t\t\t\t\t"<<endl;
            }
    }while(r!='Y' && r!='y' && r!='N' && r!='n');

            cout<<endl<<"\n\t\t\t\t\t\t\t\t\t\t    Do you want to add new tenant (Y/N): ";
            cin>>answer;
            system("cls");

    }while(answer=='Y' || answer=='y'); //continue
}

//----------------------------------------------------------delete record function--------------------------------------------------------
void delRecord()
{
    do{
            viewRecord(data); //display record before deletion

            cout<<"\n\n\t\t\t\t\t\t\t\t       Please enter the tenant name to delete: ";
            cin.ignore();
            getline(cin,name);

            for (unsigned int i=0; i<name.length(); i++)
            {
                name[i] = toupper(name[i]); //change from lowercase to uppercase
            }

            bool noThisTenant=true;
            for(unsigned int i=0; i<data.size(); i++)
            {
                if (data[i].getName()==name)
                {
                    c=i;
                    noThisTenant=false;
                }
            }

            if (!noThisTenant)
            {
                data.erase(data.begin()+c); //delete specific tenant
                viewRecord(data); //display record after deletion

                cout<<"\n\n\t\t\t\t\t\t\t\t================================================================="<<endl;
                cout<<"\t\t\t\t\t\t\t\t                                                   "<<endl;
                cout<<"\t\t\t\t\t\t\t\t               Tenant record has been deleted "<<endl;
                cout<<"\t\t\t\t\t\t\t\t                                                   "<<endl;
                cout<<"\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl<<endl;
                system("pause");
            }
            else
            {
                cout<<"\n\t\t\t\t\t\t\t\t       Sorry, we don't have that tenant in the hostel."<<endl;
            }

            cout<<"\n\t\t\t\t\t\t\t\t       Do you want to make another deletion (Y/N): ";
            cin>>answer;
            system("cls");

    }while(answer=='Y' || answer=='y'); //continue
}

//---------------------------------------------------------edit record function---------------------------------------------------------
void verifyEdit()
{
        viewRecord(data);
        cout<<"\n\n\t\t\t\t\t\t\t\t       Please enter the tenant name to edit: ";
        cin.ignore();
        getline(cin,name);

        for (unsigned int i=0; i<name.length(); i++)
        {
            name[i] = toupper(name[i]); //change from lowercase to uppercase
        }

        bool noThisTenant=true;
        for(unsigned int i=0; i<data.size(); i++)
        {
            if (name==data[i].getName())
            {
                c=i; //point to specific tenant to edit
                noThisTenant=false;
            }
        }

        if (!noThisTenant)
        {
            searchByName(name); //display specific tenant data
            editRecord();
            printEdit(data);
        }
        else
        {
            cout<<"\n\t\t\t\t\t\t\t\t       Sorry, we don't have that tenant in the hostel."<<endl;
        }
}

void editRecord()
{
     do{
            cout<<"\n\n\t\t\t\t\t\t\t\t\t            _____\n";
            cout<<"\t\t\t\t\t\t\t\t\t           /     \\   ____   ____    __ __\n";
            cout<<"\t\t\t\t\t\t\t\t\t          /  \\ /  \\_/ __ \\ /     \\ |  |  |\n";
            cout<<"\t\t\t\t\t\t\t\t\t         /    Y    \\  ___/|   |   \\|  |  |\n";
            cout<<"\t\t\t\t\t\t\t\t\t         \\____|____/\\____>____|____|_____| \n\n";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t        1. Edit Name";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t        2. Edit Student ID";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t        3. Edit Gender";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t        4. Edit Phone Number";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t        5. Edit Identity Card (IC)";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t        6. Edit Room No";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t        7. Edit Move In Date";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t  Please enter your option to proceed (1,2,3,4,5,6 or 7): ";
            cin>>response2;

            if(response2=="1")
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new tenant name: ";
                cin.ignore();
                getline(cin,name);

                for (unsigned int i=0; i<name.length(); i++)
                {
                    name[i] = toupper(name[i]); //change from lowercase to uppercase
                }
                data[c].setName(name);
            }
            else if(response2=="2")
            {
                do{
                        cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new student ID (1191100123): ";
                        cin>>id;
                        data[c].setStuid(id);

                        if (!isLetters(id) && isNumbers(id) && !isPunct(id) && id.size()==10)
                        {
                            return;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, Student ID must have 10 digits without dash and space."<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                        }
                }while(true);
            }
            else if(response2=="3")
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new gender (M/F): ";
                cin>>gender;

                for (unsigned int i=0; i<gender.length(); i++)
                {
                    gender[i] = toupper(gender[i]); //change from uppercase to lowercase
                }
                data[c].setGender(gender);

                while(gender!="m" && gender!="M" && gender!="f" && gender!="F")
                {
                    cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                    Beep(300,500);
                    cout<<"\t\t\t\t\t\t\t\t\t  Choose from (M,m or F,f). "<<endl<<endl<<"\t\t\t   "<<l<<endl;
                    cout<<"\n\t\t\t\t\t\t\t\t\t  Enter your gender (M/F): ";
                    cin>>gender;

                    for (unsigned int i=0; i<gender.length(); i++)
                    {
                        gender[i] = toupper(gender[i]); //change from uppercase to lowercase
                    }
                    data[c].setGender(gender);
                }
            }
            else if(response2=="4")
            {
                do{
                        cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new phone number (01110345678): ";
                        cin>>phoneNo;
                        data[c].setPhoneNo(phoneNo);

                        if (!isLetters(phoneNo) && isNumbers(phoneNo) && !isPunct(phoneNo) && phoneNo.size()>=10 && phoneNo.size()<=11)
                        {
                            return;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, phone number must have 10 or 11 digits without dash."<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                        }
                }while(true);
            }
            else if(response2=="5")
            {
                do{
                        cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new Identity Card Number (010203011234): ";
                        cin>>ic;
                        data[c].setIC(ic);

                        if (!isLetters(ic) && isNumbers(ic) && !isPunct(ic) && ic.size()==12)
                        {
                            return;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, IC must have 12 digits without dash."<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                        }
                }while(true);
            }
            else if(response2=="6")
            {
                do{
                        cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new block (A,B,C or D): ";
                        cin>>block;

                        for (unsigned int i=0; i<block.length(); i++)
                        {
                            block[i] = toupper(block[i]); //change from uppercase to lowercase
                        }
                        data[c].setBlock(block);

                        if(block!="a" || block!="A" ||block!="b" || block!="B" || block!="c" || block!="C" ||block!="d" || block!="D")
                        {
                            goto block;
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t  Choose from (A,B,C, or D). "<<endl;
                            cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                        }
                }while(block!="a" || block!="A" ||block!="b" || block!="B" || block!="c" || block!="C" ||block!="d" || block!="D");

            block:

                do{
                        cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new floor (1,2,3,4,5 or 6): ";
                        cin>>floor;
                        data[c].setFloor(floor);

                        if (floor==1)
                        {
                            do{
                                    cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new room number (1,2,3 or 4): ";
                                    cin>>room;
                                    data[c].setRoom(room);

                                    if(room>=1 && room<=4)
                                    {
                                        goto final_confirm;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t  Choose from (1,2,3 or 4). "<<endl;
                                        cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                                    }
                            }while(!((room>=1) && (room<=4)));
                        }
                        else if (floor==2)
                        {
                            do{
                                    cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new room number (5,6,7 or 8): ";
                                    cin>>room;
                                    data[c].setRoom(room);

                                    if(room>=5 && room<=8)
                                    {
                                        goto final_confirm;

                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t  Choose from (5,6,7 or 8). "<<endl;
                                        cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                                    }
                            }while(!((room>=5) && (room<=8)));
                        }
                        else if (floor==3)
                        {
                            do{
                                    cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new room number (9,10,11 or 12): ";
                                    cin>>room;
                                    data[c].setRoom(room);

                                    if(room>=9 && room<=12)
                                    {
                                        goto final_confirm;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t  Choose from (9,10,11 or 12). "<<endl;
                                        cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                                    }
                            }while(!((room>=9) && (room<=12)));
                        }
                        else if (floor==4)
                        {
                            do{
                                    cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new room number (13,14,15 or 16): ";
                                    cin>>room;
                                    data[c].setRoom(room);

                                    if(room>=13 && room<=16)
                                    {
                                        goto final_confirm;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t  Choose from (13,14,15 or 16). "<<endl;
                                        cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                                    }
                            }while(!((room>=13) && (room<=16)));
                        }
                        else if (floor==5)
                        {
                            do{
                                    cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new room number (17,18,19 or 20): ";
                                    cin>>room;
                                    data[c].setRoom(room);

                                    if(room>=17 && room<=20)
                                    {
                                        goto final_confirm;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t  Choose from (17,18,19 or 20). "<<endl;
                                        cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                                    }
                            }while(!((room>=17) && (room<=20)));
                        }
                        else if (floor==6)
                        {
                             do{
                                    cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new room number (21,22,23 or 24): ";
                                    cin>>room;
                                    data[c].setRoom(room);

                                    if(room>=21 && room<=24)
                                    {
                                        goto final_confirm;
                                    }
                                    else
                                    {
                                        cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                                        Beep(300,500);
                                        cout<<"\t\t\t\t\t\t\t\t\t  Choose from (21,22,23 or 24). "<<endl;
                                        cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                                    }
                            }while(!((room>=21) && (room<=24)));
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t  Choose from (1,2,3,4,5 or 6). "<<endl;
                            cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                        }
                }while(!((floor>=1 && floor<=6)));

            final_confirm: cout<<endl;
            }
            else if(response2=="7")
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new move in year (xxxx): ";
                cin>>year;
                data[c].setYear(year);

                while((year!=2021)&&(year!=2022))
                {
                    if(year<=2020)
                    {
                        cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, please enter a valid year."<<endl;
                        Beep(300,500);
                        cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                        cout<<"\n\t\t\t\t\t\t\t\t\t  Which year are you in (xxxx): ";
                        cin>>year;
                        data[c].setYear(year);
                    }
                    if(year>2022)
                    {
                        cout<<endl<<"\t\t\t\t\t\t\t\t\t  Sorry, we are not ready for that."<<endl;
                        Beep(300,500);
                        cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                        cout<<"\n\t\t\t\t\t\t\t\t\t  Which year are you in (xxxx): ";
                        cin>>year;
                        data[c].setYear(year);
                    }
                }

                do{
                        cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new move in term (4,7 or 11): ";
                        cin>>term;
                        data[c].setTerm(term);

                        if(term==7)
                        {
                            cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new move in day (1-31): ";
                            cin>>day;
                            data[c].setDay(day);

                            while(!((day>=1) && (day<=31)))
                            {
                                cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, please enter a valid day."<<endl;
                                Beep(300,500);
                                cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                                cout<<"\n\t\t\t\t\t\t\t\t\t  Which day (1-31): ";
                                cin>>day;
                                data[c].setDay(day);
                            }
                        }
                        else if(term==4 || term==11)
                        {
                            cout<<"\n\t\t\t\t\t\t\t\t\t  Enter a new move in day (1-30): ";
                            cin>>day;
                            data[c].setDay(day);

                            while(!((day>=1) && (day<=30)))
                            {
                                cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid input, please enter a valid day."<<endl;
                                Beep(300,500);
                                cout<<"\t\t\t\t\t\t\t\t\t  Please try again."<<endl<<endl<<"\t\t\t   "<<l<<endl;
                                cout<<"\n\t\t\t\t\t\t\t\t\t  Which day (1-30): ";
                                cin>>day;
                                data[c].setDay(day);
                            }
                        }
                        else
                        {
                            cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid option. "<<endl;
                            Beep(300,500);
                            cout<<"\t\t\t\t\t\t\t\t\t  Choose from (4,7 or 11). "<<endl<<endl;
                            system("pause");
                        }
                }while(term!=4 && term!=7 && term!=11);
            }
            else
            {
                Beep(300,500);
                cout<<endl<<"\t\t\t\t\t\t\t\t\t  Invalid Input. "<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t  Choose from (1,2,3,4,5,6 or 7). "<<endl<<endl;
                system("pause");
                system("cls");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
            }
        }while(response2!="1" && response2!="2" && response2!="3" && response2!="4" && response2!="5" && response2!="6" && response2!="7");
}

void printEdit(vector<tenant>& data)
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t     ___________________________________________________________________________________________________________________________________ "<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |     Tenant Name     |          IC          |  Gender  |     Student ID     |      Phone No.     |   Room No.   |   Move in Date   |"<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |"<<"     "<<data[c].getName()<<setw(1)<<"\t\t"
                                <<data[c].getIC()<<"\t      "
                                <<data[c].getGender()<<"\t         "
                                <<data[c].getStuid()<<"\t      "
                                <<data[c].getPhoneNo()<<"\t   "
                                <<data[c].getBlock()<<"-"<<data[c].getFloor()<<"-"<<data[c].getRoom()<<"\t  "
                                <<data[c].getDay()<<"/"<<data[c].getTerm()<<"/"<<data[c].getYear()<<endl;
    cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;

}

//-------------------------------------------------------display function-------------------------------------------------------------------
void viewRecord(vector<tenant>& data)
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t     ___________________________________________________________________________________________________________________________________ "<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |     Tenant Name     |          IC          |  Gender  |     Student ID     |      Phone No.     |   Room No.   |   Move in Date   |"<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;

    for(unsigned int i=0; i<data.size(); i++)
    {
            cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
            cout<<"\t\t\t    |"<<"     "<<data[i].getName()<<setw(1)<<"\t\t"
                                        <<data[i].getIC()<<"\t      "
                                        <<data[i].getGender()<<"\t         "
                                        <<data[i].getStuid()<<"\t      "
                                        <<data[i].getPhoneNo()<<"\t   "
                                        <<data[i].getBlock()<<"-"<<data[i].getFloor()<<"-"<<data[i].getRoom()<<"\t  "
                                        <<data[i].getDay()<<"/"<<data[i].getTerm()<<"/"<<data[i].getYear()<<endl;
            cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;
    }
}

//-----------------------------------------------------searching function--------------------------------------------------------------
void searchRecord()
{
    do{
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t            _____\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t           /     \\   ____   ____    __ __\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t          /  \\ /  \\_/ __ \\ /     \\ |  |  |\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t         /    Y    \\  ___/|   |   \\|  |  |\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t         \\____|____/\\____>____|____|_____| \n\n";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       1. Search by Name";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       2. Search by student ID";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       3. Search by Block";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       4. Search by Move In Date";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t    Please enter your option to proceed (1,2,3 or 4): ";
            cin>>response2;

            if(response2=="1")
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t\t    Enter name: ";
                cin.ignore();
                getline(cin,name);

                for (unsigned int i=0; i<name.length(); i++)
                {
                    name[i] = toupper(name[i]); //change from lowercase to uppercase
                }

                searchByName(name);
            }
            else if(response2=="2")
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t\t    Enter student ID (1191100123): ";
                cin>>id;
                searchByStuid(id);
            }
            else if(response2=="3")
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t\t    Enter block (A,B,C or D): ";
                cin>>block;

                for (unsigned int i=0; i<block.length(); i++)
                {
                    block[i] = toupper(block[i]); //change from uppercase to lowercase
                }

                searchByBlock(block);
            }
            else if(response2=="4")
            {
                cout<<"\n\t\t\t\t\t\t\t\t\t\t    Enter move in date (DD MM YYYY): ";
                cin>>day>>term>>year;
                searchByDate(day, term, year);
            }
            else
            {
                Beep(300,500);
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Invalid Input. "<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t\t    Choose from (1,2,3 or 4). "<<endl<<endl;
                system("pause");
                system("cls");
            }
        }while(response2!="1" && response2!="2" && response2!="3" && response2!="4");
}

void searchByName(string name)
{
    stack<tenant> myStack;

    for(unsigned int i=0; i<data.size(); i++)
    {
        if(name==data[i].getName())
        {
            myStack.push(data[i]);
        }
    }
    if(myStack.empty())
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t    Sorry, no tenant is found."<<endl;
    }
    else
    {
        printSearch(myStack);
    }
}

void searchByStuid(string id)
{
    stack<tenant> myStack;

    for(unsigned int i=0; i<data.size(); i++)
    {
        if(id==data[i].getStuid())
        {
            myStack.push(data[i]);
        }
    }
    if(myStack.empty())
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t    Sorry, no tenant is found."<<endl;
    }
    else
    {
        printSearch(myStack);
    }
}

void searchByBlock(string block)
{
    stack<tenant> myStack;

    for(unsigned int i=0; i<data.size(); i++)
    {
        if(block==data[i].getBlock())
        {
            myStack.push(data[i]);
        }
    }
    if(myStack.empty())
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t    Sorry, no tenant has been added or invalid block entered."<<endl;
    }
    else
    {
        printSearch(myStack);
    }
}

void searchByDate(int day, int term, int year)
{
    stack<tenant> myStack;

    for(unsigned int i=0; i<data.size(); i++)
    {
        if(day==data[i].getDay() && term==data[i].getTerm() && year==data[i].getYear())
        {
            myStack.push(data[i]);
        }
    }
    if(myStack.empty())
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t    Sorry, no tenant has been added."<<endl;
    }
    else
    {
        printSearch(myStack);
    }
}

void printSearch(stack<tenant> myStack)
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t     ___________________________________________________________________________________________________________________________________ "<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |     Tenant Name     |          IC          |  Gender  |     Student ID     |      Phone No.     |   Room No.   |   Move in Date   |"<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;

    while(!myStack.empty()){
            cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
            cout<<"\t\t\t    |"<<"     "<<myStack.top().getName()<<setw(1)<<"\t\t"
                                        <<myStack.top().getIC()<<"\t      "
                                        <<myStack.top().getGender()<<"\t         "
                                        <<myStack.top().getStuid()<<"\t      "
                                        <<myStack.top().getPhoneNo()<<"\t   "
                                        <<myStack.top().getBlock()<<"-"<<myStack.top().getFloor()<<"-"<<myStack.top().getRoom()<<"\t  "
                                        <<myStack.top().getDay()<<"/"<<myStack.top().getTerm()<<"/"<<myStack.top().getYear()<<endl;
            cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;
            myStack.pop();
    };
}

//---------------------------------------------------------------------sorting-----------------------------------------------
void sortRecord(){
    do{
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t            _____\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t           /     \\   ____   ____    __ __\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t          /  \\ /  \\_/ __ \\ /     \\ |  |  |\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t         /    Y    \\  ___/|   |   \\|  |  |\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t         \\____|____/\\____>____|____|_____| \n\n";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       1. Sort by Name";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       2. Sort by student ID";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       3. Sort by Block";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t       4. Sort by Move In Date";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t    Please enter your option to proceed (1,2,3 or 4): ";
            cin>>response3;

            if(response3=="1")
            {
                sortByName(data);
            }
            else if(response3=="2")
            {
                sortByStuid(data);
            }
            else if(response3=="3")
            {
                sortByBlock(data);
            }
            else if(response3=="4")
            {
                sortByDate(data);
            }
            else
            {
                Beep(300,500);
                cout<<endl<<"\t\t\t\t\t\t\t\t\t\t    Invalid Input. "<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t\t    Choose from (1,2, 3 or 4). "<<endl<<endl;
                system("pause");
            }
        }while(response3!="1" && response3!="2" && response3!="3" && response3!="4");
}

void swap(tenant& x, tenant& y){
   tenant temp = x;
   x = y;
   y = temp;
}

void sortByName(vector<tenant>& data){
    string tmp;

    for (unsigned int i = 0; i < data.size() ; i++)
    {
        bool swapped = false;

        for (unsigned int j = 0 ; j < data.size()-1 ; j++)
        {
            if (data[j+1].getName() < data[j].getName())
            {
                swap(data[j+1],data[j]);
                swapped=true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    queue<tenant> myQueue;
    for(unsigned i=0; i<data.size(); ++i)
	{
		myQueue.push(data[i]);
	}

    if(myQueue.empty())
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\t    Sorry, no tenant has been added."<<endl;
    }
    else
    {
        printSort(myQueue);
    }
}

void sortByStuid(vector<tenant>& data){
    string tmp;

    for (unsigned int i = 0; i < data.size() ; i++)
    {
        bool swapped = false;

        for (unsigned int j = 0 ; j < data.size()-1 ; j++)
        {
            if (data[j+1].getStuid() < data[j].getStuid())
            {
                swap(data[j+1],data[j]);
                swapped=true;
            }
        }
        if (!swapped)
        {
            break;
        }
   }

    queue<tenant> myQueue;
    for (unsigned i=0; i<data.size(); ++i)
	{
		myQueue.push(data[i]);
	}

    if(myQueue.empty())
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\t    Sorry, no tenant has been added."<<endl;
    }
    else
    {
        printSort(myQueue);
    }
}

void sortByBlock(vector<tenant>& data){
    string tmp;

    for (unsigned int i = 0; i < data.size() ; i++)
    {
        bool swapped = false;

        for (unsigned int j = 0 ; j < data.size()-1 ; j++)
        {
            if (data[j+1].getRoom() < data[j].getRoom())
            {
                swap(data[j+1],data[j]);
                swapped=true;
            }

            if (data[j+1].getFloor() < data[j].getFloor())
            {
                swap(data[j+1],data[j]);
                swapped=true;
            }

            if (data[j+1].getBlock() < data[j].getBlock())
            {
                swap(data[j+1],data[j]);
                swapped=true;
            }

        }
        if (!swapped)
        {
            break;
        }
   }

    queue<tenant> myQueue;
    for (unsigned i=0; i<data.size(); ++i)
	{
		myQueue.push(data[i]);
	}

    if(myQueue.empty())
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\t    Sorry, no tenant has been added."<<endl;
    }
    else
    {
        printSort(myQueue);
    }
}

void sortByDate(vector<tenant>& data){
    string tmp;

    for (unsigned int i = 0; i < data.size() ; i++)
    {
        bool swapped = false;

        for (unsigned int j = 0 ; j < data.size()-1 ; j++)
        {
            if (data[j+1].getDay() < data[j].getDay())
            {
                swap(data[j+1],data[j]);
                swapped=true;
            }

            if (data[j+1].getTerm() < data[j].getTerm())
            {
                swap(data[j+1],data[j]);
                swapped=true;
            }

            if (data[j+1].getYear() < data[j].getYear())
            {
                swap(data[j+1],data[j]);
                swapped=true;
            }
        }
        if (!swapped)
        {
            break;
        }
   }

    queue<tenant> myQueue;
    for (unsigned i=0; i<data.size(); ++i)
	{
		myQueue.push(data[i]);
	}

    if(myQueue.empty())
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\t    Sorry, no tenant has been added."<<endl;
    }
    else
    {
        printSort(myQueue);
    }
}

void printSort(queue<tenant> myQueue)
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t     ___________________________________________________________________________________________________________________________________ "<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |     Tenant Name     |          IC          |  Gender  |     Student ID     |      Phone No.     |   Room No.   |   Move in Date   |"<<endl;
    cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
    cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;

    while(!myQueue.empty()){
            cout<<"\t\t\t    |                     |                      |          |                    |                    |              |                  |"<<endl;
            cout<<"\t\t\t    |"<<"     "<<myQueue.front().getName()<<setw(1)<<"\t\t"
                                        <<myQueue.front().getIC()<<"\t      "
                                        <<myQueue.front().getGender()<<"\t         "
                                        <<myQueue.front().getStuid()<<"\t      "
                                        <<myQueue.front().getPhoneNo()<<"\t   "
                                        <<myQueue.front().getBlock()<<"-"<<myQueue.front().getFloor()<<"-"<<myQueue.front().getRoom()<<"\t  "
                                        <<myQueue.front().getDay()<<"/"<<myQueue.front().getTerm()<<"/"<<myQueue.front().getYear()<<endl;
            cout<<"\t\t\t    |_____________________|______________________|__________|____________________|____________________|______________|__________________|"<<endl;
            myQueue.pop();
    };
}
