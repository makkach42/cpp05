/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:13 by makkach           #+#    #+#             */
/*   Updated: 2026/03/03 20:36:22 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		// Bureaucrat d("qwerty", 1);
		// std::cout << "d:" << d << std::endl;
		// d.decrement();
		// std::cout << "d:" << d << std::endl;
		// d.increment();
		// std::cout << "d:" << d << std::endl;
		// std::cout << std::endl;

		// const Bureaucrat b(d);
		// std::cout << "b:" << b << std::endl;
		// Bureaucrat z(b);
		// std::cout << "z:" << z << std::endl;
		// std::cout << std::endl;

		// Bureaucrat n("azerty", 2);
		// std::cout << "n:" << n << std::endl;
		// n = b;
		// std::cout << "n:" << n << std::endl << std::endl;


		Form f("treaty 1", 1, 1);
		std::cout << "name:" << f.getName() << std::endl;
		std::cout << "signed:" << f.getSigned() << std::endl;
		std::cout << "execgrade:" << f.getExecGrade() << std::endl;
		std::cout << "signgrade:" << f.getSignGrade() << std::endl;
		std::cout << "f:[" << f << "]" << std::endl << std::endl;
		
		const Form f2("treaty 2", 1, 1);
		std::cout << "name:" << f2.getName() << std::endl;
		std::cout << "signed:" << f2.getSigned() << std::endl;
		std::cout << "execgrade:" << f2.getExecGrade() << std::endl;
		std::cout << "signgrade:" << f2.getSignGrade() << std::endl;
		std::cout << "f2:[" << f2 << "]" << std::endl << std::endl;

		const Form f3(f);
		std::cout << "const f3(nonconst f):[" << f3 << "]"<< std::endl << std::endl;
		
		Form f4(f2);
		std::cout << "nonconst f4(const f2):[" << f4 << "]" << std::endl << std::endl;
		
		const Form f5(f2);
		std::cout << "const f5(const f2):[" << f5 << "]" << std::endl << std::endl;
		
		Form f6(f);
		std::cout << "nonconst f6(nonconst f):[" << f6 << "]" << std::endl << std::endl;

		const Bureaucrat conburo("aaaa", 1);
		std::cout << "f.signed: " << f.getSigned() << std::endl;
		f.beSigned(conburo);
		std::cout << "f.signed: " << f.getSigned() << std::endl << std::endl;
		
		Bureaucrat buro("bbbb", 1);
		std::cout << "f6.signed: " << f6.getSigned() << std::endl;
		f6.beSigned(buro);
		std::cout << "f6.signed: " << f6.getSigned() << std::endl << std::endl;
		
		const Bureaucrat conburo2("cccc", 1);
		Form f7("ssss", 1, 1);
		std::cout << "f7.signed: " << f7.getSigned() << std::endl;
		f7.beSigned(conburo2);
		std::cout << "f7.signed: " << f7.getSigned() << std::endl << std::endl;
		
		Bureaucrat b3("b3", 1);
		Form f9("uuuu", 1, 1);
		std::cout << "f9.signed: " << f9.getSigned() << std::endl;
		b3.signForm(f9);
		std::cout << "f9.signed: " << f9.getSigned() << std::endl << std::endl;
		
		const Bureaucrat b4("b4", 1);
		Form f10("vvvv", 1, 1);
		std::cout << "f10.signed: " << f10.getSigned() << std::endl;
		b4.signForm(f10);
		std::cout << "f10.signed: " << f10.getSigned() << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
