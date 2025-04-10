/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:08:02 by ademarti          #+#    #+#             */
/*   Updated: 2025/04/10 11:24:28 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
Here only the weapon is passed as a reference
A constructor is useful to use initial values when
calling a function (initializer).
Here the constructor is using an initializer list!
The initializer list initializes the private attributes of HumanA
*/
HumanA::HumanA(std::string name, Weapon &weapon)
	: name(name), weapon(weapon)
{};

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType()  << std::endl;
};