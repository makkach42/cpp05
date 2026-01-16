/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:09 by makkach           #+#    #+#             */
/*   Updated: 2026/01/16 14:00:38 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    private:
        const std::string name;
        int Grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void signForm(AForm& f);
        void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif