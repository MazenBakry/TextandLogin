#ifndef LOGINAPPFUNCTIONS_H_INCLUDED
#define LOGINAPPFUNCTIONS_H_INCLUDED

#include<vector>
#include "conio.h"
using namespace std;

struct user_info {
    string UserName,e_mail , pass,PhoneNumber ;
    string Id;
};


extern char  pass[100];
extern char  pass1[100];

void passRequire();
bool repeat();
bool validate();
void write();
void loadexistingusers (vector<user_info>&user);
void displayMenu ();
void regist ();
bool Email_check(string email);
bool PhoneNumber_check(string PhoneNumber);
bool check_input_data (string search);


#endif // LOGINAPPFUNCTIONS_H_INCLUDED
