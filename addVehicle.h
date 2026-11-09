#ifndef _ADDVEHICLES_H_
#define _ADDVEHICLES_H_

/*
  addVehicle.h
  Student ID: M00837954
  Created: 06/12/2022
  Updated: 12/01/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>
#include <sstream>



/*
  all functions relating to adding vehicle
  includes all user input validation
 */

bool validateString(const std::string& strToValidate);
bool validateString(const std::string& strToValidate);
bool validateReg (const std::string& strToValidate);
void addCar();
void addMotorcycle();
void addVan();
void addingMenu();
void createCar(const std::string& make,
	       const std::string& model,
	       const std::string& registration,
	       const std::string& colour,
	       const std::string& pricePerDay,
	       const std::string& availabilityStatus,
	       const std::string& returnDate,
	       const std::string& engineSizeLT,
	       const std::string& numberOfSeats,
	       const std::string& numberDoors);

void createMotorcycle(const std::string& make,
		      const std::string& model,
		      const std::string& registration,
		      const std::string& colour,
		      const std::string& pricePerDay,
		      const std::string& availabilityStatus,
		      const std::string& returnDate,
		      const std::string& engineSizeCC,
		      const std::string& passengerSeat,
		      const std::string& luggageSpace);

void createVan(const std::string& make,
	       const std::string& model,
	       const std::string& registration,
	       const std::string& colour,
	       const std::string& pricePerDay,
	       const std::string& availabilityStatus,
	       const std::string& returnDate,
	       const std::string& engineSizeLT,
	       const std::string& numberOfSeats,
	       const std::string& luggageSpace);


std::string enterMake();
std::string enterModel();
std::string enterReg();
std::string enterColour();
std::string enterPrice();
std::string enterStatus();
std::string enterDate();

std::string enterEngine();
std::string enterSeats();
std::string enterDoors();

std::string enterEngineCC();
std::string enterPassengerSeat();
std::string enterLuggageSpace();

std::string enterLuggageSpaceCM();


#endif
