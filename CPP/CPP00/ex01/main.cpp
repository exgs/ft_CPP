/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 05:24:47 by yunslee           #+#    #+#             */
/*   Updated: 2021/03/11 21:30:19 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "member.hpp"

int main_menu()
{
	std::string command;
	std::cout << "-----------------------main page---------------------\n";
	std::cout << "목록                                                  \n";
	std::cout << "1. ADD                                               \n";
	std::cout << "2. SEARCH                                            \n";
	std::cout << "3. EXIT                                              \n";
	std::cout << "-----------------------------------------------------\n";
	std::cout << "Please write COMMAND\n";
	std::cin >> command;
	if (!command.compare("ADD"))
		return (1);
	else if (!command.compare("SEARCH"))
		return (2);
	else if (!command.compare("EXIT"))
		return (3);
	else if (command.size() == 0) // EOF 처리
		return (EOF);
	return (0);
}

int add(member phonebook[8])
{
	int i = 0;
	while (phonebook[i].exist() == 1 && i < 8)
		i++;
	if (i > 7)
		return (full_member_add());
	phonebook[i].setup();
	return (0);
}

int no_member_search()
{
	std::cout << "There is no member in this phonebook\n";
	std::cout << "Return to main page.\n";
	return (0);
}

int full_member_add()
{
	std::cout << "Phonebook is full.\n";
	std::cout << "Return to main page.\n";
	return (0);
}

std::string truncate(std::string str)
{
	if (str.size()> 10)
	{
		str = str.insert(9, ".");
		str = str.substr(0, 10);
	}
	return (str);
}


int search(member phonebook[8])
{
	std::string str;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    int j = 0;
    while (phonebook[j].exist() && j < 8)
    {
        std::cout << std::setw(10) << j << "|";
        str = truncate(phonebook[j].getFirstName());
        std::cout << std::setw(10) << str << "|";
        str = truncate(phonebook[j].getLastName());
        std::cout << std::setw(10) << str << "|";
        str = truncate(phonebook[j].getNickname());
		std::cout << std::setw(10) << str << "|";
        std::cout << '\n';
        j++;
    }
	int cin_index;
	std::cout << "-------------------------------------------" << std::endl;
	if (j == 0)
		return (no_member_search());
	else
	{
		if ((cin_index = choose_index_search()) == -1)
		{
			std::cout << "Input wrong index number. Return to the main menu." << std::endl;
			return (0);
		}
		else if (phonebook[cin_index].exist() == 0)
		{
			std::cout << "Input number is out of range. Return to the main menu." << std::endl;
		}
		else
			phonebook[cin_index].print_members();
		return (0);
	}
}

int choose_index_search()
{
	std::string str;
	int index;
	
	std::cout << "Choose an index within table\n";
	std::cin >> str;
	if (str.size() != 1 || str.c_str()[0] >= '9' || str.c_str()[0] < '0')
		return (-1);
	index = atoi(str.c_str()); //Error처리를 0으로 해서 문제가 발생
	if (index < 0 || index > 8)
		return (-1);
	return (index);
}

int main()
{
	int window_num;
	member phonebook[8];
	
	for (size_t i = 0; i < 8; i++)
		phonebook[i].clear();
	
	window_num = 0;
	while (1)
	{
		if (window_num == MAIN)
			window_num = main_menu();
		if (window_num == ADD)
			window_num = add(phonebook);
		if (window_num == SEARCH)
			window_num = search(phonebook);
		if (window_num == EXIT)
			exit(0);
		if (window_num == EOF)
		{
			std::cout << "eof" << std::endl;
			exit(0);
		}
	}
	return (0);
}
