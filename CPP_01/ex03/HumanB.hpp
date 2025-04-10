/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:59:08 by ademarti          #+#    #+#             */
/*   Updated: 2025/04/10 12:10:59 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMAN_B_H
# define HUMAN_B_H
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
	Weapon *weapon;
	std::string name;

	public:
	HumanB(std::string name);
	void setWeapon(Weapon &type);
	void attack();
};

#endif