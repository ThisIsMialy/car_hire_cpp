/*
  motorcycle.cpp
  Student ID: M00837954
  Created: 19/12/2022
  Updated: 13/01/2023
*/

#include "motorcycle.h"
#include <string>

Motorcycle::Motorcycle(
		       std::string make,
		       std::string model,
		       std::string registration,
		       std::string colour,
		       std::string pricePerDay,
		       std::string availabilityStatus,
		       std::string returnDate,
		       std::string engineSizeCC,
		       std::string passengerSeat,
		       std::string luggageSpace):Vehicle(make,
							 model,
							 registration,
							 colour,
							 pricePerDay,
							 availabilityStatus,
							 returnDate)
		       
{
  this->engineSizeCC = engineSizeCC;
  this->passengerSeat = passengerSeat;
  this->luggageSpace = luggageSpace;
};

Motorcycle::~Motorcycle(){
};

/*
  display all details
 */
std::string Motorcycle::displayDetails()
{
  return "\nDisplaying details... \n \
    VEHICLE TYPE: MOTORCYCLE \n"+
    details() +
    "Engine Size: " + engineSizeCC + "\n"+
    "Passenger: " + passengerSeat + "\n"+    
    "Luggage: " + luggageSpace + "\n";
   
};

/*
  for saving in files
 */
std::string Motorcycle::save()
{
  return "bike:"+getMake()+":"+getModel()+":"+getPrice()+":"+engineSizeCC+":"+passengerSeat+":"+luggageSpace+":"+getReg()+":"+getColour()+":"+getAvail()+":"+getDate();
};

