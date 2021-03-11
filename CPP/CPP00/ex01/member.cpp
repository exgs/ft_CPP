/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 01:27:40 by yunslee           #+#    #+#             */
/*   Updated: 2020/12/31 06:13:28 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "member.hpp"

member::member()
{
	_is_exist = 1;
}

member::member(const member& copy)
{
	_first_name = copy._first_name;
	_last_name = copy._last_name;
	_nickname = copy._last_name;
	_login = copy._login;
	_postal_address = copy._postal_address;
	_email_address = copy._email_address;
	_phone_number = copy._phone_number;
	_birthday_date = copy._birthday_date;
	_favorite_meal = copy._favorite_meal;
	_underwear_color = copy._underwear_color;
	_darkest_secret = copy._darkest_secret;
	_is_exist = copy._is_exist;
}

member::~member(){}
//동적할당이 없어서 처리를 해주지 않았다.

member& member::operator=(const member& copy)
{
	if (this == &copy)
		return (*this); 
	_first_name = copy._first_name;
	_last_name = copy._last_name;
	_nickname = copy._nickname;
	_login = copy._login;
	_postal_address = copy._postal_address;
	_email_address = copy._email_address;
	_phone_number = copy._phone_number;
	_birthday_date = copy._birthday_date;
	_favorite_meal = copy._favorite_meal;
	_underwear_color = copy._underwear_color;
	_darkest_secret = copy._darkest_secret;
	_is_exist = copy._is_exist;
	return (*this);
}

// Set the member
void	member::setFirstName(const std::string &first_name)
{ this->_first_name = first_name; }
void	member::setLastName(const std::string &last_name)
{ this->_last_name = last_name; }
void	member::setNickname(const std::string &nickname)
{ this->_nickname = nickname; }
void	member::setLogin(const std::string &login)
{ this->_login = login; }
void	member::setPostalAddress(const std::string &postal_address)
{ this->_postal_address = postal_address; }
void	member::setEmailAddress(const std::string &email_address)
{ this->_email_address = email_address; }
void	member::setPhoneNumber(const std::string &phone_number)
{ this->_phone_number = phone_number; }
void	member::setBirthdayDate(const std::string &birthday_date)
{ this->_birthday_date = birthday_date; }
void    member::setFavoriteMeal(const std::string &favorite_meal)
{ this->_favorite_meal = favorite_meal; }
void    member::setUnderwearColor(const std::string &underwear_color)
{ this->_underwear_color = underwear_color; }
void    member::setDarkestSecret(const std::string &darkest_secret)
{ this->_darkest_secret = darkest_secret; }


// Get the member
const std::string    &member::getFirstName()
{ return (this->_first_name); }
const std::string    &member::getLastName()
{ return (this->_last_name); }
const std::string    &member::getNickname()
{ return (this->_nickname); }
const std::string    &member::getLogin()
{ return (this->_login); }
const std::string    &member::getPostalAddress()
{ return (this->_postal_address); }
const std::string    &member::getEmailAdress()
{ return (this->_email_address); }
const std::string    &member::getPhoneNumber()
{ return (this->_phone_number); }
const std::string    &member::getBirthdayDate()
{ return (this->_birthday_date); }
const std::string    &member::getFavoriteMeal()
{ return (this->_favorite_meal); }
const std::string    &member::getUnderwearColor()
{ return (this->_underwear_color); }
const std::string    &member::getDarkestSecret()
{ return (this->_darkest_secret); }

void	member::setup()
{
	std::string infos_name[11] = {
		"first name",
		"last name",
		"nickname",
		"login",
		"postal address",
		"email address",
		"phone number",
		"birthday date",
		"favorite meal",
		"underwear color",
		"darkest secret"
	};
	std::string entry;
	for (int i = 0; i < 11; i++)
	{
		std::cout << infos_name[i] << " : ";
		std::cin >> entry;
		(i == 0) ? this->setFirstName(entry) : (void)0;
		(i == 1) ? this->setLastName(entry) : (void)0;
		(i == 2) ? this->setNickname(entry) : (void)0;
		(i == 3) ? this->setLogin(entry) : (void)0;
		(i == 4) ? this->setPostalAddress(entry) : (void)0;
		(i == 5) ? this->setEmailAddress(entry) : (void)0;
		(i == 6) ? this->setPhoneNumber(entry) : (void)0;
		(i == 7) ? this->setBirthdayDate(entry) : (void)0;
		(i == 8) ? this->setFavoriteMeal(entry) : (void)0;
		(i == 9) ? this->setUnderwearColor(entry) : (void)0;
		(i == 10) ? this->setDarkestSecret(entry) : (void)0;
	}
	this->_is_exist = true;
}

void	member::print_members()
{
	std::string infos_name[11] = {
		"first name",
		"last name",
		"nickname",
		"login",
		"postal address",
		"email address",
		"phone number",
		"birthday date",
		"favorite meal",
		"underwear color",
		"darkest secret"
	};
	std::string infos[11] = {
		this->getFirstName(),
		this->getLastName(),
		this->getNickname(),
		this->getLogin(),
		this->getPostalAddress(),
		this->getEmailAdress(),
		this->getPhoneNumber(),
		this->getBirthdayDate(),
		this->getFavoriteMeal(),
		this->getUnderwearColor(),
		this->getDarkestSecret()
	};
	for (int i = 0; i < 11; i++)
		std::cout << infos_name[i] << " : " << infos[i] << std::endl;
	std::cin.ignore(1000, '\n');
	std::cout << "Press enter";
	std::string temp;
	std::getline(std::cin, temp);
}

bool	member::exist()
{ return (this->_is_exist); }

void	member::clear()
{
	this->_first_name.clear();
	this->_last_name.clear();
	this->_nickname.clear();
	this->_login.clear();
	this->_postal_address.clear();
	this->_email_address.clear();
	this->_phone_number.clear();
	this->_birthday_date.clear();
	this->_favorite_meal.clear();
	this->_underwear_color.clear();
	this->_darkest_secret.clear();
	this->_is_exist = 0;
}
