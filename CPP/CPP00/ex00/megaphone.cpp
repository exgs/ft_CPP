/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 04:54:36 by yunslee           #+#    #+#             */
/*   Updated: 2021/03/11 05:46:00 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int islower(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

void lower_to_upper(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (islower(str[i]) == 1)
			str[i] -= 32;
		i++;
	}
}

void lower_to_upper2(std::string &temp)
{
	std::transform(temp.begin(), temp.end(),temp.begin(), ::toupper);
}


int main(int argc, char *str[])
{
	int i;
	
	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		//c++스타일
		// std::string temp = str[i];
		// lower_to_upper2(temp);
		// std::cout << temp;

		//c스타일
		lower_to_upper(str[i]);
		std::cout << str[i];
		i++;
	}
	
}
