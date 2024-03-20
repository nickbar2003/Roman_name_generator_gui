#include "program.h"

void displayMenu() {
  std::cout << "\n\nWelcome to the "
               "Roman Name Generator!!"
            << "\n";
  std::cout << "Please choose from the following options: "
            << "\n";
  std::cout << "1) Character Name"
            << "\n";
  std::cout << "2) Settlement Name"
            << "\n";
  std::cout << "3) River Name"
            << "\n";
  std::cout << "9) Quit"
            << "\n";
}

int getValidChoice() {
  int choice = -1;
  std::string temp;
  do {
    std::cout << "Choice: ";
    std::cin >> choice;
    if (choice < FIRST_OPTION || choice > LAST_OPTION) {
      std::cout << "That is not a valid option. Please try again.\n";
    }
  } while (choice < FIRST_OPTION || choice > LAST_OPTION);
  getline(std::cin, temp); // flush the newline outta the buffer
  return choice;
}

void executeUserChoice(int choice) {
  switch (choice) {
  case 1:
    std::cout << "\n\nYour Character Name is: " << generateCharacterName()
              << "\n";
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  default:
    std::cout << "Unrecognized menu choice\n";
    break;
  }
}

void runProgram() {
  srand(0);
  int choice = -1;
  do {
    displayMenu();
    choice = getValidChoice();
    if (choice != QUIT_OPTION) {
      executeUserChoice(choice);
    }
  } while (choice != QUIT_OPTION);
  std::cout << "Thanks for using the Roman Name Generator\n";
}

std::string generateCharacterName() {

  std::map<int, std::string> praenomenMap{
      {0, "Aulus"},    {1, "Appius"},    {11, "Gaius"},    {9, "Gnaeus"},
      {4, "Decimus"},  {2, "Kaeso"},     {6, "Lucius"},    {7, "Marcus"},
      {8, "Manius"},   {3, "Mamercus"},  {17, "Numerius"}, {5, "Publius"},
      {12, "Quintus"}, {13, "Servius"},  {14, "Sextus"},   {15, "Spurius"},
      {16, "Titus"},   {10, "Tiberius"},
  };

  std::string completeName = "";
  std::string praenomen = "";
  std::string gensnomen = "";
  std::string cognomen = "";

  int praenomenSize = 18;
  int gensnomenSize = 789;
  int cognomenSize = 105;

  std::string gensnomenArr[gensnomenSize];
  std::string cognomenArr[cognomenSize];

  loadNomenArr(gensnomenArr, gensnomenSize, "gensnomen.txt");
  loadNomenArr(cognomenArr, cognomenSize, "cognomen.txt");

  praenomen = praenomenMap[(rand() % praenomenSize)];
  gensnomen = gensnomenArr[(rand() % gensnomenSize)];
  cognomen = cognomenArr[(rand() % cognomenSize)];
  completeName = praenomen + " " + gensnomen + " " + cognomen;
  return completeName;
}

void loadNomenArr(std::string *array, int size, std::string filename) {
  std::fstream fileTag;
  fileTag.open(filename);
  for (int i = 0; i < size; i++) {
    getline(fileTag, array[i]);
  }
  fileTag.close();
}
