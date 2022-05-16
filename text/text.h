#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

extern fstream file;
extern vector <string> token;

void loadFile(vector<string>& token, fstream& file);
void displayMenu();
void print();
void empty_the_file();
void add_text();
void cypher();
void decypher();
void mergeFiles();
void countWords();
void countLines();
void countChar();
void findWord();
void count();
void NumOfTimes();
void convertToLower();
void convertToUpper();
void FstChar();
void save();

#endif // TEXT_H_INCLUDED
