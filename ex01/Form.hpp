/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:02:51 by makkach           #+#    #+#             */
/*   Updated: 2026/01/18 10:57:57 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form
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
		Form();
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		Form(const std::string& name, int grade, int exec_grade);
		~Form();
		const std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(Bureaucrat& employee);
};

std::ostream &operator<<(std::ostream &stream, const Form &AForm);

#endif