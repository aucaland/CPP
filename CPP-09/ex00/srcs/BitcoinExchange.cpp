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
