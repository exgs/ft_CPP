/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 05:24:39 by yunslee           #+#    #+#             */
/*   Updated: 2021/03/11 21:30:04 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iomanip>
# include <iostream>
# include <string>

enum page
{
	MAIN = 0,
	ADD,
	SEARCH,
	EXIT
};

class properties {
	// protected:
	// 	std::string infos_name[11] = {
	// 	"first name",
	// 	"last name",
	// 	"nickname",
	// 	"login",
	// 	"postal address",
	// 	"email address",
	// 	"phone number",
	// 	"birthday date",
	// 	"favorite meal",
	// 	"underwear color",
	// 	"darkest secret"
	// };
};

class member : public properties{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _login;
		std::string _postal_address;
		std::string _email_address;
		std::string _phone_number;
		std::string _birthday_date;
		std::string _favorite_meal;
		std::string _underwear_color;
		std::string _darkest_secret;
		bool		_is_exist;
	public:
		member(); // 복사 생성자
		member(const member&); // 복사 생성자(=)
		virtual ~member();
		member &operator=(const member& op); // =연산자

		// Getter - Setter
		void	setFirstName(const std::string &first_name);
		void	setLastName(const std::string &last_name);
		void	setNickname(const std::string &nickname);
		void	setLogin(const std::string &login);
		void	setPostalAddress(const std::string &postal_address);
		void	setEmailAddress(const std::string &email_address);
		void	setPhoneNumber(const std::string &phone_number);
		void	setBirthdayDate(const std::string &birthday_date);
		void	setFavoriteMeal(const std::string &favorite_meal);
		void	setUnderwearColor(const std::string &underwear_color);
		void	setDarkestSecret(const std::string &darkest_secret);

		const std::string    &getFirstName();
		const std::string    &getLastName();
		const std::string    &getNickname();
		const std::string    &getLogin();
		const std::string    &getPostalAddress();
		const std::string    &getEmailAdress();
		const std::string    &getPhoneNumber();
		const std::string    &getBirthdayDate();
		const std::string    &getFavoriteMeal();
		const std::string    &getUnderwearColor();
		const std::string    &getDarkestSecret();
		void	setup();
		void	print_members();
		bool	exist();
		void	clear();
};
		std::string truncate(std::string str);
		int		main_menu();
		int		add(member phonebook[8]);
		int		no_member_search();
		int		full_member_add();
		int		search(member phonebook[8]);
		int		choose_index_search();
#endif
