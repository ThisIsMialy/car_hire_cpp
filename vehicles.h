#ifndef _VEHICLES_H_
#define _VEHICLES_H_

/*
  vehicles.h
  Student ID: M00837954
  Created: 06/12/2022
  Updated: 25/12/2022
*/

#include <string>

// Vehicle is base (abstract) class

class Vehicle
{
 private:
  std::string make;
  std::string model;
  std::string registration;
  std::string colour;
  std::string pricePerDay;
  std::string availabilityStatus;
  std::string returnDate;
  
 public:
  Vehicle(std::string make,
	  std::string model,
	  std::string registration,
	  std::string colour,
	  std::string pricePerDay,
	  std::string availabilityStatus,
	  std::string returnDate
	  );
  
  virtual ~Vehicle();
   
  std::string listing();
  std::string details();

  std::string getMake();
  std::string getModel();
  std::string getReg();
  std::string getColour();
  std::string getPrice();
  std::string getAvail();
  std::string getDate();
  
};

#endif

/*
van:Ford:Transit:£40:2L:3 seats:15.1 cubic meters luggage space:EW72RAY:red:Yes:N/A
bike:Triumph:Speedmaster:£75:1200cc:passenger seat:No luggage:QL69FLY:green:Yes:N/A
car:BMW:Mini:£50:1.1L:4 seats:3 door:TZ69ZYG:black:No:6/2/2023
*/
