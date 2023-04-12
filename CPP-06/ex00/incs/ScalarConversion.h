//
// Created by aurel on 4/12/23.
//

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <limits>
#include <stdint.h>
#include <cmath>
using std::string;
using std::cout;
using std::endl;
using std::numeric_limits;

# define INT 0
# define FLOAT 1
# define DOUBLE 2
# define CHAR 3
# define ERROR 4


class ScalarConversion
{
public:
	static void convert( string litteral );
private:
	static int findEntryType(string litteral) ;

	static bool checkInt(string litteral) ;
	static bool checkFloat(string litteral) ;
	static bool checkDouble(string litteral) ;
	static bool checkChar(string litteral) ;

	static void convertInt(string litteral);
	static void convertFloat(string litteral);
	static void convertDouble(string litteral);
	static void convertChar(string litteral);


};