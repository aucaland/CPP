/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:46:46 by aurel             #+#    #+#             */
/*   Updated: 2023/03/12 22:40:16 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				if (isalpha(argv[i][j]))
					std::cout << (char) toupper(argv[i][j]) ;
				else
					std::cout << (char) toupper(argv[i][j]);
			}
			if (i < argc - 1)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return (0);
}
