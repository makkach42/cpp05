/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:29:08 by makkach           #+#    #+#             */
/*   Updated: 2026/01/23 10:51:56 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
// #include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm(const std::string& name, int grade, int exec_grade, std::string target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        void execute(Bureaucrat const & executor) const;
        void beSigned(Bureaucrat& employee);
		static AForm *createRobotomy();
        ~RobotomyRequestForm();
};

#endif