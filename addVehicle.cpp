// created: 10/12/2022
// updated: 29/12/2022

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>
#include <sstream>

#include "vehicles.h"
#include "car.h"
#include "motorcycle.h"
#include "van.h"
#include "addVehicle.h"


extern std::vector<Car> vect_car;
extern std::vector<Motorcycle> vect_bike;
extern std::vector<Van> vect_van;



void createCar(const std::string& make,
	       const std::string& model,
	       const std::string& registration,
	       const std::string& colour,
	       const std::string& pricePerDay,
	       const std::string& availabilityStatus,
	       const std::string& returnDate,
	       const std::string& engineSizeLT,
	       const std::string& numberOfSeats,
	       const std::string& numberDoors){
  Car car(make,
	  model,
	  registration,
	  colour,
	  pricePerDay,
	  availabilityStatus,
	  returnDate,
	  engineSizeLT,
	  numberOfSeats,
	  numberDoors);
  
  // std::cout << car.listing();
  // std::cout << car.displayDetails();
  vect_car.push_back(car);
  // std::cout << vect_car[0].listing();
  // std::cout << vect_car[0].displayDetails();
  std::cout << "CAR CREATED!\n";
};

void createMotorcycle(const std::string& make,
		      const std::string& model,
		      const std::string& registration,
		      const std::string& colour,
		      const std::string& pricePerDay,
		      const std::string& availabilityStatus,
		      const std::string& returnDate,
		      const std::string& engineSizeCC,
		      const std::string& passengerSeat,
		      const std::string& luggageSpace){
  Motorcycle motorcycle(make,
			model,
			registration,
			colour,
			pricePerDay,
			availabilityStatus,
			returnDate,
			engineSizeCC,
			passengerSeat,
			luggageSpace);
  
  vect_bike.push_back(motorcycle);
  std::cout << "\n BIKE CREATED!\n";

};


void createVan(const std::string& make,
	       const std::string& model,
	       const std::string& registration,
	       const std::string& colour,
	       const std::string& pricePerDay,
	       const std::string& availabilityStatus,
	       const std::string& returnDate,
	       const std::string& engineSizeLT,
	       const std::string& numberOfSeats,
	       const std::string& luggageSpace){
  Van van(make,
	  model,
	  registration,
	  colour,
	  pricePerDay,
	  availabilityStatus,
	  returnDate,
	  engineSizeLT,
	  numberOfSeats,
	  luggageSpace);
  
  vect_van.push_back(van);
  std::cout << "\n VAN CREATED!\n";

};
/* validate string to accept only letters and spaces
 @param std::string strToValidate
 @return boolean
*/


bool validateString(const std::string& strToValidate){
  for (const char c : strToValidate){
    if(!isalpha(c))
      return false;
  };
  return true;
};

/* registration 2 letters, 2 numbers, 3 letters
 @param std::string
 @return bool*/
bool validateReg (const std::string& strToValidate){
  if (strToValidate.length() == 7 &&
      isalpha(strToValidate[0]) &&
      isalpha(strToValidate[1]) &&
      isdigit(strToValidate[2]) &&
      isdigit(strToValidate[3]) &&
      isalpha(strToValidate[4]) &&
      isalpha(strToValidate[5]) &&
      isalpha(strToValidate[6]) ){
     return true;
   }
   else {
     return false;
   };
};


void invalidInput (const std::string& type){
  std::cout << "ERROR: [" + type + "] was not valid input. Pls retry \n";
};

std::string enterMake(){
  std::string make;
  std::cout << "\n[string] Enter make: ";
  std::cin >> make;
  if (!validateString(make)){
    invalidInput("make");
    make = "none";
  }
  return make;
  
};


std::string enterModel(){
  std::string model;
  std::cout << "\n[string] Enter model: ";
  std::cin >> model; 

  if (!validateString(model)){
    invalidInput("model");
    model = "none";
  }
  return model;  
};

std::string enterReg(){
  std::string upperReg;
  std::string registration;
  std::cout << "\n[string] Enter registration: ";
  std::cin >> registration; 

  if (!validateReg(registration)){
    invalidInput("registration");
    registration = "none";
  };
  
  for (long unsigned int i=0; i<registration.length(); i++)
        upperReg += toupper(registration[i]);
  
  return upperReg;  
};

std::string enterColour(){
  std::string colour;
  std::cout << "\n[string] Enter colour: ";
  std::cin >> colour; 

  if (!validateString(colour)){
    invalidInput("colour");
    colour = "none";
  }
  return colour;  
};

std::string enterPrice(){
  int priceInt;
  std::cout << "\n[int] Enter price: £ ";
  while (!(std::cin >> priceInt)){
    invalidInput("price");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none";
  };
  return "£" +  priceInt;
};

std::string enterStatus(){
  char status;
  std::cout << "\n[char] Is vehicle available? Y or N: ";
  std::cin >> status;
  if (status == 'Y')
    return "Yes";
  else if (status == 'N')
    return "No";
  else {
    invalidInput("Availability Status");
    return "none";
  }; 
};

