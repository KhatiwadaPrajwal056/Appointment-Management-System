#include <iostream>
#include <stdio.h> //standard input output
#include <fstream>
#include <stdlib.h> //for rand() fflush
#include <conio.h>  //console input output
#include <string.h>
#include <windows.h> //for sleep
#include <iomanip>   //manipulate the output of C++
#include <time.h>    //manipulte date and time info

using namespace std;
int password(); // b
void menu();    // c
void show();    // a Table header list
class Patient
{
    int age;
    int temperature;
    int bloodPressure;
    char gender;
    char name[100];
    char citizenship[100];
    char profession[100];
    char address[100];
    char mobileNumber[100];

public:
    void setData();          // 1  Use this to set data on the record
    void addNew();           // 2   To add the record given within setData()-1 funtion and print successfully recorded
    void showData();         // 3 This is to show the whole data which is recorded within the file given from setData()
    void showList();         // 4 This is the data to call for the table data Note: not the table header
    void viewAppointments(); // 5 //Gives the number of appointments remaining -- Or we can add it
    void searchData();       // 6  Search the data option to get to a list to from which data type to search
    void modify();           // 7
    void view_all();         // 8
    void del();              // 9

    void search_by_citizenship(); // 6.1
    void search_by_age();         // 6.2
    void search_by_profession();  // 6.3
    void search_by_gender();      // 6.4
};
//----------------------------------------
void Patient::setData() // 1
{
    int n;

    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 APPOINTMENT MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<< endl;
    cout << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t ENTER THE DETAILS ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cout<<"/t/t 1 Morning shift  ";
    cout<<"/t/t 1 Day shift  ";
    cout<<"/t/t 1 Evening shift  ";
    cout<<"Enter the Time shift ";
    cin>>n;
    switch (n)
    {
    case 1:
        cout << "\n\t\t Enter your name :-  ";
        gets(name);
        cout << "\n\t\t Enter your citizenship no :-  ";
        gets(citizenship);
        cout << "\n\t\t Enter your gender (M|F) :-  ";
        cin >> gender;
        cout << "\n\t\t Enter your age:- ";
        cin >> age;
        fflush(stdin);
        cout << "\n\t\t Enter your profession :-  ";
        gets(profession);
        cout << "\n\t\t Enter your permanent address :-  ";
        gets(address);
        cout << "\n\t\t Enter your Mobile number :- ";
        gets(mobileNumber);
        break;
    case 2:
        cout << "\n\t\t Enter your name :-  ";
        gets(name);
        cout << "\n\t\t Enter your citizenship no :-  ";
        gets(citizenship);
        cout << "\n\t\t Enter your gender (M|F) :-  ";
        cin >> gender;
        cout << "\n\t\t Enter your age:- ";
        cin >> age;
        fflush(stdin);
        cout << "\n\t\t Enter your profession :-  ";
        gets(profession);
        cout << "\n\t\t Enter your permanent address :-  ";
        gets(address);
        cout << "\n\t\t Enter your Mobile number :- ";
        gets(mobileNumber);
        break;
        
    case 3:
        cout << "\n\t\t Enter your name :-  ";
        gets(name);
        cout << "\n\t\t Enter your citizenship no :-  ";
        gets(citizenship);
        cout << "\n\t\t Enter your gender (M|F) :-  ";
        cin >> gender;
        cout << "\n\t\t Enter your age:- ";
        cin >> age;
        fflush(stdin);
        cout << "\n\t\t Enter your profession :-  ";
        gets(profession);
        cout << "\n\t\t Enter your permanent address :-  ";
        gets(address);
        cout << "\n\t\t Enter your Mobile number :- ";
        gets(mobileNumber);
        break;
    default:
        cout<<"Enter valid shift for the appointment ";
        break;
    }
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t-------------------***************-------------------------\n\n";
    Patient::showData();
    cout << "\n\n\t\t\t\t\t\t\t\t\t-------------------***************-------------------------";
}

void Patient::addNew() // 2
{
    fstream outin;
    outin.open("app.dat", ios::app | ios::out | ios::binary); // ios::out to write means to add the setData() recorded within a vaccinetrial.txt file
    setData();
    outin.write((char *)this, sizeof(Patient));
    cout << "\n\n\t\t\t\t\t\t\t\t\t---------YOUR DATA HAS BEEN SUCCESSFULLY INSERTED--------- " << endl;
    getch();
    outin.close();
}

