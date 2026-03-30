/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:28:57 by makkach           #+#    #+#             */
/*   Updated: 2026/03/04 14:11:43 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("default", 25, 5, "target"){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):AForm(copy){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy){AForm::operator=(copy);return *this;}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm::AForm("PresedentialPardonForm", 25, 5, target){}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
		if (executor.getGrade() > this->getExecGrade())
			throw AForm::GradeTooLowException();
		if (this->getSigned() == false)
			throw AForm::NotSignedForm();
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::beSigned(const Bureaucrat& employee)
{
		if (employee.getGrade() <= 25 && employee.getGrade() <= this->getSignGrade())
			this->setSigned(true);
		else
			throw AForm::GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(){}
