/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:08:02 by ademarti          #+#    #+#             */
/*   Updated: 2025/04/08 15:38:01 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon)
	: name(name), weapon(weapon)
{};

void HumanA::attack()
{
	std::cout << name << "attacks with their" << weapon.getType()  << std::endl;
};