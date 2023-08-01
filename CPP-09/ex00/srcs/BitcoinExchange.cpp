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

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _bitcoinData(other._bitcoinData) {
	cout << "Copy constructor BitcoinExchange called" << endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
	{
		this->_bitcoinData = other._bitcoinData;
	}
	cout << "Constructor assignement BitcoinExchange called" << endl;
	return *this;
}

bool BitcoinExchange::fileExist(const char *fileName ) {
	std::ifstream  file( fileName );
	return file.good();
}

void	BitcoinExchange::openFile( const char *fileName, std::ifstream *file ) {
	if (fileExist( fileName )) {
		{
			char testChar;
			file->open( fileName );
			if ( file->get(testChar).eof() )
				throw std::runtime_error( ERR_EMPTY );
			file->close( );
			file->open( fileName );
		}
	}
	else
		throw std::runtime_error("File '" + static_cast<std::string>(fileName )+ "' doesn't exist or cannot be opened");
}

BitcoinExchange::BitcoinExchange(const char *fileName) : _bitcoinData() {
	std::ifstream file;
	std::ifstream dataFile;
	openFile( fileName, &file );
	openFile( "data.csv", &dataFile );
	errorsManagement(fillMap( dataFile ) );
	inputParsing( file );
}

int BitcoinExchange::fillMap( std::ifstream &file ) {
	std::string line;
	int 		errorCode;
	std::getline( file, line );
	line.clear();
	while ( std::getline( file, line )) {
		if (line.empty())
			return BAD_INPUT;
		size_t 		i = 0;
		int 		start = 0;
		float 		bitcoinValue = 0;
		if ( line.find(',') == std::string::npos )
			return BAD_INPUT;
		if ( !isdigit(line[0]) )
			return BAD_INPUT;
		while ( line[i] && line[i] != ',' )
			i++;
		if ( i >= line.size() - 1  || line[i] != ','  || i != 10 )
			return BAD_INPUT;
		errorCode = timestampIsValid( line.substr( start, i ) );
		if ( errorCode != true )
			return errorCode;

		std::istringstream ss( line.substr( i + 1, line.size() - 1 ) );
		ss >> bitcoinValue;
		if ( ss.fail() || !ss.eof() )
			return WRONG_VALUE;
		else if ( bitcoinValue < 0 )
			return NOT_POSITIVE_NUMBER;
		this->_bitcoinData[ line.substr( start, i ) ] = bitcoinValue;
		line.clear();
	}
	if ( this->_bitcoinData.empty() )
		throw std::runtime_error("data.csv is empty");
	return true;
}

int BitcoinExchange::timestampIsValid( const std::string &timestamp ) {
	int i = -1;

//	std::cerr << "FULL: '" << timestamp << "'" << endl;
	while ( !timestamp.empty() && timestamp[++i] )
	{
//		std::cerr << "char: '" << timestamp[i] << "'" << endl;
		if ( ( i == 5 || i == 6 || i == 8 || i == 9 || (i >= 0 && i <= 3) ) && !isdigit(timestamp[i] ) ) //fu** cpp98
			return BAD_INPUT;
		else if ( ( i == 4 || i == 7 ) && timestamp[i] != '-' )
			return BAD_INPUT;
	}

	std::istringstream si(timestamp.substr(8, 10));
	std::istringstream sj(timestamp.substr(5, 7));
	std::istringstream sk(timestamp.substr(0, 5));
	int day; si >> day;
	int month; sj >> month;
	int year; sk >> year;

	if ( day < 1 || day > 31 || year > 2023 || month < 1 || month > 12 )
		return WRONG_DATE;
	switch (month) {
		case 2:
		{
			if ( day > 28 )
				return WRONG_DATE;
			break;
		}
		case 4 :
		{
			if ( day > 30 )
				return WRONG_DATE;
			break;
		}
		case 6:
		{
			if ( day > 30 )
				return WRONG_DATE;
			break;
		}
		case 9:
		{
			if ( day > 30 )
				return WRONG_DATE;
			break;
		}
		case 11:
		{
			if ( day > 30 )
				return WRONG_DATE;
			break;
		}
		default:
			return true;
	}
	return true;
}

int BitcoinExchange::inputParsing(std::ifstream &fileName) {
	std::string line;
	std::string date;
	int 		errorCode;

	while ( std::getline( fileName, line )) {
		size_t 		i = 0;
		size_t 		start = 0;
		float 		bitcoinQuantity = 0;
		if ( line.find('|') == std::string::npos )
		{
			inputFileErrorsManagement( BAD_INPUT, line );
			continue;
		}

		while ( line[i] && line[i] >= 9 && line[i] <= 13 )
			i++;
		start = i;
		while ( line[i] && line[i] != '|' )
			i++;
		if ( i >= line.size() - 1 || i != 11 || line[i + 1] != ' ' || line[ i - 1 ] != ' ' )
		{
			inputFileErrorsManagement( BAD_INPUT, line );
			continue ;
		}
		date = line.substr( start, i - 1 );
		errorCode = timestampIsValid( date );
		if ( errorCode != true )
		{
			inputFileErrorsManagement( errorCode, line );
			continue ;
		}
		std::istringstream ss( line.substr( i + 1, line.size() - 1 ) );
		ss >> bitcoinQuantity;
		if ( ss.fail() || !ss.eof() )
		{
			inputFileErrorsManagement( WRONG_VALUE, line );
			continue ;
		}
		else if ( bitcoinQuantity < 0 )
		{
			inputFileErrorsManagement( NOT_POSITIVE_NUMBER, line );
			continue ;
		}
		else if ( bitcoinQuantity > 1000 )
		{
			inputFileErrorsManagement( TOO_LARGE_VALUE, line );
			continue ;
		}
		processData( date, bitcoinQuantity );
	}
	return true;
}

void BitcoinExchange::errorsManagement(int errorCode) {

	switch ( errorCode ) {
		case BAD_INPUT:
			throw std::runtime_error("data.csv is not well formatted (^xx-xx-xxxx(date),number$(float/int)");
		case WRONG_DATE:
			throw std::runtime_error("data.csv contains a date which doesn't exist");
		case NOT_POSITIVE_NUMBER:
			throw std::runtime_error("Bitcoin values in Data.csv must be positive integer");
		case WRONG_VALUE:
			throw std::runtime_error("Bitcoin values in Data.csv must be float or positive integer");
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
			break;
		case WRONG_VALUE:
			std::cout << ERR_WRONG_VALUE;
			break;
		case TOO_LARGE_VALUE:
			std::cout << ERR_TOO_LARGE( content );
			break;
		default:
			break;
	}
}

void BitcoinExchange::processData(const std::string& date, float bitcoinQuantity ) {
	std::map<string, float>::iterator it = this->_bitcoinData.lower_bound( date );
	if ( it != this->_bitcoinData.end() )
	{
		if ( it != this->_bitcoinData.begin() )
			it--;
//		std::cerr << "lowerBound: " << it->first << " = " << it->second << std::endl;
		std::cout << date << " => " << bitcoinQuantity << " = " << bitcoinQuantity * it->second << std::endl;
	}
}
