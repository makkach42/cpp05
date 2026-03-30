/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:29:08 by makkach           #+#    #+#             */
/*   Updated: 2026/03/04 13:43:27 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        void execute(const Bureaucrat& executor) const;
        void beSigned(const Bureaucrat& employee);
		static AForm *createRobotomy();
        ~RobotomyRequestForm();
};

#endif