//
// Created by aucaland on 4/29/23.
//
#include "../incs/BitcoinExchange.h"

int main( int argc, char **argv )
{
	if ( argc != 2 )
		throw std::runtime_error(" ./btc filename.txt\n");
	try
	{

	}
	catch ( std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}