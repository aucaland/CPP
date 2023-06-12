//
// Created by aucaland on 4/29/23.
//

#include "../incs/BitcoinExchange.h"

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange() {
	cout << "Constructor BitcoinExchange called" << endl;
}

BitcoinExchange::~BitcoinExchange() {
	cout << "Destructor BitcoinExchange called" << endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	cout << "Copy constructor BitcoinExchange called" << endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	cout << "Constructor assignement BitcoinExchange called" << endl;
	return *this;
}

bool BitcoinExchange::fileExist(const char *fileName ) {
	std::ifstream  file( fileName );
	return file.good();
}

std::ifstream BitcoinExchange::openFile(const char *fileName) {
	if (fileExist( fileName )) {
		std::ifstream file( fileName );
		return ( file );
	}
	else
		throw std::runtime_error("File '" + static_cast<std::string>(fileName )+ " doesn't exist or cannot be opened\n");
}

BitcoinExchange::BitcoinExchange(const char *fileName) : _bitcoinData(){
	std::ifstream file;
	std::ifstream dataFile;
	file = openFile( fileName );
	dataFile = openFile( "data.csv");
	fillMap( dataFile );
}

void BitcoinExchange::fillMap( std::ifstream file ) {
	std::string line;

	while ( std::getline( file, line )) {
		int 		i = 0;
		int 		start = 0;
		float 		bitcoinValue = 0;
		if ( line.find('|') == std::string::npos )
			throw std::runtime_error("Data.csv is not well formatted (xx-xx-xxxx (date) | number (int))\n");
		while ( line[i] )
		{
			while ( line[i] && line[i] >= 9 && line[i] <= 13 )
				i++;
			start = i;
			while ( line[i] != '|' )
				i++;
			if ( i >= line.size() - 1 )
				throw std::runtime_error("Data.csv is not well formatted (xx-xx-xxxx (date) | number (int))\n");
			timestampIsValid( line.substr( start, i - 1 ) );
			std::istringstream ss( line.substr( i, line.size() - 1 ) );
			ss >> bitcoinValue;
			if ( ss.fail() || !ss.eof() || bitcoinValue < 0 || bitcoinValue > 1000 )
				throw std::runtime_error("Bitcoin values in Data.csv must be float or positive integer between 0 and 1000\n");
			this->_bitcoinData[ line.substr( start, i - 1 ) ] = bitcoinValue;
			line.clear();
		}
	}
	if ( this->_bitcoinData.empty() )
		throw std::runtime_error("Data.csv is not well formatted (xx-xx-xxxx (date) | number (int)), or is empty\n");
}

bool BitcoinExchange::timestampIsValid( const std::string &timestamp ) {
	std::regex pattern( DATE_PATTERN );
	if ( !std::regex_match( timestamp, pattern ) )
		throw std::runtime_error("Data.csv is not well formatted (xx-xx-xxxx (date) | number (int))\n");

	int day = std::stoi(timestamp.substr(0, 2));
	int month = std::stoi(timestamp.substr(3, 2));
	int year = std::stoi(timestamp.substr(6, 4));

	if ( day < 1 || day > 31 || month < 1 || month > 12 ) {
		throw std::runtime_error("Data.csv contains an date which doesn't exist\n")
	}
	return true;
}
