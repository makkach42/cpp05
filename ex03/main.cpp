/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:13 by makkach           #+#    #+#             */
/*   Updated: 2026/03/04 13:49:39 by makkach          ###   ########.fr       */
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
		Bureaucrat b("buro", 1);
		Intern i;
		AForm *j = i.makeForm("robotomy request", "wwwww");
		AForm *k = i.makeForm("presidential pardon", "wwwww");
		AForm *l = i.makeForm("shrubbery creation", "wwwww");
		b.signForm(*j);
		b.signForm(*k);
		b.signForm(*l);
		b.executeForm(*j);
		b.executeForm(*k);
		b.executeForm(*l);
		delete j;
		delete k;
		delete l;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
