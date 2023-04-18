/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:43:32 by aurel             #+#    #+#             */
/*   Updated: 2023/03/18 13:48:52 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include "../incs/outputs.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::flush;

int main(int ac, char **av)
{
	string filename;
	string line;
	string s1;
	string s2;

	if (ac != 4)
	{
		cout << INV_ARG << endl;
		return (0);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	if (s1.empty() || filename.empty())
	{
		cout << INV_ARG << endl;
		return (0);
	}
	std::ifstream input_file(filename.c_str());
	if (input_file.fail())
	{
		std::cerr << OPEN_ERROR << endl;
		return (0);
	}
	std::ofstream output_file(string(filename + ".replace").c_str());
	if (output_file.fail())
	{
		std::cerr << OPEN_ERROR << endl;
		return (0);
	}
	while (getline(input_file, line))
	{
		size_t pos = line.find(s1);
		while (pos != string::npos)
		{
			output_file << line.substr(0, pos) << s2;
			line = line.substr(pos + s1.length());
			pos = line.find(s1);
		}
		output_file << line << endl;
	}
	input_file.close();
	output_file.close();
}