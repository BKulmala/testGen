//Checklist
//1.store the term
//2.store the definition
//3.store multiple
//4.a list to call for previously made ones or new ones
//5.games for lists. Multiple choice, True/false, respond
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <cstdlib>
#include <sys/types.h>
#include <vector>
#include <stdio.h>    
#include <stdlib.h>    
#include <time.h>


void fileCreate() {
    std::string txtName;
    std::cin.ignore();
    std::getline(std::cin, txtName);
    std::ifstream file;
    { //Terms
      std::ofstream MyFile("Terms/" + txtName + ".txt");
      std::ofstream MyFileTwo("Definitions/D_" + txtName + ".txt");
      MyFile.open("Terms/" + txtName + ".txt", std::ofstream::app);
      MyFileTwo.open("Definitions/D_" + txtName + ".txt", std::ofstream::app);
      MyFile.close();
      MyFileTwo.close();
      int i = 1;
      std::string term;
      std::string define;
      while(i != 0) {
      std::cout << "Enter your term.\n";
      std::getline(std::cin, term);
      MyFile.open("Terms/" + txtName + ".txt", std::ofstream::app);
      MyFile << term << "$" << std::endl;
      MyFile.close();

      std::cout << "Enter the definition for " << term << ".\n";

      std::getline(std::cin, define);
      MyFileTwo.open("Definitions/D_" + txtName + ".txt", std::ofstream::app);
      MyFileTwo << define << "$" << std::endl;
      MyFileTwo.close();
      std::cout << term << " is " << define << ". Continue?\n0.No\n1.Yes\n";
      std::cin >> i;
      std::cin.ignore();
      }
    }
      return;
}
void fileList() {
    std::string path = "Terms";
        char term, definition;
        std::vector<std::string> termsL;
        std::vector<std::string> definitionL;
        std::string termSen;
        std::string definitionSen;
        std::string chapterReview;
        std::string response;
        int choice;
        char charChoice;
    for (const auto & file : std::filesystem::recursive_directory_iterator(path)) {
        std::cout << file.path() << std::endl;
    }
        std::cout << "What do you want to review?";
        std::cin.ignore();
        std::getline(std::cin, chapterReview);
      std::ifstream MyFile("Terms/" + chapterReview + ".txt");
      std::ifstream MyFileTwo("Definitions/D_" + chapterReview + ".txt");
      MyFile.open("Terms/" + chapterReview + ".txt");
      MyFileTwo.open("Definitions/D_" + chapterReview + ".txt");
      MyFile.close();
      MyFileTwo.close();
        std::cout << "You want to review " << chapterReview << ". How do you want to review it?\n";
        std::cout << "1.Terms and Definitions\n2.True/False\n3.Multiple choice\n4.Fill in the blank";
        std::cin >> choice;


      MyFile.open("Terms/" + chapterReview + ".txt");
      MyFile >> std::noskipws;
      while(!MyFile.eof()) {
        MyFile >> term;
        if(term == '$') {
          termsL.push_back(termSen);
          termSen = "";
          MyFile >> term;
        }
        else if(term == '\n') {
        MyFile >> term;
        }
        else{
          termSen.push_back(term);
        }
      }
        MyFile.close();
      MyFileTwo.open("Definitions/D_" + chapterReview + ".txt");
      MyFileTwo >> std::noskipws;
      while(!MyFileTwo.eof()) {
        MyFileTwo >> definition;
        if(definition == '$') {
          definitionL.push_back(definitionSen);
          definitionSen = "";
          MyFileTwo >> definition;
        }
        else if(definition == '\n') {
        MyFileTwo >> definition;
        }
        else{
          definitionSen.push_back(definition);
        }
      }
        MyFileTwo.close();

          srand((unsigned)time(NULL));
          int random = rand() % termsL.size();
          int guess = rand() % definitionL.size();
          std::string answer;
          char answr;
        switch(choice) {
          case 1:
            for(int i = 0;i != termsL.size();i++){
              std::cout << termsL[i] << "--" << definitionL[i] << std::endl << std::endl;
            }
          break;
          case 2:
          std::cout << "True or false, " << termsL[random] << " is " << definitionL[guess];
          std::cin >> answer;
          if(random == guess && answer == "T" || answer == "True" || answer == "t" || answer == "true") {
            std::cout << "True! You are correct.";
          break;
          }
          else if(random != guess && answer == "F" || answer == "False" || answer == "f" || answer == "false"){
            std::cout << "False! You are correct.";
          break;
          }
          else{
            std::cout << "Incorrect." << termsL[random] << " is " << definitionL[random];
            break;
          }
          break;
          case 3:
          std::cout << "What is " << termsL[random] << "?" << std::endl;
          answr = rand() % 4 + 65;
          for(char i = 'A';i <= 68;i++) {
            if(answr == i) {
              std::cout << i << "." << definitionL[random] << std::endl;
            }
            else if(answr != i && definitionL[random] != definitionL[guess]){
              std::cout << i << "." << definitionL[guess] << std::endl;
              guess = rand() % definitionL.size();
            }
          }
          std::cin >> charChoice;
          if(charChoice == answr) {
            std::cout << "Correct!";
          }
          else{
            std::cout << "Incorrect.";
          }
          break;
          case 4:
              std::cout << "What is " << termsL[random] << "?";
                  std::cin.ignore();
                  std::getline(std::cin, response);
              if(response == definitionL[random]) {
                std::cout << "Correct!";
              }
              else{
                std::cout << "Incorrect.";
              }
          break;
          default:
          std::cout << "Input invalid.";
          break;
            }
        }