std::string enterDate(){
  time_t now = time(0);
  tm *ltm = localtime(&now);

  const int yearNow = 1900 + ltm->tm_year;
  const int monNow = 1 + ltm->tm_mon;
  const int dayNow = ltm->tm_mday;
  
  int day;
  int month;
  int year;

  std::cout << "current month: " + std::to_string(monNow);
  std::cout << "\n[int] Enter YEAR of return date: ";
  

  while(!(std::cin >> year)){
    invalidInput("date{year}");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none"; 
  };
  
  if ((year < yearNow) || (year > yearNow + 2 )){
    invalidInput("date{year}");
    return "none";
  };

  std::cout << "\n[int] Enter MONTH of return date: ";

  while(!(std::cin >> month)){
    invalidInput("date{month}");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none"; 
  };

  if (!( (month >= 1) || (month <= 12)  )){
    invalidInput("date{month}");
    return "none";
  };

  if (year == yearNow){
    if (month < monNow){
      invalidInput("date{month}");
      return "none";
    };
  };
  
  std::cout << "\n[int] Enter DAY of return date: ";

  while(!(std::cin >> day)){
    invalidInput("date{day}");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none"; 
  };

  if (!( (day >= 1) || (day <= 31)  )){
    invalidInput("date{day}");
    return "none";
  };

  if (year == yearNow){
    if (month == monNow){
      if (day < dayNow){
	invalidInput("date{day}");
	return "none";
      };
    };
  };
 
  return std::to_string(day) + "/" + std::to_string(month) + "/" \
    + std::to_string(year) + "\n";      
};

std::string enterEngine(){
  float engineSize;
  std::stringstream ss;
  
  std::cout << "\n[decimal] Enter engine size (in Litres): ";
  

  while(!(std::cin >> engineSize)){
    invalidInput("engine size");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none"; 
  };

  ss << engineSize << "L";
  return ss.str();
  // return std::to_string(engineSize) + " L";
};

std::string enterLuggageSpaceCM(){
  float luggageSpace;
  std::stringstream ss;
  
  std::cout << "\n[decimal] Enter luggage space (in cubic meters): ";
  
  while(!(std::cin >> luggageSpace)){
    invalidInput("Luggage space {cubic meters}");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none"; 
  };

  ss << luggageSpace << " cubic meters luggage space";
  return ss.str();
  
};


std::string enterSeats(){
  int numSeats;

  std::cout << "\n[int] Enter number of seats: ";
  while(!(std::cin >> numSeats)){
    invalidInput("number of seats");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none"; 
  };
  if (numSeats < 1){
    return "none";
  };
    
  return std::to_string(numSeats) + " seats";
};
  
std::string enterDoors(){
  int numDoors;

  std::cout << "\n[int] Enter number of doors: ";
  while((!(std::cin >> numDoors))){
    invalidInput("number of doors");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none"; 
  };

  if (numDoors < 1){
    return "none";
  };
  return std::to_string(numDoors) + " door";   
};



std::string enterEngineCC(){
  int engineSize;

  std::cout << "\n[int] Enter engine size in CC: ";
  while((!(std::cin >> engineSize))){
    invalidInput("engine size {in CC}");
    std::cin.clear();
    std::cin.ignore(123, '\n');
    return "none"; 
  };

  if (engineSize < 1){
    return "none";
  };
  return std::to_string(engineSize) + "cc";
};


std::string enterPassengerSeat(){
  char hasPassenger;
  std::cout << "\n[char] Has Passenger Seat? Y or N: ";
  std::cin >> hasPassenger;
  if (hasPassenger == 'Y')
    return "Passenger seat";
  else if (hasPassenger == 'N')
    return "No passenger";
  else {
    invalidInput("Has Passenger Seat");
    return "none";
  };
};

 
std::string enterLuggageSpace(){
  char hasLuggage;
  std::cout << "\n[char] Has Luggage Space? Y or N: ";
  std::cin >> hasLuggage;
  if (hasLuggage == 'Y')
    return "Has luggage";
  else if (hasLuggage == 'N')
    return "No luggage";
  else {
    invalidInput("Has Luggage Space");
    return "none";
  };
};


