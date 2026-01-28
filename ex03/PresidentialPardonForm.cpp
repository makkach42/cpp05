/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:28:57 by makkach           #+#    #+#             */
/*   Updated: 2026/01/23 11:01:02 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("default", 25, 5, "target"){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):AForm(copy){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy){AForm::operator=(copy);return *this;}

AForm *PresidentialPardonForm::createPardon(){ return new PresidentialPardonForm();}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, int sign_grade, int exec_grade, std::string target):AForm::AForm(name, sign_grade, exec_grade, target)
{
		if (sign_grade > 25 || exec_grade > 5)
			throw GradeTooLowException();
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
		if (this->getSigned() == false)
			throw AForm::NotSignedForm();
		if (executor.getGrade() > 5 || executor.getGrade() > this->getSignGrade())
			throw AForm::GradeTooLowException();
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::beSigned(Bureaucrat& employee)
{
		if (employee.getGrade() <= 25 && employee.getGrade() <= this->getSignGrade())
			this->setSigned(true);
		else
			throw AForm::GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(){}
