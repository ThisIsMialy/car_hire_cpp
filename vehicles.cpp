/*
  vehicles.cpp - source file for vehicle base class
  Student ID: M00837954
  Created: 19/12/2022
  Updated: 29/12/2022
*/

#include "vehicles.h"
#include <string>
#include <iostream>

Vehicle::Vehicle( std::string make,
		  std::string model,
		  std::string registration,
		  std::string colour,
		  std::string pricePerDay,
		  std::string availabilityStatus,
		  std::string returnDate )
{
  this->make = make;
  this->model = model;
  this->registration = registration;
  this->colour = colour;
  this->pricePerDay = pricePerDay;
  this->availabilityStatus = availabilityStatus;
  this->returnDate = returnDate;
  
}

Vehicle::~Vehicle(){
}

// return make, model, reg, availabity
std::string Vehicle::listing()
{
  return make + "\t\t\t" + model + "\t\t\t" +
    registration + "\t\t\t" + availabilityStatus + "\t\t\t";
}

std::string Vehicle::details()
{
  return "Make: " + make + "\n" +
    "Model: " + model + "\n" +
    "Registration: " + registration + "\n" +
    "Colour: " + colour + "\n" +
    "Price per Day: " + pricePerDay + "\n" +
    "Available: " + availabilityStatus + "\n" +
    "Return Date: " + returnDate + "\n";
}

/*
  get methods for all attributes
  @return std::string for all
 */
std::string Vehicle::getMake(){
  return make;
};

std::string Vehicle::getModel(){
  return model;
}

std::string Vehicle::getReg(){
  return registration;
}

std::string Vehicle::getColour(){
  return colour;
}

std::string Vehicle::getPrice(){
  return pricePerDay;
}

std::string Vehicle::getAvail(){
  return availabilityStatus;
}

std::string Vehicle::getDate(){
  return returnDate;
}




