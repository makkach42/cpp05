/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:29:10 by makkach           #+#    #+#             */
/*   Updated: 2026/01/23 09:53:40 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm():AForm("default", 145, 137, "target"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int sign_grade, int execute_grade, std::string target):AForm(name, sign_grade, execute_grade, target)
{
	try
	{
		if (sign_grade > 145 || execute_grade > 137)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy){*this = copy;}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy){AForm::operator=(copy);return *this;}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw(){ return "ShrubberyCreationForm::GradeTooHighException"; }

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw(){ return "ShrubberyCreationForm::GradeToolowException"; }

const char *ShrubberyCreationForm::BadFd::what() const throw(){ return "ShrubberyCreationForm::GradeToolowException"; }

void ShrubberyCreationForm::beSigned(Bureaucrat& employee)
{
	try
	{
		if (this->getSignGrade() <= 145 && this->getSignGrade() >= employee.getGrade())
			this->setSigned(true);
		else
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if ((this->getExecGrade() <= 137 && this->getSignGrade() <= 145) && executor.getGrade() <= 137 && executor.getGrade() <= this->getExecGrade())
		{
			std::ofstream of;
			of.open((this->getTarget() + "_shrubbery").c_str());
			if (!of.is_open())
				throw BadFd();
			std::string tree[] = 
			{
				  "     ccee88oo/"
				, "  C8O8O8Q8PoOb o8oo/"
				, " dOB69QO8PdUOpugoO9bD/"
				, "CgggbU8OU qOp qOdoUOdcb/"
				, "    6OuU  /p u gcoUodpP/"
				, "      /////  /douUP/"
				, "        ///p////"
				, "         |||///"
				, "         |||/p/"
				, "         |||||"
				,"   .....//||||||p...."
			};
			for (size_t i = 0; i < 11; i++)
			{
				of << tree[i];
				if (i < 10)
					of << std::string("\n");
			}
			of.close();
		}
		else
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
