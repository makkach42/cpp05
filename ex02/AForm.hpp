/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:02:51 by makkach           #+#    #+#             */
/*   Updated: 2026/01/14 14:07:56 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
class Bureaucrat;

class AForm
{
    class GradeTooHighException: public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
        public:
            const char *what() const throw();
    };
    private:
        const std::string _name;
        bool _signed;
        const int sign_grade;
        const int exec_grade;
    public:
        AForm();
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        AForm(const std::string& name, int grade, int exec_grade);
        ~AForm();
        const std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        virtual void beSigned(Bureaucrat& employee) = 0;
        virtual void execute(Bureaucrat const & executor) const;
        void setSigned(bool expression);
};

std::ostream &operator<<(std::ostream &stream, AForm &AForm);

#endif