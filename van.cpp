/*
  van.cpp
  Student ID: M00837954
  Created: 19/12/2022
  Updated: 13/01/2023
*/
#include "van.h"
#include <string>
#include "vehicles.h"

/*
  constructor and call base Vehicle
 */
Van::Van(
	 std::string make,
	 std::string model,
	 std::string registration,
	 std::string colour,
	 std::string pricePerDay,
	 std::string availabilityStatus,
	 std::string returnDate,
	 std::string engineSizeLT,
	 std::string numberOfSeats,
	 std::string luggageSpace):Vehicle(make,
					   model,
					   registration,
					   colour,
					   pricePerDay,
					   availabilityStatus,
					   returnDate)

{
  this->engineSizeLT = engineSizeLT;
  this->numberOfSeats = numberOfSeats;
  this->luggageSpace = luggageSpace;
}

Van::~Van()
{
};

/*
  display all details
 */
std::string Van::displayDetails()
{
  return "\nDisplaying details... \n \
    VEHICLE TYPE: VAN \n"+
    details() +
    "Engine Size: " + engineSizeLT + "\n"+
    "Seats: " + numberOfSeats + "\n"+ 
    "Luggage: " + luggageSpace + "\n";
}

/*
  for saving in files
 */
std::string Van::save()
{
  return "van:"+getMake()+":"+getModel()+":"+getPrice()+":"+engineSizeLT+":"+numberOfSeats+":"+luggageSpace+":"+getReg()+":"+getColour()+":"+getAvail()+":"+getDate();
};
