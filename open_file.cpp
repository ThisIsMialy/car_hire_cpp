/*
  open_file.cpp
  Student ID: M00837954
  Created: 19/12/2022
  Updated: 13/01/2023
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#include "vehicles.h"
#include "car.h"
#include "motorcycle.h"
#include "van.h"
#include "open_file.h"

#include "addVehicle.h"

/*
  all main vectors that store currently loaded file
  init in main file
  can be modified in this file
 */
extern std::vector<Car> vect_car;
extern std::vector<Motorcycle> vect_bike;
extern std::vector<Van> vect_van;

/*
  check if file exists
  @param filename
  @return bool
 */
inline bool file_exists (const std::string& filename){
  std::ifstream f(filename.c_str());
  return f.good();
};

/*
  turn a vector of string into respective class
  push class as an element into respective vector
  @param vect as vector 
  @return - none, void
 */

void turnIntoClass(std::vector<std::string>& vect){ 
  if (vect[0] == "car"){
    Car car(vect[1],
	    vect[2],
	    vect[7],
	    vect[8],
	    vect[3],
	    vect[9],
	    vect[10],
	    vect[4],
	    vect[5],
	    vect[6]); 

    vect_car.push_back(car);
  } else if (vect[0] == "bike"){
    Motorcycle motorcycle(vect[1],
			  vect[2],
			  vect[7],
			  vect[8],
			  vect[3],
			  vect[9],
			  vect[10],
			  vect[4],
			  vect[5],
			  vect[6]);

    vect_bike.push_back(motorcycle);
    
  } else if (vect[0] == "van"){
    Van van(vect[1],
	    vect[2],
	    vect[7],
	    vect[8],
	    vect[3],
	    vect[9],
	    vect[10],
	    vect[4],
	    vect[5],
	    vect[6]);

     vect_van.push_back(van);
  };  
};


/*splits string into multiple substrings where there is a delimiter
 @param line of string to be split
 @return void */
void stringSplit(const std::string& line){
  std::string str;
  str = line;
  std::string delimiter = ":";
  std::vector<std::string> vect;

  size_t position = 0;
  std::string token;
  while ((position = str.find(delimiter)) != std::string::npos){
    token = str.substr(0, position);
    vect.push_back(token);
    str.erase(0, position + delimiter.length());
  }
  vect.push_back(str);
  
  turnIntoClass(vect);
};


/*
  load a file that user inputs
  @param none
  @return void
 */
void loadFile(){
  std::string mystring;
  std::string line;
  std::ifstream inFile;
  std::string fileInput;

  std::cout << "\n";
  std::cout << "==============================================";
  std::cout << "\n LOADING FILE\n";
  std::cout << "Enter filename: ";
  std::cin >> fileInput;
  if (file_exists(fileInput)){
    inFile.open(fileInput);
    if (inFile.is_open()){
      
      while (inFile){
	std::getline(inFile, line);
	stringSplit(line);
      };
      inFile.close();
    }
  }
  else{
    std::cout << "ERROR: File is not found. Could not open." << std::endl;
    
  };
};



/*
  truncate all vector data into a file - overwrite a file
  @param filename 
  @return void
 */

void truncateFile(const std::string& filename){
  std::ofstream outFile(filename, std::ofstream::trunc);
  
  for (Car i : vect_car){
    outFile << i.save();
    outFile << "\n";
  };

  for (Motorcycle i : vect_bike){
    outFile << i.save();
    outFile << "\n";
  };

  for (Van i : vect_van){
    outFile << i.save();
    outFile << "\n";
  };
  
  std::cout << "SUCCESS: File overwritten.\n";
  outFile.close();
}


/*
  append all vector data into a file
  @param filename 
  @return void
 */
void appendFile(const std::string& filename){
  std::ofstream outFile;
  outFile.open(filename, std::ofstream::app);

  for (Car i : vect_car){
    outFile << i.save();
    outFile << "\n";
  };

  for (Motorcycle i : vect_bike){
    outFile << i.save();
    outFile << "\n";
  };

  for (Van i : vect_van){
    outFile << i.save();
    outFile << "\n";
  };
  
  std::cout << "SUCCESS: File appended.\n";
  outFile.close();
}

/*
  create a new file and write all vector data in it
  @param filename 
  @return void
 */

void createFile(const std::string& filename){
  std::ofstream outFile(filename);
  for (Car i : vect_car){
    outFile << i.save();
    outFile << "\n";
  };

  for (Motorcycle i : vect_bike){
    outFile << i.save();
    outFile << "\n";
  };

  for (Van i : vect_van){
    outFile << i.save();
    outFile << "\n";
  };
  
  std::cout << "SUCCESS: Data written in new file.\n";
  outFile.close();

}

/*
  user inputs a filename
  user chooses how to write to a file
  if existing = rewrite or append
  if not existing = create or not
  return to menu if invalid input or user chooses to
  @param none 
  @return void
*/

void writeFile(){
  // std::ofstream outFile;
  std::string fileOutput;
  char rewriteChoice;
  char createChoice;

  std::cout << "\n";
  std::cout << "==============================================";
  std::cout << "\n SAVE ALL VEHICLES TO FILE";
  std::cout << "Enter filename: ";
  std::cin >> fileOutput;
  
  if (file_exists(fileOutput)){
    std::cout << "\nMESSAGE - WARNING: This file already exists. \
\n 'R' to Rewrite contents \n 'A' to append to file \n	       \
 'M' to go back to Menu: \n ";
    std::cout << "ENTER CHOICE: ";
    std::cin >> rewriteChoice;
    if (rewriteChoice == 'R')
      truncateFile(fileOutput);
    else if (rewriteChoice == 'A')
      appendFile(fileOutput);
    else if (rewriteChoice == 'M')
      std::cout << "\n";
    else{
      std::cout << "ERROR: Invalid choice. \n";
      
    }
  }
  else{
    std::cout << "MESSAGE - WARNING: This file does not exist.\n\
 Create file? (Y/N) \n \
 'M' to go back to Menu: \n";
    std::cout << "ENTER CHOICE: ";
    std::cin >> createChoice;
    if (createChoice == 'Y')
      createFile(fileOutput);
    else if (createChoice == 'N'){
      std::cout << "MESSAGE: File was not created. \n";
      
    }
    else if (createChoice == 'M')
      std::cout << "\n";
    else{
      std::cout << "ERROR: Invalid choice. \n";
  
    }
  }
};

