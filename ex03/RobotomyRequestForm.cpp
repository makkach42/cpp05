/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:29:05 by makkach           #+#    #+#             */
/*   Updated: 2026/01/23 11:01:47 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("default", 72, 45, "target"){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):AForm(copy){}
RobotomyRequestForm::RobotomyRequestForm(const std::string& name, int grade, int exec_grade, std::string target):AForm(name, grade, exec_grade, target)
{
        if (grade > 72 || exec_grade > 45)
            throw AForm::GradeTooLowException();
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){AForm::operator=(copy);return *this;}
RobotomyRequestForm::~RobotomyRequestForm(){}

AForm *RobotomyRequestForm::createRobotomy(){ return new RobotomyRequestForm();}

void RobotomyRequestForm::beSigned(Bureaucrat& employee)
{
		if (this->getSignGrade() <= 72 && this->getSignGrade() >= employee.getGrade())
			this->setSigned(true);
		else
			throw AForm::GradeTooLowException();
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
		if (this->getSigned() == false)
			throw AForm::NotSignedForm();
		if ((this->getExecGrade() <= 45 && this->getSignGrade() <= 72) && executor.getGrade() <= 45 && executor.getGrade() <= this->getExecGrade())
		{
            srand(time(NULL));
            if (rand() % 2)
            {
                std::cout << "* drilling noises *" << std::endl;
                std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
            }
            else
            {
                std::cout << "* drilling noises *" << std::endl;
                std::cout << "the robotomy failed." << std::endl;
            }
		}
		else
			throw AForm::GradeTooHighException();
}
