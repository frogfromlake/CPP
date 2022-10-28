/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:40:51 by fquist            #+#    #+#             */
/*   Updated: 2022/08/04 20:29:26 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

void Harl::debug(void)
{
	GREEN "\n" << "DEBUG:" RESET;
	GREEN "I love having extra bacon for my" 
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << "\n" << RESET;
	return ;
}

void Harl::info(void)
{
	LGREEN "INFO:" RESET;
	LGREEN "I cannot believe adding extra bacon costs more money. You didn’t put"
		<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n" << RESET;
	return ;
}

void Harl::warning(void)
{
	YELLOW "WARNING:" RESET;
	YELLOW "I think I deserve to have some extra bacon for free. I’ve been coming for"
		<< "years whereas you started working here since last month." << "\n" << RESET;
	return ;
}

void Harl::error(void)
{
	RED "ERROR:" RESET;
	RED "This is unacceptable! I want to speak to the manager now." << "\n" << RESET;
	return ;
}

void Harl::complain(std::string level)
{
	int option = 0;
	const char *message[4]
		= {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (option < 4 && level != message[option])
		option++;
	switch (option)
	{
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			LBLUE "Non machting input: nothing to complain about: " << "\033[0m" << level << "\n" << std::endl;
			break;
	}
}
