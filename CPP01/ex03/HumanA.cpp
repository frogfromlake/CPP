/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:53:29 by fquist            #+#    #+#             */
/*   Updated: 2022/07/29 17:51:13 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack()
{
	PURPLE << this->_Name << " attacks with their " << this->_Club.getType() << RESET;
}

HumanA::HumanA(const std::string &Name, Weapon& Club): _Name( Name ), _Club( Club ) {
}

HumanA::~HumanA() {
}
