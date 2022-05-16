#include <bits/stdc++.h>
#include "conio.h"
#include "loginAppFunctions.h"
using namespace std;


char  pass[100];
char  pass1[100];
user_info data;
map<string ,user_info>user ;

void displayMenu (){
    while (true){
    int option ;
    cout <<"To register press (1)" << endl;
    cout <<"To exit press (0)" << endl;
    cin >>  option ;
    if (option==1)
        regist();
    else if (option == 0)
        break;
    }
}
void loadexistingusers (vector<user_info>&user){
    ifstream  file ;
    file.open("tst.txt");
    user_info temp ;
    while (!file.eof() )
    {
        getline(file ,temp.Id);
        getline(file ,temp.UserName);
        getline(file ,temp.e_mail);
        getline(file ,temp.PhoneNumber);
    }
}

void regist (){
    user_info data;
    bool a = true;
    while (a){
        cout<<"enter your ID"<<endl;
        cin>>data.Id;
        regex x("[0-9]*");
        if(!regex_match(data.Id, x)){
            a = true;
        }
        else{
            a = false;
        }
        ifstream file;
        file.open("tst.txt");
        while (!file.eof()) {
            string temp = "";
            getline(file, temp);
            if (temp == data.Id) {
                cout << "Not available, please enter another one : " << endl;
                cin.ignore();
                cin >> data.Id;
            }


        }
    }

    bool b = true;
    while (b){
        cout<<"enter your user name: "<<endl;
        cin>>data.UserName;
        regex y("[a-zA-Z_-_]*");
        if(!regex_match(data.UserName, y)){
            b = true;
        }
        else{
            b = false;
        }
        ifstream file;
        file.open("tst.txt");
        while (!file.eof()) {
            string temp = "";
            getline(file, temp);
            if (temp == data.UserName) {
                cout << "Not available, please enter another one : " << endl;
                cin.ignore();
                cin >> data.UserName;
            }
        }
    }
    bool c = true;
    while (c){
        cout<<"enter your email: "<<endl;
        cin>> data.e_mail;
        regex z("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        if(!regex_match(data.e_mail, z)){
            c = true;
        }
        else{
            c = false;
        }
        ifstream file;
        file.open("tst.txt");
        while (!file.eof()) {
            string temp = "";
            getline(file, temp);
            if (temp == data.e_mail) {
                cout << "Not available, please enter another one : " << endl;
                cin.ignore();
                cin >> data.e_mail;
            }
        }
    }
    bool d = true;
    while (d){
        cout<<"enter your number: "<<endl;
        cin>> data.PhoneNumber;
        regex q("^(\\+201|01|00201)[0-2,5]{1}[0-9]{8}");
        if(!regex_match(data.PhoneNumber, q)){
            d = true;
        }
        else{
            d = false;
        }
        ifstream file;
        file.open("tst.txt");
        while (!file.eof()) {
            string temp = "";
            getline(file, temp);
            if (temp == data.PhoneNumber) {
                cout << "Not available, please enter another one : " << endl;
                cin.ignore();
                cin >> data.PhoneNumber;
            }
        }
    }
    passRequire();
    bool flagValidate=false;
    while (!flagValidate){
    int a=0;
    while (pass[a-1] != '\r'){
            pass[a]=getch();
            if(pass[a-1]!= '\r')
                cout<<"*";
            a++;

        }
        cout<<endl<<endl;


        while(validate()==false){
            validate();
       }
         cout<<"Repeat the password, please"<<endl<<endl;
         bool flagRepeat=false;
         flagRepeat = repeat();
         if (flagRepeat == 1){
            cout<<"Passwords match"<<endl<<endl;
            flagValidate=true;
            data.pass=pass;
         }
        else{
            while (flagRepeat!=1){
            cout<<"Passwords don't match"<<endl<<endl;
            flagRepeat = repeat();
            }
        cout<<"Passwords match"<<endl<<endl;

    }
        }

    ofstream file ("tst.txt" , ios::app)  ;
    file << data.Id << endl;
    file << data.UserName << endl;
    file << data.e_mail << endl;
    file << data.pass <<endl;
    file << data.PhoneNumber << endl;
    file.close();
    cout << "Registered successfully :) " << endl ;
}

void passRequire(){
    cout<<"1-Password is at least 8 characters long. The longer your password is - the better."<<endl;
    cout<<"2-Use uppercase and lowercase letters, numbers and special symbols."<<endl;
}


bool repeat(){
    int a=0;
    while (pass1[a-1] != '\r'){
        pass1[a]=getch();
        if(pass1[a-1]!= '\r')
            cout<<"*";
        a++;

    }
    cout<<endl<<endl;

    if (sizeof(pass1)!= sizeof(pass))
        return false;
    else{
    for (unsigned long i=0;i<sizeof(pass)-1;i++){
            if (pass[i]!=pass1[i]){
                return false;
            }
    }
    }
    return true;
}


bool validate(){
    bool upper_case   = false; //saves the result if upper-case characters were found.
    bool lower_case   = false; //same for lower-case
    bool number_case  = false; //...
    bool special_char = false;





    regex upper_case_expression{ "[A-Z]+" }; //here is the very simple expression for upper_case search
    regex lower_case_expression{ "[a-z]+" }; //for lower-case
    regex number_expression{ "[0-9]+" }; //...
    regex special_char_expression{ "[@!?#$%^&*]+"};





    //do ask-for-password as long were not done

        if (sizeof(pass)-1 < 8){ //too short!
            cout << "Invalid password! Try again . . .\n\n";
            return false;
        }
        else{

            upper_case   = regex_search(pass, upper_case_expression); //save the result, if the expression was found.
            lower_case   = regex_search(pass, lower_case_expression); //....
            number_case  = regex_search(pass, number_expression);
            special_char = regex_search(pass, special_char_expression);

            //like: sum_of_positive_results = 1 + 0 + 1 + 1 (true/false as an integer)
            int sum_of_positive_results = upper_case + lower_case + number_case + special_char;

            if (sum_of_positive_results < 3){ //not enough booleans were true!
                cout << "Invalid password! Try again . . .\n\n";
            }
            else{ //otherwise it's valid!
                cout << "That's a valid Password!" << endl;
                return true;
            }
        }



}



