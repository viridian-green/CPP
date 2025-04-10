/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:58:09 by ademarti          #+#    #+#             */
/*   Updated: 2025/04/10 11:19:40 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H
#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon &weapon;
	std::string name;

	public:
	HumanA(std::string name, Weapon &weapon);
	void attack();
};

#endif