#include <string>
#include <iostream>
#include <vector>
//#include <utility>
#include "loginAppFunctions.h"
using namespace std;
int main () {
    vector<user_info> data;
    loadexistingusers (data);
    user_info dt;
    cout << "Welcome at login app :)" << endl ;
    displayMenu();
    /*while (true){
        int option = Displaymenu ();
        if (option==0){
            cout << "Thank u for using this app :)";
            break ;
        }
        if (option==1){
            regist(dt);
            cout << "Registered successfully :) " << endl ;
        }

    }*/

}

