/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:02:48 by makkach           #+#    #+#             */
/*   Updated: 2026/03/03 20:35:02 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():_name("default"), _signed(false), sign_grade(150), exec_grade(150){}

Form::Form(const Form& copy):_name(copy.getName()), _signed(copy.getSigned()), sign_grade(copy.getSignGrade()), exec_grade(copy.getExecGrade())
{
	*this = copy;
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		this->_signed = copy.getSigned();
	return (*this);
}

Form::Form(const std::string& name, int sign_grade, int exec_grade):_name(name), _signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw GradeTooHighException();
	if (this->sign_grade > 150 || this->exec_grade > 150)
		throw GradeTooLowException();
}

Form::~Form(){}

std::ostream &operator<<(std::ostream &os, Form &Form)
{
	os << Form.getName() << ", Form sign grade " << Form.getSignGrade() << ", Form sign status " << Form.getSigned() << ", Form execution grade " << Form.getExecGrade();
	return (os);
}

const std::string Form::getName()const{return this->_name;}
bool Form::getSigned()const{return this->_signed;}
int Form::getSignGrade()const{return this->sign_grade;}
int Form::getExecGrade()const{return this->exec_grade;}

void Form::beSigned(Bureaucrat& employee)
{
	if (employee.getGrade() > this->sign_grade)
		throw GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw(){ return "Form::GradeTooHighException"; }

const char *Form::GradeTooLowException::what() const throw(){ return "Form::GradeTooLowException"; }