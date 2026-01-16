/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:28:57 by makkach           #+#    #+#             */
/*   Updated: 2026/01/16 13:39:22 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):AForm(copy){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    (void)copy;
    return *this;
}

const char *PresidentialPardonForm::GradeTooHighException::what() const throw(){return "PresidentialPardonForm::GradeTooHighException";}

const char *PresidentialPardonForm::GradeTooLowException::what() const throw(){return "PresidentialPardonForm::GradeTooLowException";}


PresidentialPardonForm::PresidentialPardonForm(const std::string& name, int sign_grade, int exec_grade):AForm::AForm(name, sign_grade, exec_grade)
{
    try
    {
        if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
            throw GradeTooHighException();
        if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
            throw GradeTooLowException();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (executor.getGrade() > 5 || executor.getGrade() > this->getSignGrade())
            throw GradeTooLowException();
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void PresidentialPardonForm::beSigned(Bureaucrat& employee)
{
    try
    {
        if (employee.getGrade() < 25 && employee.getGrade() <= this->getSignGrade())
            this->setSigned(true);
        else
            throw GradeTooLowException();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

PresidentialPardonForm::~PresidentialPardonForm(){}
