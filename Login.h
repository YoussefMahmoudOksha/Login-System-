// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: Login System .
// Last Modification Date: 5/16/2022
// Author1 and ID and Group: Moaz Alaa Eldin Megahed - 20210587
// Author2 and ID and Group: Mariam Ramadan Abd El-Hameed - 20210381
// Author3 and ID and Group: Youssef Mahmoud Okasha Mahmoud - 20210486

#ifndef LOGIN_SYSTEM_CPP_LOGIN_H
#define LOGIN_SYSTEM_CPP_LOGIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "Login.h"
using namespace std;
bool IsEmailValid(const string& Gmail);
bool IsPhoneValid(const string& phone);
void Register();
bool IsNameValid(const string& name);
bool CheckName(string& name);
bool CheckGmail(string& Gmail);
bool IsPasswordValid(string& password1, string& password2);
bool IsPasswordStrong(string& password1);
#endif //LOGIN_SYSTEM_CPP_LOGIN_H
