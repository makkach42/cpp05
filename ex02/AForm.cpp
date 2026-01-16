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

AForm::AForm():_name("default"), _signed(false), sign_grade(150), exec_grade(150){}

AForm::AForm(const AForm& copy):_name(copy.getName()), sign_grade(copy.getSignGrade()), exec_grade(copy.getExecGrade())
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

AForm::AForm(const std::string& name, int sign_grade, int exec_grade):_name(name), _signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
    try
    {
        if (this->sign_grade < 1 || this->exec_grade < 1)
            throw GradeTooHighException();
        if (this->sign_grade > 150 || this->exec_grade > 150)
            throw GradeTooLowException();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

AForm::~AForm(){}

std::ostream &operator<<(std::ostream &os, AForm &AForm)
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
    try
    {
        if (employee.getGrade() > this->sign_grade)
            throw GradeTooLowException();
        this->_signed = true;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

const char *AForm::GradeTooHighException::what() const throw(){ return "AForm::GradeTooHighException"; }

const char *AForm::GradeTooLowException::what() const throw(){ return "AForm::GradeToolowException"; }

void AForm::setSigned(bool expression){this->_signed = expression;}

void AForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (executor.getGrade() > this->getSignGrade())
            throw GradeTooLowException();
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}