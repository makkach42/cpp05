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

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int sign_grade;
		const int exec_grade;
		std::string target;
	public:
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
		class NotSignedForm: public std::exception
		{
			public:
				const char *what() const throw();
		};
		AForm();
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		AForm(const std::string& name, int grade, int exec_grade, std::string target);
		virtual ~AForm();
		const std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		std::string getTarget() const;
		void beSigned(Bureaucrat& employee);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void setSigned(bool expression);
		void setTarget(std::string target);
};

std::ostream &operator<<(std::ostream &stream, const AForm &AForm);

#endif