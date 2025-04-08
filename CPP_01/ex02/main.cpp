/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:17:12 by ademarti          #+#    #+#             */
/*   Updated: 2025/04/08 13:31:21 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*Here we are introduced to references.
Reference is making a alias to a variable.
If i update a reference, the original var is also update;
*/
int main()
{
	std::string greeting = "HI THIS IS BRAIN";
	std::string *stringPTR = &greeting;
	std::string &stringREF = greeting;

	std::cout << &greeting << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << greeting << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}