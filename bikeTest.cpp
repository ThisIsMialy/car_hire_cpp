#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "motorcycle.h"
#include "vehicles.h"

/*to run test:
  g++ -c motorcycle.cpp
  g++ -o bikeTest vehicles.o motorcycle.o bikeTest.cpp
  ./bikeTest
 */
Motorcycle bike("make", "model", "reg",
	  "colour", "price", "avail",
	  "date",
	  "engine", "passenger", "luggage");


TEST_CASE("constructor"){
  
  REQUIRE(bike.save() == "bike:make:model:price:engine:passenger:luggage:reg:colour:avail:date");
};



TEST_CASE("details"){
  
  REQUIRE(bike.displayDetails() == "\nDisplaying details... \n \
    VEHICLE TYPE: MOTORCYCLE \n" +
	  bike.details() +
	  "Engine Size: engine\n" +
	  "Passenger: passenger\n" +
	  "Luggage: luggage\n");
};

TEST_CASE("listing"){
  REQUIRE(bike.listing() == "make\t\t\tmodel\t\t\treg\t\t\tavail\t\t\t");
};

TEST_CASE("Vehicle::details()"){
  REQUIRE(bike.details() == "Make: make\nModel: model\nRegistration: reg\nColour: colour\nPrice per Day: price\nAvailable: avail\nReturn Date: date\n");
};

