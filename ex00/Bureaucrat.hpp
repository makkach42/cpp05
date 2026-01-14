/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makkach <makkach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:53:09 by makkach           #+#    #+#             */
/*   Updated: 2026/01/14 13:00:13 by makkach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int Grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif