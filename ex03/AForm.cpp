/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:02:48 by makkach           #+#    #+#             */
/*   Updated: 2026/01/14 14:10:53 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():_name("default"), _signed(false), sign_grade(150), exec_grade(150), target("default"){}

AForm::AForm(const AForm& copy):_name(copy.getName()), _signed(copy.getSigned()), sign_grade(copy.getSignGrade()), exec_grade(copy.getExecGrade()), target(copy.target)
{
	*this = copy;
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return (*this);
}

AForm::AForm(const std::string& name, int sign_grade, int exec_grade, std::string target):_name(name), _signed(false), sign_grade(sign_grade), exec_grade(exec_grade), target(target)
{
		if (this->sign_grade < 1 || this->exec_grade < 1)
			throw GradeTooHighException();
		if (this->sign_grade > 150 || this->exec_grade > 150)
			throw GradeTooLowException();
}

AForm::~AForm(){}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << AForm.getName() << ", AForm sign grade " << AForm.getSignGrade() << ", AForm sign status " << AForm.getSigned() << ", AForm execution grade " << AForm.getExecGrade();
	return (os);
}

const std::string AForm::getName()const{return this->_name;}
bool AForm::getSigned()const{return this->_signed;}
int AForm::getSignGrade()const{return this->sign_grade;}
int AForm::getExecGrade()const{return this->exec_grade;}

void AForm::beSigned(Bureaucrat& employee)
{
		if (employee.getGrade() > this->sign_grade)
			throw GradeTooLowException();
		this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw(){ return "AForm::GradeTooHighException"; }

const char *AForm::GradeTooLowException::what() const throw(){ return "AForm::GradeTooLowException"; }

const char *AForm::NotSignedForm::what() const throw(){ return "AForm::NotSignedForm"; }

void AForm::setSigned(bool expression){this->_signed = expression;}

std::string AForm::getTarget() const {return this->target;}

void AForm::setTarget(std::string target) {this->target = target;}
