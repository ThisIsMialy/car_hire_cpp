#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "car.h"
#include "vehicles.h"

/*to run test:
  g++ -c car.cpp
  g++ -o carTest vehicles.o car.o carTest.cpp
  ./carTest
 */
Car car("make", "model", "reg",
	  "colour", "price", "avail",
	  "date",
	  "engine", "seats", "doors");

TEST_CASE("constructor"){
  
  REQUIRE(car.save() == "car:make:model:price:engine:seats:doors:reg:colour:avail:date");
};

TEST_CASE("listing"){
  REQUIRE(car.listing() == "make\t\t\tmodel\t\t\treg\t\t\tavail\t\t\t");
};

TEST_CASE("display full details"){
  
  REQUIRE(car.displayDetails() == "\nDisplaying details... \n \
    VEHICLE TYPE: CAR \n" +
	  car.details() +
	  "Engine Size: engine\n" +
	  "Seats: seats\n" +
	  "Doors: doors\n" );
};

TEST_CASE("Vehicle::details()"){
  REQUIRE(car.details() == "Make: make\nModel: model\nRegistration: reg\nColour: colour\nPrice per Day: price\nAvailable: avail\nReturn Date: date\n");
};

