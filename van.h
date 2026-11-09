#ifndef _VAN_H_
#define _VAN_H_

/*
  van.h
  Student ID: M00837954
  Created: 06/12/2022
  Updated: 29/12/2022
*/

#include <string>
#include <iostream>
#include "vehicles.h"

// Van class

class Van: public Vehicle
{
 private:
  std::string engineSizeLT;
  std::string numberOfSeats;
  std::string luggageSpace;
  
 public:
  Van(
      std::string make,
      std::string model,
      std::string registration,
      std::string colour,
      std::string pricePerDay,
      std::string availabilityStatus,
      std::string returnDate,
      
      std::string engineSizeLT,
      std::string numberOfSeats,
      std::string luggageSpace
      );
  ~Van();
  std::string displayDetails();
  std::string save();
  
  
};

#endif
