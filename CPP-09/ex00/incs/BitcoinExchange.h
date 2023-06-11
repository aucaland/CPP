//
// Created by aucaland on 4/29/23.
//

#pragma once

#include <iostream>
#include <map>
#include <string>

using std::string;


class BitcoinExchange
{
private:
	std::map<string, int>	bitcoinData;


public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &);
	BitcoinExchange(const BitcoinExchange &);
};


#endif //CPP_BITCOINEXCHANGE_H
