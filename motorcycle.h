#ifndef _MOTORCYCLE_H_
#define _MOTORCYCLE_H_

/*
  motorcycle.h
  Student ID: M00837954
  Created: 06/12/2022
  Updated: 25/12/2022
*/

#include <string>
#include <iostream>
#include "vehicles.h"

// Motorcycle class

class Motorcycle: public Vehicle
{
 private:
  std::string engineSizeCC;
  std::string passengerSeat;
  std::string luggageSpace;
  
 public:
  Motorcycle(
	     std::string make,
	     std::string model,
	     std::string registration,
	     std::string colour,
	     std::string pricePerDay,
	     std::string availabilityStatus,
	     std::string returnDate,
	     
	     std::string engineSizeCC,
	     std::string passengerSeat,
	     std::string luggageSpace
	     );
  
  ~Motorcycle();
  std::string displayDetails();
  std::string save();
  
  
};
#endif
