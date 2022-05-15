// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: Login System .
// Last Modification Date: 5/8/2022
// Author1 and ID and Group: Moaz Alaa Eldin Megahed - 20210587
// Author2 and ID and Group: Mariam Ramadan Abd El-Hameed - 20210381
// Author3 and ID and Group: Youssef Mahmoud Okasha Mahmoud - 20210486

#include <iostream>
#include <string>
#include <regex>
#include "Login.h"
using namespace std;
struct data{
    string name;
    string gmail;
    string phone;
};
void Register()
{
    data inf;
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
    Registration<<endl;
    if(!CheckName(inf.name) && !CheckGmail(inf.gmail))
    {
        Registration<<inf.name<<endl;
        Registration<<inf.gmail<<endl;
        Registration<<inf.phone<<endl;
    }
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



