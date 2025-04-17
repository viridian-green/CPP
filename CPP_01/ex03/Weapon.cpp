/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:38:24 by ademarti          #+#    #+#             */
/*   Updated: 2025/04/17 15:12:04 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	return type;
};

void Weapon::setType(const std::string &newVal)
{
	this->type = newVal;
}