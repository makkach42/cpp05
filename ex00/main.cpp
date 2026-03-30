/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:13 by makkach           #+#    #+#             */
/*   Updated: 2026/03/03 20:26:02 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat d("qwerty", 1);
		std::cout << "d:" << d << std::endl;
		d.decrement();
		std::cout << "d:" << d << std::endl;
		d.increment();
		std::cout << "d:" << d << std::endl;
		std::cout << std::endl;

		const Bureaucrat b(d);
		std::cout << "b:" << b << std::endl;
		Bureaucrat z(b);
		std::cout << "z:" << z << std::endl;
		std::cout << std::endl;

		Bureaucrat n("azerty", 2);
		std::cout << "n:" << n << std::endl;
		n = b;
		std::cout << "n:" << n << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return 0;
}
