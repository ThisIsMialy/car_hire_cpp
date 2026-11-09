/*
  car.cpp
  Student ID: M00837954
  Created: 19/12/2022
  Updated: 13/01/2023
*/

#include "car.h"
#include "vehicles.h"
#include <string>

/*
  constructor and call base Vehicle
 */
Car::Car(std::string make,
	 std::string model,
	 std::string registration,
	 std::string colour,
	 std::string pricePerDay,
	 std::string availabilityStatus,
	 std::string returnDate,
	 std::string engineSizeLT,
	 std::string numberOfSeats,
	 std::string numberDoors):Vehicle(make,
				  model,
				  registration,
				  colour,
				  pricePerDay,
				  availabilityStatus,
				  returnDate)
{ 
  this->engineSizeLT = engineSizeLT;
  this->numberOfSeats = numberOfSeats;
  this->numberDoors = numberDoors;
};

Car::~Car()
{
};

// all details of a vehicle
std::string Car::displayDetails()
{
  return "\nDisplaying details... \n \
    VEHICLE TYPE: CAR \n" +
    details() +
    "Engine Size: " + engineSizeLT + "\n" +
    "Seats: " + numberOfSeats + "\n" +
    "Doors: " + numberDoors + "\n";
  
};

/*
  for saving in files
 */
std::string Car::save()
{
  return "car:"+getMake()+":"+getModel()+":"+getPrice()+":"+engineSizeLT+":"+numberOfSeats+":"+numberDoors+":"+getReg()+":"+getColour()+":"+getAvail()+":"+getDate();
};





