/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:41:05 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 17:39:56 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Type) {

	this->type = Type;
}

Weapon::~Weapon() {
}

void Weapon::setType( std::string type )
{
	this->type = type;
}

const std::string& Weapon::getType(void)
{
	return(this->type);
}
