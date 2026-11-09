CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic
RM = rm
OBJ = car.o vehicles.o motorcycle.o van.o addVehicle.o open_file.o 

.PHONY : all
all : program

program : main-adding.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

vehicles.o : vehicles.cpp vehicles.h
	$(CXX) $(CXXFLAGS) -c $<

car.o : car.cpp car.h
	$(CXX) $(CXXFLAGS) -c $<

motorcycle.o : motorcycle.cpp motorcycle.h
	$(CXX) $(CXXFLAGS) -c $<

van.o : van.cpp van.h
	$(CXX) $(CXXFLAGS) -c $<

addVehicle.o : addVehicle.cpp addVehicle.h
	$(CXX) $(CXXFLAGS) -c $<

open_file.o : open_file.cpp open_file.h
	$(CXX) $(CXXFLAGS) -c $<


.PHONY: clean
clean:
	$(RM) *.o
	$(RM) program
