/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:08:33 by makkach           #+#    #+#             */
/*   Updated: 2026/01/23 10:17:03 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}
Intern::Intern(const Intern& copy){*this = copy;}
Intern::~Intern(){}
Intern& Intern::operator=(const Intern& copy){(void)copy;return *this;}

const char *Intern::FormtypeNotFound::what() const throw(){return "Intern::FormtypeNotFound";}
AForm *Intern::makeForm(std::string one, std::string two)
{
	try
	{
		std::string arr[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
		typedef AForm *(*clone)();
		clone arr2[3];
		arr2[0] = &RobotomyRequestForm::createRobotomy;
		arr2[1] = &PresidentialPardonForm::createPardon;
		arr2[2] = &ShrubberyCreationForm::createShrubbery;
		for (int i = 0; i < 3; i++)
		{
			if (arr[i] == one)
			{
				AForm *f = arr2[i]();
				f->setTarget(two);
				return (f);
			}
		}
		throw (FormtypeNotFound());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return NULL;
}
