// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: Login System .
// Last Modification Date: 5/8/2022
// Author1 and ID and Group: Moaz Alaa Eldin Megahed - 20210587
// Author2 and ID and Group: Mariam Ramadan Abd El-Hameed - 20210381
// Author3 and ID and Group: Youssef Mahmoud Okasha Mahmoud - 20210486
#include <iostream>
#include <string>
#include "Login.h"
struct data{
    string name;
    string gmail;
    string phone;
};
int main()
{
    int choice;
    bool flag= true;
    string Continue;
    while (flag) {
        cout << "1.Register \n"
                "2.Login \n"
                "3.Chang Password \n"
                "4.Exit \n";
        cout<<"Please choose from the following menu :\n";
        cin>>choice;
        switch (choice) {
            case 1:
                Register();
                break;
            default:
                cout<<"choose correct number \n";
        }
        cout<<"\n If you want to continue press 'yes' else press 'no' \n";
        cin>>Continue;
        if(Continue!="yes")
        {
            flag= false;
        }
    }
    return 0;
}

