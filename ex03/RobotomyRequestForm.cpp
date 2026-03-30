/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:29:05 by makkach           #+#    #+#             */
/*   Updated: 2026/03/04 14:11:36 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("default", 72, 45, "target"){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):AForm(copy){}
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45, target){}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){AForm::operator=(copy);return *this;}
RobotomyRequestForm::~RobotomyRequestForm(){}

AForm *RobotomyRequestForm::createRobotomy(){ return new RobotomyRequestForm("target");}

void RobotomyRequestForm::beSigned(const Bureaucrat& employee)
{
		if (this->getSignGrade() <= 72 && this->getSignGrade() >= employee.getGrade())
			this->setSigned(true);
		else
			throw AForm::GradeTooLowException();
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
		if (this->getSigned() == false)
			throw AForm::NotSignedForm();
		if ((this->getExecGrade() <= 45 && this->getSignGrade() <= 72) && executor.getGrade() <= 45 && executor.getGrade() <= this->getExecGrade())
		{
            static bool random = false;
            if (!random)
            {
                srand(time(NULL));
                random = true;
            }
            std::cout << "* drilling noises *" << std::endl;
            if (rand() % 2)
                std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
            else
                std::cout << "the robotomy failed." << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
}
