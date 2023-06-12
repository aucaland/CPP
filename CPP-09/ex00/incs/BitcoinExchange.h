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
#include <regex>

using std::string;

# define DATE_PATTERN "^\\d{2}-\\d{2}-\\d{4}\\s$"

class BitcoinExchange
{
	/* Private attributs */
private:
	std::map<string, float>	_bitcoinData;

	/* Private Methods */
private:
	static bool				fileExist( const char* fileName );
	static std::ifstream	openFile( const char* fileName );
	static void				formatIsValid( const std::string & );
	static bool				timestampIsValid( const std::string &timestamp );
	void					fillMap( std::ifstream file );
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);
	BitcoinExchange(const BitcoinExchange &);

	BitcoinExchange( const char* fileName );
};

#endif //CPP_BITCOINEXCHANGE_H