void addCar(){
  bool notValidated  = true; 
  std::cout << "==============================";
  std::cout << "\n VEHICLE CATEGORY : CAR \n";
  std::cout << "Follow the appropriate data types. \n";

  std::string make;
  std::string model;
  std::string registration;
  std::string colour;
  std::string pricePerDay;
  std::string availabilityStatus;
  std::string returnDate;
  
  std::string engineSizeLT;
  std::string numberOfSeats;
  std::string numberDoors;

  while (notValidated){
    
    make = enterMake();
    if (make == "none")
      break;
   
    model = enterModel();
    if (model == "none")
      break;

    registration = enterReg();
    if (registration == "none")
      break;

    colour = enterColour();
    if (colour == "none")
      break;

    pricePerDay = enterPrice();
    if (pricePerDay == "none")
      break;

    availabilityStatus = enterStatus();
    if (availabilityStatus == "none")
      break;

    if (availabilityStatus == "No"){
      returnDate = enterDate();
      if (returnDate == "none")
	break;
    }else if (availabilityStatus == "Yes"){
      returnDate = "N\\A";
    };

    engineSizeLT = enterEngine();
    if (engineSizeLT == "none")
      break;

    numberOfSeats = enterSeats();
    if (numberOfSeats == "none")
      break;

    numberDoors = enterDoors();
    if (numberDoors == "none")
      break;
  

  notValidated = false;
  createCar(make, model, registration,
	    colour, pricePerDay, availabilityStatus,
	    returnDate, engineSizeLT,
	    numberOfSeats, numberDoors);
  };

};

void addMotorcycle(){

  bool notValidated  = true; 
  std::cout << "==============================";
  std::cout << "\n VEHICLE CATEGORY : MOTORCYCLE \n";
  std::cout << "Follow the appropriate data types. \n";

  std::string make;
  std::string model;
  std::string registration;
  std::string colour;
  std::string pricePerDay;
  std::string availabilityStatus;
  std::string returnDate;
  
  std::string engineSizeCC;
  std::string passengerSeat;
  std::string luggageSpace;

  while (notValidated){
    
    make = enterMake();
    if (make == "none")
      break;
   
    model = enterModel();
    if (model == "none")
      break;

    registration = enterReg();
    if (registration == "none")
      break;

    colour = enterColour();
    if (colour == "none")
      break;

    pricePerDay = enterPrice();
    if (pricePerDay == "none")
      break;

    availabilityStatus = enterStatus();
    if (availabilityStatus == "none")
      break;

    if (availabilityStatus == "No"){
      returnDate = enterDate();
      if (returnDate == "none")
	break;
    }else if (availabilityStatus == "Yes"){
      returnDate = "N\\A";
    };

     
    engineSizeCC = enterEngineCC();
    if (engineSizeCC == "none")
      break;

    passengerSeat = enterPassengerSeat();
    if (passengerSeat == "none")
      break;

    luggageSpace = enterLuggageSpace();
    if (luggageSpace == "none")
      break;
  

  notValidated = false;
  createMotorcycle(make, model, registration,
		   colour, pricePerDay, availabilityStatus,
		   returnDate,
		   engineSizeCC,
		   passengerSeat, luggageSpace);
  };

  
};

void addVan(){

  bool notValidated  = true; 
  std::cout << "==============================";
  std::cout << "\n VEHICLE CATEGORY : VAN \n";
  std::cout << "Follow the appropriate data types. \n";

  std::string make;
  std::string model;
  std::string registration;
  std::string colour;
  std::string pricePerDay;
  std::string availabilityStatus;
  std::string returnDate;
  
  std::string engineSizeLT;
  std::string numberOfSeats;
  std::string luggageSpace;

  while (notValidated){
    
    make = enterMake();
    if (make == "none")
      break;
   
    model = enterModel();
    if (model == "none")
      break;

    registration = enterReg();
    if (registration == "none")
      break;

    colour = enterColour();
    if (colour == "none")
      break;

    pricePerDay = enterPrice();
    if (pricePerDay == "none")
      break;

    availabilityStatus = enterStatus();
    if (availabilityStatus == "none")
      break;

    if (availabilityStatus == "No"){
      returnDate = enterDate();
      if (returnDate == "none")
	break;
    }else if (availabilityStatus == "Yes"){
      returnDate = "N\\A";
    };
    
    engineSizeLT = enterEngine();
    if (engineSizeLT == "none")
      break;

    numberOfSeats = enterSeats();
    if (numberOfSeats == "none")
      break;

    luggageSpace = enterLuggageSpaceCM();
    if (luggageSpace == "none")
      break;
  

  notValidated = false;
  createVan(make, model, registration,
	    colour, pricePerDay, availabilityStatus,
	    returnDate,
	    engineSizeLT,
	    numberOfSeats, luggageSpace);
  };

  
};



void addingMenu(){
  bool runProgram = true;
  
  while(runProgram){
    char choice;
  
    std::cout << "\n ADDING VEHICLE \n";
    std::cout << "==============================================";
    std::cout << "\n 'C' CAR \n 'M' MOTORCYCLE \n 'V' VAN \n \
'Q' to Quit \n";

    std::cout << "ENTER CHOICE: ";
    std::cin >> choice;

    if (choice == 'C')
      addCar();
    else if (choice == 'M')
      addMotorcycle();
    else if (choice == 'V')
      addVan();
    else if (choice == 'Q')
      runProgram = false;
    else{
      std::cout << "ERROR: Invalid choice. \n";
    };
  }
};

// driver - call menu()
// int main(){
//   menu();
//   return 0;
// };

