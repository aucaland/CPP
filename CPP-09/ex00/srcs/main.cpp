//
// Created by aucaland on 4/29/23.
//
#include "../incs/BitcoinExchange.h"

int main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Error, one arg needed: './btc filename.txt'" << std::endl;
		return 0;
	}
	try
	{
		BitcoinExchange( static_cast<const char*>(argv[1]) );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}