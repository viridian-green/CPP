/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:33:56 by ademarti          #+#    #+#             */
/*   Updated: 2025/04/17 15:09:52 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
#include <string>
#include <iostream>

class Weapon
{
	private:
	std::string type;

	public:
	Weapon(std::string type);
	const std::string &getType();
	void setType(const std::string &newVal);
};

#endif
