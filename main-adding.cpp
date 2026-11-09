/*
  main-adding.cpp
  Student ID: M00837954
  Created: 19/12/2022
  Updated: 13/01/2023
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
 
#include "vehicles.h"
#include "car.h"
#include "motorcycle.h"
#include "van.h"
#include "addVehicle.h"
#include "open_file.h"

/*
  main vectors init
 */
std::vector<Car> vect_car;
std::vector<Motorcycle> vect_bike;
std::vector<Van> vect_van;

/*
  functions declaration
 */
void loadVehicles();
void saveVehicles();
void addVehicle();
void removeVehicle();
void listAllVehicles();
void displayVehicle();
void mainMenu();

/*
  all void loadVehicles(), saveVehicles(), addVehicle()
  calls their respective functions from open_file.h/.cpp
  @param = none
 */
void loadVehicles(){
  loadFile();
}

void saveVehicles(){
  writeFile();
  
}

void addVehicle(){
  addingMenu();
}

/*
  removes vehicle from respective vector
  @param = none
 */
void removeVehicle(){
  std::cout << "Remove a vehicle" << std::endl;

  std::string reg;
  int index = 0;
  reg = enterReg();

  if (!(reg == "none")){
    for (Car i : vect_car){
      if (i.getReg() == reg){;
	vect_car.erase(vect_car.begin() + index);
	std::cout << reg + "Deleted successfully. \n";
      };
      index++;
    };
    
    index = 0;
    for (Motorcycle i : vect_bike){
      if (i.getReg() == reg){;
	vect_bike.erase(vect_bike.begin() + index);
	std::cout << reg + "Deleted successfully. \n";
      };
      index++;
    };
    
    index = 0;
    for (Van i : vect_van){
      if (i.getReg() == reg){;
	vect_van.erase(vect_van.begin() + index);
	std::cout << reg + "Deleted successfully. \n";
      };
      index++;
    };
  };
  
}

/*
  call method .listing for all elements in all vectors
  display in table format
  @param = none
 */
void listAllVehicles(){
  std::cout << "Listing all vehicles" << std::endl;
  std::cout << "\n============================================================\n";
  std::cout << "Make\t\t\tModel\t\t\tRegNo\t\t\tAvailable\n";

  // for (Car i : vect_car){
  //   std::cout << i.listing();
  //   std::cout << "\n";
  // };

  for (Motorcycle i : vect_bike){
    std::cout << i.listing();
    std::cout << "\n";
  };

  for (Van i : vect_van){
    std::cout << i.listing();
    std::cout << "\n";
  };

  std::cout << "\n============================================================\n";
}

/*
  enter and validate registration
  call method .displayDetails for one element
  display in table format
  @param = none
 */
void displayVehicle(){
  std::string reg;
  reg = enterReg();

  if (!(reg == "none")){
    for (Car i : vect_car){
      if (i.getReg() == reg){
	std::cout << i.displayDetails();
      };
    };

    for (Motorcycle i : vect_bike){
      if (i.getReg() == reg){
	std::cout << i.displayDetails();
      };
    };

    for (Van i : vect_van){
      if (i.getReg() == reg){
	std::cout << i.displayDetails();
      };
    };
  }else {
    std::cout << "\nERROR: No vehicle found.\n";
    
  };
    
}

/*
  mainMenu for the program
  all 6 functionalities
  @param = none
 */

void mainMenu(){
  bool runProgram = true;
  
  int choice;

  while(runProgram)
    {
      std::cout<<"===================================================== \n";
      std::cout<<"\t  MAIN MENU  \t"<<std::endl;
      std::cout<<"1. Load vehicles"<<std::endl;
      std::cout<<"2. Save current vehicles to a file"<<std::endl;
      std::cout<<"3. Add a vehicle"<<std::endl;
      std::cout<<"4. Remove a vehicle"<<std::endl;
      std::cout<<"5. List all vehicles "<<std::endl;
      std::cout<<"6. Display all details of a vehicle"<<std::endl;
      std::cout<<"7. Quit \n"<<std::endl;
      std::cout<<"Enter a number: ";
      std::cin>>choice;

      if (choice == 1)
	loadVehicles();
      else if (choice == 2)
	saveVehicles();
      else if (choice == 3)
	addVehicle();
      else if (choice == 4)
	removeVehicle();
      else if (choice == 5)
	listAllVehicles();
      else if (choice == 6)
	displayVehicle();
      else if (choice == 7)
        runProgram = false;
      else{
	std::cout << "ERROR: Invalid choice. \n";
      };
    };
};


// driver 
int main(){
  mainMenu();
  return 0;
}

