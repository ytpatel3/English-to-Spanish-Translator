/*
Yash Patel, Rahul Pemmasani, Krrishiv Kohli, Ashwin Vaithiyalingam
Hackathon 2022
4/23/22
*/

//http://www.gwicks.net/dictionaries.htm

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;


int main() {
  
  bool runAgain = true;
  cout << "\n                Yash's Secure Translator                      \n";
  cout << "      ＊This translator never compromises user data*\n\n";

  string username, password;
  cout << "Enter your username: ";
  getline(cin, username);
  cout << "Enter your password: ";
  getline(cin, password);

  do {
    string userChoice2;
    int userChoice;
    bool errorTrap = true;


    ifstream myfile;
    myfile.open("English.txt");

    ifstream myfile2;
    myfile2.open("Spanish.txt");

    string search, search2, line, line2;
    if (userChoice == 1) {
      //Creating variables to find what word the user wants translated
      bool isFound;
      int lineCounter = 0, pos = 0, lineCounter2 = 0;

      cout << "\nEnglish word to be translated (lowercase): ";
      getline(cin, search);

      transform(search.begin(), search.end(), search.begin(), ::tolower);


      while(getline(myfile, line)) {
        lineCounter++;
        //(line.find(search) != string::npos)
        if (line == search) {
          cout << "\n\nEnglish: " << line << endl;
          break;
        }
      }

      if(search == "zymurgy" || search2 == "zymurgy" || line == "zymurgy" || line2 == "zymurgy" || search == "zimurgia" || search2 == "zimurgia" || line == "zimurgia" || line2 == "zimurgia") {
      cout << "\nWord does not exist in list.\n";
      return 0;
    }
      
      while (getline(myfile2, line2) && lineCounter2 <= lineCounter) {
        lineCounter2++;
        if (lineCounter2 == lineCounter) {
          cout << "Spanish: " << line2 << endl;
        }
      }
    }
      
    else if (userChoice == 2) {
      //Creating variables to find what word the user wants translated
      string search2, line, line2;
      bool isFound2;
      int lineCounter3 = 0, lineCounter4 = 0;

      cout << "Word to be translated (lowercase): ";
      getline(cin, search2);

      transform(search2.begin(), search2.end(), search2.begin(), ::tolower);

      while(getline(myfile2, line)) {
        lineCounter3++;
        
        //(line.find(search) != string::npos)
        if (line == search2) {
          cout << "\nSpanish: " << line << endl;
          break;
        }
      }

      while (getline(myfile, line2) && lineCounter4 <= lineCounter3) {
        lineCounter4++;
        if (lineCounter4 == lineCounter3) {
          cout << "English: " << line2 << endl;
        }
      }
    }



    //Asking user if they want to translate again
    cout << "\n\n\nDo you, " + username + ", want to translate another word? (y/n): ";
    getline(cin, userChoice2);

    if (userChoice2 == "Y" || userChoice2 == "y") {
      runAgain = true;
    }
    else if (userChoice2 == "N" || userChoice2 == "n") {
      cout << "Are you absolutely sure? (y/n): ";
      getline(cin, userChoice2);
      if (userChoice2 == "Y" || userChoice2 == "y") {
        cout << "\nThanks for running!";
        myfile.close();
        myfile2.close();
        runAgain = false;
      }
      else if (userChoice2 == "N" || userChoice2 == "n") {
        runAgain = true;
      }
    }
    
  } while (runAgain == true);
}