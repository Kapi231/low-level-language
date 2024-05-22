#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <limits>
#include <ostream>
#include <pstl/glue_algorithm_defs.h>
#include <string>
#include <iostream>

#ifdef _WIN32
#include <windows.h>

std::string os_command = "cls";
#endif

#ifdef linux
#include <unistd.h>

std::string os_command = "clear";
#endif

std::string originalFile = "logs/task_list.txt";
std::string tmpFile = "logs/tmp.txt";

void ShowContent() {
  system(os_command.c_str());
  std::ifstream oFile(originalFile);
  std::string line;
  
  std::cout << "<==========Todo App==========>\n\n";

  while (getline(oFile, line)) {
    std::cout << line << std::endl;
  }
  oFile.close();
  std::cout << "\n<==========================================>";
  std::cout << "\n A = add task | D = delete task | E = exit";
  std::cout << "\n<==========================================>";
}

void AddTask() {
  std::fstream file(originalFile, std::ios::app);
  
  std::string task;

  while (1) {
    ShowContent();
    std::cout << "\nAdd task: ";
    std::cin >> task;
    if (task == "E") {
      break;
    }
    else {
      file << task << std::endl; 
    }
  }

  file.close();
}

void DeleteTask() {
  std::fstream oFile(originalFile);
  std::fstream tFile(tmpFile, std::ios::app);

  int delLine = 0;
  bool validInput = false;
  
  while (!validInput) {
    std::cout << "\nWhich task you want to delete? : ";
    std::cin >> delLine;

    if (std::cin.fail()) {
      std::cout << "It's not a number";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } 
    else {
      validInput = true;
    }
  }

  std::string line;
  int lineNumber = 0;

  while (getline(oFile, line)) {
    lineNumber++;
    std::cout << line << std::endl;
    if (lineNumber != delLine) {
      tFile << line << std::endl;
    }
  }

  oFile.close();
  tFile.close();

  try {
    std::remove(originalFile.c_str());
    std::rename(tmpFile.c_str(), originalFile.c_str());
  }
  catch (...) {
    std::cerr << "Error removing/renaming files\n";
  }
}

int main (int argc, char *argv[]) {

  while (1) {
    bool validInput = false;
    ShowContent();
    std::string command;

    while (!validInput) {
      std::cout << "\nCommand /> ";
      std::cin >> command;

      if (std::cin.fail()) {
        std::cin.clear();
        std::cout << "\nCommand error\n";
        std::exit(1);
      }
      else {
        validInput = true;
      }
    }
   
    if (command == "A") {
      AddTask();
    } 
    else if (command == "D") {
      ShowContent();
      DeleteTask();
    } 
    else if (command == "E") {
      system(os_command.c_str());
      std::cout << "Goodbye <3\n";
      break;
    }
  }

  return 0;
}
