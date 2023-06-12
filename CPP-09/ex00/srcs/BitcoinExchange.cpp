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

void	BitcoinExchange::openFile( const char *fileName, std::ifstream *file ) {
	if (fileExist( fileName )) {
		file->open( fileName );
	}
	else
		throw std::runtime_error("File '" + static_cast<std::string>(fileName )+ " doesn't exist or cannot be opened\n");
}

BitcoinExchange::BitcoinExchange(const char *fileName) : _bitcoinData(){
	std::ifstream file;
	std::ifstream dataFile;
	openFile( fileName, &dataFile );
	openFile( "data.csv", &file );
	errorsManagement(fillMap( dataFile ) );
	inputParsing( dataFile );
}

int BitcoinExchange::fillMap( std::ifstream &file ) {
	std::string line;
	int 		errorCode;

	while ( std::getline( file, line )) {
		int 		i = 0;
		int 		start = 0;
		float 		bitcoinValue = 0;
		if ( line.find('|') == std::string::npos )
			return BAD_FORMAT;
		while ( line[i] )
		{
			while ( line[i] && line[i] >= 9 && line[i] <= 13 )
				i++;
			start = i;
			while ( line[i] != '|' )
				i++;
			if ( i >= line.size() - 1  || line[i + 1] != ' ' )
				return BAD_FORMAT;
			errorCode = timestampIsValid( line.substr( start, i - 1 ) );
			if ( errorCode != true )
				return errorCode;

			std::istringstream ss( line.substr( i, line.size() - 1 ) );
			ss >> bitcoinValue;
			if ( ss.fail() || !ss.eof() )
				return WRONG_VALUE;
			else if ( bitcoinValue < 0 )
				return NOT_POSITIVE_NUMBER;
			this->_bitcoinData[ line.substr( start, i - 1 ) ] = bitcoinValue;
			line.clear();
		}
	}
	if ( this->_bitcoinData.empty() )
		throw std::runtime_error("Data.csv is empty\n");
}

int BitcoinExchange::timestampIsValid( const std::string &timestamp ) {
	std::regex pattern( DATE_PATTERN );
	if ( !std::regex_match( timestamp, pattern ) )
		return BAD_FORMAT;
	int day = std::stoi(timestamp.substr(0, 2));
	int month = std::stoi(timestamp.substr(3, 2));
	int year = std::stoi(timestamp.substr(6, 4));

	if ( day < 1 || day > 31 || year > 2023 )
		return WRONG_DATE;
	switch (month) {
		case 2:
		{
			if ( day > 28 )
				return WRONG_DATE;
		}
		case 4 :
		{
			if ( day > 30 )
				return WRONG_DATE;
		}
		case 6:
		{
			if ( day > 30 )
				return WRONG_DATE;
		}
		case 9:
		{
			if ( day > 30 )
				return WRONG_DATE;
		}
		case 11:
		{
			if ( day > 30 )
				return WRONG_DATE;
		}
		default:
			return true;
	}
}

int BitcoinExchange::inputParsing(std::ifstream &fileName) {
	std::string line;
	int 		errorCode;

	while ( std::getline( fileName, line )) {
		int 		i = 0;
		int 		start = 0;
		float 		bitcoinQuantity = 0;
		if ( line.find('|') == std::string::npos )
		{
			inputFileErrorsManagement( BAD_FORMAT, line );
			line.clear();
			continue;
		}
		while ( line[i] )
		{
			while ( line[i] && line[i] >= 9 && line[i] <= 13 )
				i++;
			start = i;
			while ( line[i] != '|' )
				i++;
			if ( i >= line.size() - 1  || line[i + 1] != ' ' )
			{
				inputFileErrorsManagement( BAD_FORMAT, line );
				line.clear();
				continue;
			}
			errorCode = timestampIsValid( line.substr( start, i - 1 ) );
			if ( errorCode != true )
				return errorCode;

			std::istringstream ss( line.substr( i, line.size() - 1 ) );
			ss >> bitcoinQuantity;
			if ( ss.fail() || !ss.eof() )
			{
				inputFileErrorsManagement( WRONG_VALUE, line );
				line.clear();
				continue;
			}
			else if ( bitcoinQuantity < 0 )
			{
				inputFileErrorsManagement( NOT_POSITIVE_NUMBER, line );
				line.clear();
				continue;
			}
			else if ( bitcoinQuantity > 1000 )
			{
				inputFileErrorsManagement( TOO_LARGE_VALUE, line );
				line.clear();
				continue;
			}
			line.clear();
		}
	}
}

void BitcoinExchange::errorsManagement(int errorCode) {

	switch ( errorCode ) {
		case BAD_FORMAT:
			throw std::runtime_error("Data.csv is not well formatted (xx-xx-xxxx (date) | number (float/int)\n");
		case WRONG_DATE:
			throw std::runtime_error("Data.csv contains a date which doesn't exist\n");
		case NOT_POSITIVE_NUMBER:
			throw std::runtime_error("Bitcoin values in Data.csv must be float or positive integer between 0 and 1000\n");
		default:
			break;
	}
}

void BitcoinExchange::inputFileErrorsManagement(int errorCode, std::string content) {
	switch ( errorCode ) {
		case BAD_INPUT:
			std::cout << ERR_INPUT( content );
			break;
		case WRONG_DATE:
			std::cout << ERR_DATE( content );
			break;
		case NOT_POSITIVE_NUMBER:
			std::cout << ERR_NOT_POSITIV;
		case WRONG_VALUE:
			std::cout << ERR_WRONG_VALUE;
		case TOO_LARGE_VALUE:
			std::cout << ERR_TOO_LARGE( content );
		default:
			break;
	}
}
