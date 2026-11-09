#ifndef _CAR_H_
#define _CAR_H_

/*
  car.h
  Student ID: M00837954
  Created: 06/12/2022
  Updated: 12/01/2023
*/

#include <string>
#include <iostream>
#include "vehicles.h"

// Car class

class Car: public Vehicle
{
 private:
  std::string engineSizeLT;
  std::string numberOfSeats;
  std::string numberDoors;
  
 public:
  Car(
      std::string make,
      std::string model,
      std::string registration,
      std::string colour,
      std::string pricePerDay,
      std::string availabilityStatus,
      std::string returnDate,
  
      std::string engineSizeLT,
      std::string numberOfSeats,
      std::string numberDoors
      );
  
  ~Car();
  
  std::string displayDetails();

  std::string save();
  
  
};


#endif
    
	     
