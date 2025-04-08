/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:33:56 by ademarti          #+#    #+#             */
/*   Updated: 2025/04/08 15:12:52 by ademarti         ###   ########.fr       */
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
	const std::string getType();
	const std::string setType(std::string newVal);
};

#endif
