/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:03:22 by jforner           #+#    #+#             */
/*   Updated: 2022/08/29 18:20:58 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H
# include <string>
# include <iostream>
# include <cstring>
# include <fstream>
# include <vector>
# include <list>
# include <algorithm>

using namespace std;
class Span {

private :
const unsigned int	N;
std::vector<int>	vec;

public:
	Span(unsigned int nbr);
	~Span(void);
        
	Span(const Span &copy);

	Span& operator=(const Span &copy);
	int operator[](unsigned int it);

	unsigned int getN(void);
	std::vector<int> getVec(void);

	void addNumber(int nbr);
	long shortestSpan();
	long longestSpan();

	void	addMoreNumbers(vector<int>::iterator const & begin ,vector<int>::iterator const & end);

	class TooMuchNumber: public std::exception
	{
		public:
		const char *	what(void) const throw();
	};

	class NotEnoughNumber: public std::exception
	{
		public:
		const char *	what(void) const throw();
	};
};
std::ostream&	operator<<(std::ostream& os, Span& s2);
#endif