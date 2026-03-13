/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:11 by makkach           #+#    #+#             */
/*   Updated: 2026/03/04 13:54:13 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("default"), Grade(150){}

Bureaucrat::Bureaucrat(const Bureaucrat& copy):name(copy.name)
{
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		this->Grade = copy.getGrade();
	return (*this);
}


Bureaucrat::Bureaucrat(const std::string name, int grade):name(name), Grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->Grade = grade;
}

Bureaucrat::~Bureaucrat(){}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

const std::string Bureaucrat::getName()const{ return this->name; }

int Bureaucrat::getGrade()const{ return this->Grade; }

const char *Bureaucrat::GradeTooHighException::what() const throw() {return ("Bureaucrat::GradeTooHighException");}

const char *Bureaucrat::GradeTooLowException::what() const throw() {return ("Bureaucrat::GradeTooLowException");}

void Bureaucrat::signForm(Form& f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << this->name << " signed " << f.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << this->name << " couldn't sign " << f.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::increment()
{
	this->Grade--;
	if (this->Grade > 150)
		throw GradeTooLowException();
	if (this->Grade < 1)
		throw GradeTooHighException();	
}

void Bureaucrat::decrement()
{
	this->Grade++;
	if (this->Grade > 150)
		throw GradeTooLowException();
	if (this->Grade < 1)
		throw GradeTooHighException();
}