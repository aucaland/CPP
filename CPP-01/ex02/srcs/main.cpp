/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:09:19 by aurel             #+#    #+#             */
/*   Updated: 2023/03/17 17:27:35 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using std::string;
using std::cout;
using std::endl;

int main()
{
	string	brain = "HI THIS IS BRAIN";
	string*	stringPTR = &brain;
	string&	stringREF = brain;

	cout << "memory adress of the string variable: " << &brain << endl;
	cout << "memory adress held by stringPTR: " << stringPTR << endl;
	cout << "memory adress held by stringREF: " << &stringREF << endl;
	cout << "value of string variable: " << brain << endl;
	cout << "value pointed to by stringPTR: " << *stringPTR << endl;
	cout << "value pointed to by stringPTR: " << stringREF << endl;

	return (0);
}