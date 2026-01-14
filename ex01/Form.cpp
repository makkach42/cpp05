/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:02:48 by makkach           #+#    #+#             */
/*   Updated: 2026/01/14 14:10:53 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_name("default"), _signed(false), sign_grade(150), exec_grade(150){}

Form::Form(const std::string& name, int sign_grade, int exec_grade):_name(name), _signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
    try
    {
        if (this->sign_grade < 1 || this->exec_grade < 1)
            throw 1;
        if (this->sign_grade > 150 || this->exec_grade > 150)
            throw 2;
    }
    catch(int i)
    {
        if (i == 1)
            std::cerr << "Form::GradeTooHighException" << std::endl;            
        if (i == 2)
            std::cerr << "Form::GradeTooLowException" << std::endl;            
    }
}

Form::~Form(){}

std::ostream &operator<<(std::ostream &os, Form &form)
{
    os << form.getName() << ", form sign grade " << form.getSignGrade() << ", form sign status " << form.getSigned() << ", form execution grade " << form.getExecGrade();
    return (os);
}

const std::string Form::getName(){return this->_name;}
bool Form::getSigned(){return this->_signed;}
const int Form::getSignGrade(){return this->sign_grade;}
const int Form::getExecGrade(){return this->exec_grade;}

void Form::beSigned(Bureaucrat& employee)
{
    try
    {
        if (employee.getGrade() > this->sign_grade)
            throw 1;
        this->_signed = true;
    }
    catch(int i)
    {
        std::cerr << "Form::GradeTooLowException" << std::endl;
    }
}