/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:13 by makkach           #+#    #+#             */
/*   Updated: 2026/01/20 12:47:45 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat b("qwerty", 5);
		ShrubberyCreationForm d("tree", 5, 5, "first_one");
		b.executeForm(d);
		Intern i;
		AForm *j = i.makeForm("robotomy request", "wwwww");
		delete j;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
