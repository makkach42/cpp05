/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:11 by makkach           #+#    #+#             */
/*   Updated: 2026/01/14 13:01:34 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("default"), Grade(150){}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name), Grade(150)
{
    try
    {
        if (grade > 150)
            throw 1;
        else if (grade < 1)
            throw 2;
        this->Grade = grade;
    }
    catch(int i)
    {
        if (i == 1)
            std::cerr << "Bureaucrat::GradeTooLowException" << std::endl;
        else if (i == 2)
            std::cerr << "Bureaucrat::GradeTooLowException" << std::endl;
    }
}

Bureaucrat::~Bureaucrat(){}

std::ostream& operator<<(std::ostream& os, Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}

const std::string Bureaucrat::getName()const{ return this->name; }

int Bureaucrat::getGrade()const{ return this->Grade; }