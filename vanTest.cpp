#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "van.h"
#include "vehicles.h"

/*to run test:
  g++ -c van.cpp
  g++ -o vanTest vehicles.o van.o vanTest.cpp
  ./vanTest
 */
Van van("make", "model", "reg",
	  "colour", "price", "avail",
	  "date",
	  "engine", "seats", "luggage");


TEST_CASE("constructor"){
  
  
  REQUIRE(van.save() == "van:make:model:price:engine:seats:luggage:reg:colour:avail:date");
};

TEST_CASE("details"){
  
  REQUIRE(van.displayDetails() == "\nDisplaying details... \n \
    VEHICLE TYPE: VAN \n" +
	  van.details() +
	  "Engine Size: engine\n" +
	  "Seats: seats\n" +
	  "Luggage: luggage\n" );
};

TEST_CASE("listing"){
  REQUIRE(van.listing() == "make\t\t\tmodel\t\t\treg\t\t\tavail\t\t\t");
};

TEST_CASE("Vehicle::details()"){
  REQUIRE(van.details() == "Make: make\nModel: model\nRegistration: reg\nColour: colour\nPrice per Day: price\nAvailable: avail\nReturn Date: date\n");
};