void Patient::showData() // 3
{
    cout << "\n\t\t\t\t\t\t\t\t\t*****************************************\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\tPatient Details  ";
    cout << "\n\t\t\t\t\t\t\t\t\t*****************************************\n\n";
    cout << "\t\t\t\t\t\t\t\t\t Name : " << name << endl;
    cout << "\t\t\t\t\t\t\t\t\t Citizenship number : " << citizenship << endl;
    cout << "\t\t\t\t\t\t\t\t\t Your age  " << age << endl;
    cout << "\t\t\t\t\t\t\t\t\t Profession  : " << profession << endl;
    cout << "\t\t\t\t\t\t\t\t\t Gender  : " << gender << endl;
    cout << "\t\t\t\t\t\t\t\t\t Address : " << address << endl;
    cout << "\t\t\t\t\t\t\t\t\t Mobile number : " << mobileNumber << endl;
}
//------------------------------------------
void Patient::showList() // 4 assigns each records in the table list after the header given by show()
{
    cout << "\n";
    cout << setw(20) << setiosflags(ios::left) << name;
    cout << setw(20) << citizenship;
    cout << setw(15) << age;
    cout << setw(15) << profession;
    cout << setw(15) << gender;
    cout << setw(15) << mobileNumber;
    cout << setw(15) << address;
}

