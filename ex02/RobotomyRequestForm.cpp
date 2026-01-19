/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:29:05 by makkach           #+#    #+#             */
/*   Updated: 2026/01/19 13:28:36 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("default", 72, 45, "target"){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):AForm(copy){}
RobotomyRequestForm::RobotomyRequestForm(const std::string& name, int grade, int exec_grade, std::string target):AForm(name, grade, exec_grade, target)
{
    
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){(void)copy;return *this;}
RobotomyRequestForm::~RobotomyRequestForm(){}