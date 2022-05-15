// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: Login System .
// Last Modification Date: 5/16/2022
// Author1 and ID and Group: Moaz Alaa Eldin Megahed - 20210587
// Author2 and ID and Group: Mariam Ramadan Abd El-Hameed - 20210381
// Author3 and ID and Group: Youssef Mahmoud Okasha Mahmoud - 20210486

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <conio.h>
#include "Login.h"
using namespace std;
struct data{
    string name;
    string gmail;
    string phone;
    string password[8];
};
void Register()
{
    data inf;
    string password1;
    string password2;
    fstream Registration;
    Registration.open("Registration.txt",ios::app);
    cout<<" Username: ";
    getline(cin>>ws,inf.name);
        while (!IsNameValid(inf.name))
        {
            cout<<"\n invalid name,Plz try again: \n";
            getline(cin>>ws,inf.name);
        }
    cout<<" Gmail: ";
    getline(cin>>ws,inf.gmail);
        while (!IsEmailValid(inf.gmail))
        {
            cout<<"\n invalid Email ,Please Try Again \n";
            getline(cin>>ws,inf.gmail);
        }
    cout<<" Phone: ";
    getline(cin>>ws,inf.phone);
        while (!IsPhoneValid(inf.phone))
        {
            cout<<"\n invalid Phone,Plz try again :\n";
            getline(cin>>ws,inf.phone);
        }
    while (CheckName(inf.name))
    {
        cout<<"\n Username already exists, please try again \n ";
        getline(cin>>ws,inf.name);
        while (!IsNameValid(inf.name))
        {
            cout<<"\n invalid name,Plz try again: \n";
            getline(cin>>ws,inf.name);
        }
    }
    while (CheckGmail(inf.gmail))
    {
        cout<<"\n Gmail already exists, please try again \n";
        getline(cin>>ws,inf.gmail);
        while (!IsEmailValid(inf.gmail))
        {
            cout<<"\n invalid Email ,Please Try Again \n";
            getline(cin>>ws,inf.gmail);
        }
    }
    cout << endl; // Password 
    cout << "Note the type of characters entered in the password" << endl;
    cout << "8 characters in length'\n'"
           " Contains 3/4 of the following items:'\n'"
           " - Uppercase Letters'\n'"
           " - Lowercase Letters'\n'"
           " - Numbers'\n'"
           " - Symbols'\n'";

    cout << " Password: ";
     for (int i = 0; i < 8; i++)
    {
        password1[i] = getch();
        cout << "*"; // replace the input to "*"
    }
    // check if the password is strong
    while (!IsPasswordStrong(password1))
    {
        cout << endl << "The password is Weak, Plz try again: ";

        for (int i = 0; i < 8; i++)
        {
            password1[i] = getch();
            cout << "*";
        }
    }
    cout << endl;
    cout << "The password is strong" ;
    cout << endl;
    cout << "Retype the password: "; // retype the password
    for (int i = 0; i < 8; i++)
    {
        password2[i] = getch();
        cout << "*";
    }

    // check the password is input correct
    while (!IsPasswordValid(password1,password2))
    {    
        cout << endl << "The tow Passwords is not match, Plz try again: ";
    
        for (int i = 0; i < 8; i++)
        {
            password1[i] = getch();
            cout << "*";
        
        }
        // check if the password is strong
        while (!IsPasswordStrong(password1))
        {
            cout << endl << "The password is Weak, Plz try again: ";

            for (int i = 0; i < 8; i++)
            {
                password1[i] = getch();
                cout << "*";
            }
        }
        cout << endl;
        cout << "The password id strong" ;
        cout << endl;
        cout << "Retype the password: ";
        for (int i = 0; i < 8; i++)
        {
            password2[i] = getch();
            cout << "*";
        }
    }  


    for (int i = 0; i < 8; i++)
    {
        inf.password[i] = password1[i];
    }

    // save the data in the file
    if(!CheckName(inf.name) && !CheckGmail(inf.gmail))
    {
        Registration<<endl;
        Registration<< "Name: " <<inf.name<<endl;
        Registration<< "Gmail: " <<inf.gmail<<endl;
        Registration<< "Phone: " <<inf.phone<<endl;
    }
    Registration<< "Password: ";
    for (int i = 0; i < 8; i++)
    {
        Registration<<inf.password[i];
    }
    Registration<<endl;

    Registration.close();
}
bool IsEmailValid(const string& Gmail)
{
    // define a regular expression
    const regex pattern
            ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    // try to match the string with the regular expression
    return regex_match(Gmail, pattern);
}
bool IsPhoneValid(const string& phone)
{
    // define a regular expression
    const regex pattern
            ("^01[0125][0-9]{8}$");

    // try to match the string with the regular expression
    return regex_match(phone, pattern);
}
bool IsNameValid(const string& name)
{
    // define a regular expression
    const regex pattern
            ("(\\w+)(_)?");

    // try to match the string with the regular expression
    return regex_match(name, pattern);
}
bool CheckName(string &name)
{
    bool check= false;
    fstream Registration;
    Registration.open("Registration.txt",ios::in);
    string lines;
    while (getline(Registration,lines))
    {
        if(name==lines)
        {
            check= true;
            break;
        }
    }
    return check;
}
bool CheckGmail(string& Gmail)
{
    bool check= false;
    fstream Registration;
    Registration.open("Registration.txt",ios::in);
    string lines;
    while (getline(Registration,lines))
    {
        if(Gmail==lines)
        {
            check= true;
            break;
        }
    }

    return check;
}
// the function to  check the passwords is valid or not and if is the same 
bool IsPasswordValid(string& password1, string& password2)
{
    bool check = true;
    for (int i = 0; i < 8; i++)
    {
        if (password1[i] == password2[i])
        {
            check = check * true;
        }  
        else
        {
            check = false;
        }
        
    }

    return check;
}
// this function see if the password is strong or not
bool IsPasswordStrong(string& password1)
{
    bool check = false;
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        switch(password1[i])
        {
        case 'A':
        sum += 3;
        break;
        case 'B':
        sum += 3;
        break;
        case 'C':
        sum += 3;
        break;
        case 'D':
        sum += 3;
        break;
        case 'E':
        sum += 3;
        break;
        case 'F':
        sum += 3;
        break;
        case 'G':
        sum += 3;
        break;
        case 'H':
        sum += 3;
        break;
        case 'I':
        sum += 3;
        break;
        case 'J':
        sum += 3;
        break;
        case 'K':
        sum += 3;
        break;
        case 'L':
        sum += 3;
        break;
        case 'S':
        sum += 3;
        break;
        case 'Q':
        sum += 3;
        break;
        case 'W':
        sum += 3;
        break;
        case 'R':
        sum += 3;
        break;
        case 'T':
        sum += 3;
        break;
        case 'Y':
        sum += 3;
        break;
        case 'U':
        sum += 3;
        break;
        case 'O':
        sum += 3;
        break;
        case 'P':
        sum += 3;
        break;
        case 'Z':
        sum += 3;
        break;
        case 'X':
        sum += 3;
        break;
        case 'V':
        sum += 3;
        break;
        case 'N':
        sum += 3;
        break;
        case 'M':
        sum += 3;
        break;
        case '1':
        sum += 2;
        break;
        case '2':
        sum += 2;
        break;
        case '3':
        sum += 2;
        break;
        case '4':
        sum += 2;
        break;
        case '5':
        sum += 2;
        break;
        case '6':
        sum += 2;
        break;
        case '7':
        sum += 2;
        break;
        case '8':
        sum += 2;
        break;
        case '9':
        sum += 2;
        break;
        case '0':
        sum += 2;
        break;
        case 'a':
        sum += 2;
        break;
        case 'b':
        sum += 2;
        break;
        case 'c':
        sum += 2;
        break;
        case 'd':
        sum += 2;
        break;
        case 'e':
        sum += 2;
        break;
        case 'f':
        sum += 2;
        break;
        case 'g':
        sum += 2;
        break;
        case 'h':
        sum += 2;
        break;
        case 'i':
        sum += 2;
        break;
        case 'j':
        sum += 2;
        break;
        case 'k':
        sum += 2;
        break;
        case 'l':
        sum += 2;
        break;
        case 'm':
        sum += 2;
        break;
        case 'n':
        sum += 2;
        break;
        case 'o':
        sum += 2;
        break;
        case 'p':
        sum += 2;
        break;
        case 'q':
        sum += 2;
        break;
        case 'r':
        sum += 2;
        break;
        case 's':
        sum += 2;
        break;
        case 't':
        sum += 2;
        break;
        case 'w':
        sum += 2;
        break;
        case 'v':
        sum += 2;
        break;
        case 'x':
        sum += 2;
        break;
        case 'u':
        sum += 2;
        break;
        case 'y':
        sum += 2;
        break;
        case 'z':
        sum += 2;
        break;
        case '\r':
        sum += 0;
        break;
        case '\b':
        sum += 0;
        break;
        default:
        sum += 6;
        }
    
               
    }

    if (sum <= 20)
        {
            check = false;
        }
        else if (sum >= 21)
        {
            check = true;
        }  

    return check;
    
}



