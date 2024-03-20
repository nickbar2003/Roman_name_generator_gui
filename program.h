#ifndef PROGRAM_H
#define PROGRAM_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = QUIT_OPTION;

void displayMenu();
int getValidChoice();
void executeUserChoice(int);
void runProgram();
void loadNomenArr(std::string *, int, std::string);
std::string generateCharacterName();
#endif
