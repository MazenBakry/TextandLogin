#include<bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include<conio.h>
#include "text.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

using namespace std;

fstream file;
vector <string> token;






void print()
{
    for (auto i = token.begin(); i != token.end(); ++i) std::cout << *i << endl;
}

void empty_the_file()
{
    token.clear();
}

void add_text()
{

    fstream file1;
    char ch;
    string new_word;
    char new_text[1500], line[100];
    cout << "now you can add the new text \n";
    cout << "press ctrl+z to exit\n";
    while (ch != 26) {
        ch = getch();
        if (ch == 13) {
            cout << "\n";
            new_word += "\n";
        }
        else if (ch == '\b') {
            cout << "\b \b";
            if (new_word.length() > 1) {
                new_word.erase(new_word.length() - 1, 1);
            }
            else {
                new_word.clear();
            }
        }
        else {
            cout << ch;
            new_word += ch;
        }

    }
    cout << "\n";
    new_word.erase(new_word.length() - 1, 1);
    token.push_back(new_word);
}



void cypher()
{
    for (int i=0;i<token.size();i++)
    {
        for(int k=0; k<token[i].size(); k++)
        {
            char x;
            x=token[i][k]+1;
            token[i][k]=x;
            cout << x;
        }
    }
}

void decypher()
{
    for (int i=0;i<token.size();i++)
    {
        for(int k=0; k<token[i].size(); k++)
        {
            char x;
            x=token[i][k]-1;
            token[i][k]=x;
            cout << x;
        }
    }
}

void mergeFiles(){
    string str1,str2,secFilename;
    cin>>secFilename;
    ifstream secFile;
    secFile.open(secFilename, ios:: in );
    while (getline(secFile,str2)){
        token.push_back(string(str2));
    }
    cout<<"Merged!"<<endl;
    secFile.close();



}

void countWords(){
    int counter=0;
    for (int i=0;i<token.size();i++){
        string word;
        stringstream line(token [i]);
        while(!line.eof()){
            line >> word;
            counter++;
            }
        }
    cout<<counter<<endl;
    }



void countLines(){
    cout<<"Number of lines are "<<token.size()<<endl;

}

void countChar(){
    int counter=0;
    for (int i=0;i<token.size();i++){
                counter+=token[i].length();


            }

    cout<<counter;

}

void findWord(){
    convertToLower();
    string word;
    cout << "enter a word : ";
    cin>>word;
    int a=0;

     for(std::string& s  : token){
        if(s.find(word) != std::string::npos)
            a++;
  }


    if(a>0){
        cout<<"Found "<< a << " time(s)"<<endl;
    }
    else
        cout<<"Not Found"<<endl;

}

void NumOfTimes(){

    for (int i =0 ; i < token.size();i++){
        for(int j = 0 ; j < token[i].size() ; j ++){
            token[i][j]= tolower(token[i][j]);
            }
    }
     string word , word2;
     cout<<"enter the word "<<endl;
     cin>>word;
     int counter = 0;
     for ( int i = 0 ; i < token.size() ; i++){
        stringstream x(token[i]);
        while (x>>word2){
        if(word2==word){
            counter++;
         }
       }
     }
     cout <<"this word was found "<< counter<<" times."<<endl;

}

void convertToLower(){

    for (int i =0 ; i < token.size();i++){
        for(int j = 0 ; j < token[i].size() ; j ++){
            token[i][j]= tolower(token[i][j]);
        }
    }
    for(string line:token){
        cout<<line<<endl;
    }
}

void convertToUpper(){

    for (int i =0 ; i < token.size();i++){
        for(int j = 0 ; j < token[i].size() ; j ++){
            token[i][j]= toupper(token[i][j]);
        }
    }
    for(string line:token){
        cout<<line<<endl;
    }
}

void FstChar(){

     for (int i =0 ; i < token.size();i++){
        for(int j = 0 ; j < token[i].size() ; j ++){
            if (token[i][j]==' '){
                token[i][j+1]=toupper(token[i][j+1]);
            }
            else if (j==0){
                token[i][0]=toupper(token[i][0]);
            }
        }
     }
    for(string line:token){
        cout<<line<<endl;
    }
}

void save()
{
    ofstream file;
    char fileName[20]="bb.txt";
    file.open((fileName), fstream::trunc|fstream::out);
    for (int i=0;i<token.size();i++){
        file<<token[i];
    }
}

void loadFile(vector<string>& token, fstream& file){
    char line[100];
    if(file){
      while(!file.eof()){
        file.getline(line , 100 ,'\n');
        token.push_back(string(line));
      }

      displayMenu();
    }
}


void displayMenu(){
    while (true){
        cout << "\n1 --> Add text\n";
        cout << "2 --> Print\n";
        cout << "3 --> Clear\n";
        cout << "4 --> Encrypt the file\n";
        cout << "5 --> Decrypt the file\n";
        cout << "6 --> Merge\n";
        cout << "7 --> Count words\n";
        cout << "8 --> Count characters\n";
        cout << "9 --> Count lines\n";
        cout << "10 --> Search a word in a file\n";
        cout << "11 --> lower case"<<endl;
        cout << "12--> upper case"<<endl;
        cout << "13--> 1st char of each word is capital"<<endl;
        cout << "14 --> Count the number of times a word exists in the file"<<endl;
        cout << "15 --> save"<<endl;
        cout << "16 --> Exit\n";
        int x;
        cin >> x;
        if(x==1)
            add_text();
        else if(x==2)
            print();
        else if(x==3)
            empty_the_file();
        else if(x==4)
            cypher();
        else if(x==5)
            decypher();
        else if(x==6)
            mergeFiles();
        else if(x==7)
            countWords();
        else if(x==8)
            countChar();
        else if(x==9)
            countLines();
        else if(x==10)
            findWord();
        else if(x==11)
            convertToLower();
        else if(x==12)
            convertToUpper();
        else if(x==13)
            FstChar();
        else if(x==14)
            NumOfTimes();
        else if(x==15){
            file.close();
            save();
        }
        else if(x==16)
            break;
        }

}

