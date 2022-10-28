/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:54:17 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 17:54:17 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name)
{
	this->_Name = Name;
}

HumanB::~HumanB(void) {
}

void HumanB::attack()
{
	PURPLE << this->_Name << " attacks with their " << this->_Club->getType() << RESET;
}

void HumanB::setWeapon( Weapon &newWeapon )
{
	this->_Club = &newWeapon;
}
