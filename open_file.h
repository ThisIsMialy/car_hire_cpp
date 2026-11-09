#ifndef _OPENFILE_H_
#define _OPENFILE_H_

/*
  open_file.h
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

void fileMenu();
bool file_exists (const std::string& filename);
void loadFile();
void truncateFile(const std::string& filename);
void appendFile(const std::string& filename);
void writeFile();
void stringSplit(const std::string& line);
void turnIntoClass(std::vector<std::string>& vect);


#endif