void Patient::searchData() // 6 menu when you enter search
{
    Patient item;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3  APPOINTMENT MANAGEMENT SYSTEM    \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;
    cout << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\tSEARCHING STATISTICS";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "From which option you want to perform searching " << endl;
    cout << "\n\t\t 1. By Citizenship No. \t\t\t 2. By Age " << endl;
    cout << "\n\t\t 3. By Profession \t\t\t 4. By Gender " << endl;
    cout << "\n\t\t\t\t 5. Back to Main Menu " << endl;
    cout << "\n\n\t\tEnter your choice : ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        search_by_citizenship();
        getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        getch();
        break;
    case 3:
        system("cls");
        search_by_profession();
        getch();
        break;
    case 4:
        system("cls");
        search_by_gender();
        getch();
        break;
    case 5:
        system("cls");
        menu();
        break;

    default:
        system("cls");
        cout << "ENTER VALID OPTION" << endl;
        menu();
    }
}
//------------------------------------------------
void Patient::search_by_citizenship() // 6.1
{
    ifstream in; // read garna kholeko from file
    in.open("app.dat");
    int flag, p = 0; // p for vaccine count and flag for the proper operation
    char cs[100];
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3  APPOINTMENT MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;
    cout << "\t\t\t\t\t\t Powered By:- TEAM ACDC " << endl
         << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t Searching Citizenship.... ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter your Citizenship number: " << endl;
    fflush(stdin);
    gets(cs);

    while (!in.eof())
    {
        if (in.read(reinterpret_cast<char *>(this), sizeof(*this)) > 0)
        {

            if (strcmp(cs, citizenship) == 0)
            {
                cout << "\n\nSearching.";
                for (int i = 0; i <= 10; i++)
                {
                    cout << ".";
                    Sleep(100);
                }

                show();     // table header list while showing data
                showList(); // table header bhanda tala ko data
                flag = 1;
                p++;
            }
        }
    }
    if (flag = 0)
    {
        cout << "Citizenship you entered doesnot exist";
    }
    cout << "\n\n\n\nNO of people vaccinated  by this age: " << p;
    in.close();
}
//---------------------------------------------------
void Patient::search_by_age() // 6.2
{
    ifstream in;
    in.open("app.dat");
    int flag = 0;
    int a, p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 APPOINTMENT MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;
    //    cout<<"\t\t\t\t\t\t Powered By:- TEAM AC/DC "<<endl<<endl;
    cout << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t AGE SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter Age by which you want to search " << endl;
    cin >> a;

    while (!in.eof())
    {
        if (in.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {

            if (a == this->age)
            {
                cout << "\n\nSearching.";
                for (int i = 0; i <= 10; i++)
                {
                    cout << ".";
                    Sleep(100);
                }
                show();
                showList();
                flag = 1;
                p++;
            }
        }
    }
    if (flag == 0)
    {
        cout << "Age you entered is not found" << endl;
    }
    cout << "\n\n\n\nNO of people vaccinated  by this age" << p;
    in.close();
}
//----------------------------------------------------------------------------------
void Patient::search_by_profession() // 6.3
{
    ifstream in;
    in.open("app.dat");
    int flag = 0;
    int p = 0;
    char pf[100];
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;
    cout << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t PROFESSION SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter Profession by which you want to search:" << endl;
    fflush(stdin);
    gets(pf);

    while (!in.eof())
    {
        if (in.read(reinterpret_cast<char *>(this), sizeof(*this)) > 0)
        {

            if (strcmp(pf, profession) == 0)
            {
                cout << "\n\nSearching.";
                for (int i = 0; i <= 10; i++)
                {
                    cout << ".";
                    Sleep(100);
                }
                show();
                showList();
                flag = 1;
                p++;
                return;
            }
        }
    }
    if (flag == 0)
    {
        cout << "SORRY!! No people by this Profession is vaccinated." << endl;
    }
    cout << "\n\n\n No of people vaccinated by this profession: " << p << endl;
    in.close();
}
//-------------------------------------------------------------------
void Patient::search_by_gender() // 6.4
{
    ifstream in("app.dat");
    int flag = 0;
    char g;
    int p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;
    cout << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t GENDER SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter gender by which you want to search " << endl;
    cin >> g;

    while (!in.eof())
    {
        if (in.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {

            if (g == this->gender)
            {
                cout << "\n\nSearching.";
                for (int i = 0; i <= 10; i++)
                {
                    cout << ".";
                    Sleep(100);
                }
                show();
                showList();
                flag = 1;
                p++;
            }
        }
    }
    if (flag == 0)
    {
        cout << "SORRY!! No people by this Gender have a record." << endl;
    }

    cout << "\n\n\n NO. of people that have appointments of this gender: " << p << endl;
    in.close();
}
//---------------------------------------------------------
void Patient::modify() // 7
{
    ifstream in("app.dat");
    int n;
    Patient v;
    v.view_all();
    int i = 0;
    in.seekg(0, ios::beg);
    while (in.read((char *)this, sizeof(Patient)))
    {
        i++;
    }
    in.close();
    cout << "\nEnter the S.N. to modify:";
    cin >> n;
    if (n <= i && n > 0)
    {

        cout << "\t\t\t\t MODIFYING........................ ";

        fstream infile;
        infile.open("vaccinetrial.dat", ios::in | ios::out | ios::binary);
        setData();
        infile.seekp((n - 1) * sizeof(*this));
        infile.write(reinterpret_cast<char *>(this), sizeof(*this));
        infile.close();
        cout << "\nSuccessfully Modified";

        getch();
    }
    else
    {
        cout << "There is no record of such type";
        getch();
    }
}
//------------------------------------------------------
void Patient::view_all() // 8
{
    fstream outfile;
    outfile.open("app.dat", ios::binary | ios::in); // Opened to read
    if (!outfile)
    {
        cout << "File doesnot exist";
        getch();
    }
    else
    {
        cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 APPOINTMENT MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
             << endl;
        cout << "\n\t\t\t*****************************************\n";
        cout << "\t\t\t\t\tALL DATA ";
        cout << "\n\t\t\t*****************************************\n\n";
        show(); // header
        while (!outfile.eof())
        {
            if (outfile.read(reinterpret_cast<char *>(this), sizeof(*this)) > 0)
            {
                showList(); // sab data dekhaidinxa
            }
        }
        cout << "\n\n\t\tPRESS ANY KEY .... ";
        getch();
    }

    outfile.close();
}
//------------------------------------------------------------
void Patient::del() // 9
{
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
         << endl;
    cout << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t Delete in process..............";
    cout << "\n\t\t\t*****************************************\n\n";
    ifstream in("app.dat");
    fstream tmpfile("temp.dat", ios::out | ios::binary); // To write on it
    Patient v;
    v.view_all();
    int n, i = 0;
    cout << "\n***Enter record number to delete: ";
    cin >> n;
    while (!in.eof())
    {
        if (in.read(reinterpret_cast<char *>(this), sizeof(*this)) > 0)
        {
            i = i + 1;
            if (i != n)
            {
                tmpfile.write(reinterpret_cast<char *>(this), sizeof(*this));
            }
        }
    }

    getch();
    in.close();
    tmpfile.close();
    remove("app.dat");
    rename("temp.dat", "app.dat");
}

//-----------------------------------------------------
void show() // a  HEader
{
    cout << "\n\n\n";

    cout << setw(20) << setiosflags(ios::left) << "Name";
    cout << setw(20) << "Citizenship";
    cout << setw(15) << "Age";
    cout << setw(15) << "Profession";
    cout << setw(15) << "B.P.";
    cout << setw(15) << "Temperature";
    cout << setw(15) << "Gender";
    cout << setw(15) << "Mobile No";
    cout << setw(15) << "Address";
}
//----------------------------------------------------------------------
int password() // b
{
    char cname[30], pass[20];
    int ch, i = 0, cap = 0, capt = 0;
    cout << "\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout << "\n\t\t\t\t\tPASSWORD:    ";
    while ((ch = getch()) != 13)
    {
        cout << "*";
        pass[i] = ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap = rand();
    cout << "\n\n\t\t\t\t\tCaptcha:-> " << cap << endl;
    cout << " Please enter the valid captcha :-   ";
    cin >> capt;
    if ((strcmp(cname, "acdc") == 0) && (strcmp(pass, "123") == 0) && cap == capt)
        return 1;
    else
        return 0;
}
//----------------------------------------
void menu() // c display the functionalites of this program
{
    system("cls");
    cout << "\n\t\t\t\t\t APPOINTMENT MANAGEMENT SYSTEM " << endl;
    cout << "\n\t\t\t\t*****************************************\n";
    cout << "\t\t\t\t\t WELCOME TO THE MAIN MENU";
    cout << "\n\t\t\t\t*****************************************\n";
    cout << "\n\t\t1: Book An Appointment\t\t\t " << endl;
    cout << "\n\t\t2: Search Data   \t\t\t\t 3: View All Data" << endl;
    cout << "\n\t\t4: Modify Data  \t\t\t\t 5: Delete    \t\t\t\t " << endl;
    cout << "\n\t\t6: Exit" << endl;
}
//----------------------------------------
int main() // MAINFUNCTION---------------------------------------------------------------------------------------------
{
    Patient obj;
    char login_choice;
    system("Color E8");
    int k = 3;
    int num_vac;
    cout << "\n\t\t\t\t\t APPOINTMENT MANAGEMENT SYSTEM " << endl;

    cout << "\t\n\n Press any key to continue.............  " << endl;
    getch();
B:
    system("cls");
    cout << "\n\t\t\t\t*****************************************\n";
    cout << "\t\t\t\t\t WELCOME TO THE LOGIN PAGE";
    cout << "\n\t\t\t\t*****************************************\n";
    cout << "\n\t\t\tEnter A for Admin Login OR B for Public Login: ";
    cin >> login_choice;
    cout << "\n\t\t\t\t\tEnter User name and Password\n";
    // Loading screen complete and here asks for username and password
    while (k >= 1)
    {
        int c = password();
        if (c == 1)
            break;
        else
            cout << "\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only " << k - 1 << " times more";
        k--;
        if (k < 1)
        {
            for (int i = 59; i >= 0; i--)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
                cout << "\n\n\n\n\n\n\t\t\t\t\tTRY AFTER " << i << " SECONDS.....";
                Sleep(1000);
            }
            k = 3;
            goto B;
        }
    }
    int ch;
    do
    {
        cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 APPOINTMENT MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
             << endl;
        cout << endl;
        menu(); // List for showing the all the functions we can do .
        cout << "\n\t\n\tChoose according to your need : ";
        cin >> ch;
        Patient v1;
        switch (ch)
        {
        case 1:
            system("cls");
            obj.addNew();
            break;
        case 2:
            system("cls");
            obj.searchData();
            break;
        case 3:
            system("cls");
            obj.view_all();
            break;
        case 4:
            system("cls");
            obj.modify();
            break;
        case 5:
            system("cls");
            obj.del();
            break;
        case 6:
            system("cls");
            exit(0);
        default:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
            cout << "\n\n\t\t\t\t\t****HAVE A NICE DAY*****";
            Sleep(3000);
            exit(0);
        }
    } while (ch != 0);

    return 0;
} //----------------------------------------------------------------------------------------------------------------------
