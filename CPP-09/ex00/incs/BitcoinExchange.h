//
// Created by aucaland on 4/29/23.
//

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <fstream>
#include <string>
#include <sstream>
#include "errors.h"

using std::string;

class BitcoinExchange
{
	/* Private attributs */
private:
	std::map<string, float>	_bitcoinData;

	/* Private Methods */
private:
	static bool				fileExist( const char* fileName );
	static int				inputParsing( std::ifstream &fileName );
	static void				openFile( const char *fileName, std::ifstream *file );
	static int				timestampIsValid( const std::string &timestamp );
	static void				errorsManagement( int errorCode );
	static void				inputFileErrorsManagement( int errorCode, std::string content );
	int						fillMap( std::ifstream &file );
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);
	BitcoinExchange(const BitcoinExchange &);

	BitcoinExchange( const char* fileName );
};
