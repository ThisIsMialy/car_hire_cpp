#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "vehicles.h"
#include "car.h"
#include "motorcycle.h"
#include "van.h"
#include "addVehicle.h"

/* to test:
   g++ -c addVehicle.cpp
   g++ -o addVehicleTest vehicles.o van.o car.o motorcycle.o addVehicle.o addVehicleTest.cpp
   ./addvehicleTest
 */

Car car("make", "model", "reg",
	  "colour", "price", "avail",
	  "date",
	  "engine", "seats", "doors");

Motorcycle bike("make", "model", "reg",
		"colour", "price", "avail",
		"date",
		"engine", "passenger", "luggage");

Van van("make", "model", "reg",
	"colour", "price", "avail",
	"date",
	"engine", "seats", "luggage");


/*temporary vectors*/
std::vector<Car> vect_car;
std::vector<Motorcycle> vect_bike;
std::vector<Van> vect_van;

TEST_CASE("validate only alpha", "[validateString]")
{
  REQUIRE(validateString("hello") == true);
  REQUIRE(validateString("HELLOWORLD") == true);
  REQUIRE(validateString("Ford") == true);
  REQUIRE(validateString("VeryLongStringsAreAllowed") == true);
  REQUIRE(validateString("d") == true);
  REQUIRE(validateString("U") == true);

  REQUIRE(validateString("hello123") == false);
  REQUIRE(validateString("123strings") == false);
  REQUIRE(validateString("space not allowed") == false);
  REQUIRE(validateString("$ymbols!£$%^&*()") == false);
  REQUIRE(validateString("Combinations & not & allowed") == false);
};

TEST_CASE("validate registration - ", "[validateReg]")
{
  REQUIRE(validateReg("we12yes") == true);
  REQUIRE(validateReg("uu12olk") == true);
  REQUIRE(validateReg("yh78eDs") == true);
  REQUIRE(validateReg("HJ90fef") == true);
  REQUIRE(validateReg("JU90dFT") == true);
  REQUIRE(validateReg("ER57Thd") == true);
  REQUIRE(validateReg("ev14SWD") == true);
  REQUIRE(validateReg("QK89JHD") == true);

  REQUIRE(validateReg("juststring") == false);
  REQUIRE(validateReg("jj 89 kgg") == false);
  REQUIRE(validateReg("$g78hed") == false);
  REQUIRE(validateReg("REGnbsdj") == false);
  REQUIRE(validateReg("78JKSHWS") == false);
};



SCENARIO("Testing vectors: vect_car", "[vector]")
{
  GIVEN ("Car vector with a one element"){
    vect_car.clear();
    vect_car.push_back(car);

    REQUIRE (vect_car.size() == 1);

    WHEN ("One element added"){
      vect_car.push_back(car);

      REQUIRE (vect_car.size() == 2);
    }

    WHEN ("Multiple elements added"){
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.push_back(car);
      

      REQUIRE (vect_car.size() == 9);
    }

     WHEN ("First element is removed"){
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.push_back(car);
     
      vect_car.erase(vect_car.begin());

      REQUIRE (vect_car.size() == 4);
    }
    

    WHEN ("The vector is cleared"){
      vect_car.push_back(car);
      vect_car.push_back(car);
      vect_car.clear();

      REQUIRE (vect_car.size() == 0);
    }
    
  };
};

SCENARIO("Testing vectors: vect_bike", "[vector]")
{
  GIVEN ("Motorcycle vector with a one element"){
    vect_bike.clear();
    vect_bike.push_back(bike);

    REQUIRE (vect_bike.size() == 1);

    WHEN ("One element added"){
      vect_bike.push_back(bike);

      REQUIRE (vect_bike.size() == 2);
    }

    WHEN ("Multiple elements added"){
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      

      REQUIRE (vect_bike.size() == 6);
    }

     WHEN ("Last element is removed"){
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
     
     
      vect_bike.erase(vect_bike.end());

      REQUIRE (vect_bike.size() == 7);
    }
    
    WHEN ("The vector is cleared"){
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.push_back(bike);
      vect_bike.clear();

      REQUIRE (vect_bike.size() == 0);
    }
    
  };
};

SCENARIO("Testing vectors: vect_van", "[vector]")
{
  GIVEN ("Van vector with a one element"){
    vect_van.clear();
    vect_van.push_back(van);

    REQUIRE (vect_van.size() == 1);

    WHEN ("One element added"){
      vect_van.push_back(van);

      REQUIRE (vect_van.size() == 2);
    }

    WHEN ("Multiple elements added"){
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      

      REQUIRE (vect_van.size() == 10);
    }

     WHEN ("First, last and random element is removed"){
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
     
      vect_van.erase(vect_van.begin());
      vect_van.erase(vect_van.begin() + 2);
      vect_van.erase(vect_van.end());

      REQUIRE (vect_van.size() == 5);
    }
    
    

    WHEN ("The vector is cleared"){
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      vect_van.push_back(van);
      
      vect_van.clear();

      REQUIRE (vect_van.size() == 0);
    }
    
  };
};
 

