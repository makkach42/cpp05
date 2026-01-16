/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:29:02 by makkach           #+#    #+#             */
/*   Updated: 2026/01/16 13:38:42 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    private:
        /* data */
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        PresidentialPardonForm(const std::string& name, int grade, int exec_grade);
        void execute(Bureaucrat const & executor) const;
        void beSigned(Bureaucrat& employee);
        ~PresidentialPardonForm();
};

#endif