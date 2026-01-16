/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:13 by makkach           #+#    #+#             */
/*   Updated: 2026/01/16 14:16:16 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat b("qwerty", 5);
    std::cout << b << std::endl;
    PresidentialPardonForm f("arther morgan", 150, 1);
    b.signForm(f);
    // f.execute(b);
    b.executeForm(f);
    return 0;
}
