/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:03:22 by jforner           #+#    #+#             */
/*   Updated: 2022/08/23 19:34:27 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H
# include <string>
# include <iostream>
# include <cstring>
# include <fstream>
# include <vector>
# include <algorithm>

using namespace std;
class Span {

private :
const unsigned int	N;
std::vector<int>	vec;

public:
	Span(void);
	~Span(void);
        
	Span(const Span &copy);

	Span& operator=(const Span &copy);

	void addNumber(int nbr)
	{
		if (vec.size() + 1 > N)
			throw TooMuchNumber();
		vec.push_back(nbr);
	}
	
	int shortestSpan()
	{
		if (vec.size() <= 1)
			throw NotEnoughNumber();
		int nbr;
		for(unsigned int i = 0; i < N - 1; i++)
		{
			for(unsigned int j = i + 1; j < N; j++)
				nbr = min(nbr, abs(vec[i] - vec[j]));
		}
		return nbr;
	}
	
	int longestSpan()
	{
		if (vec.size() <= 1)
			throw NotEnoughNumber();
		int nbr;
		for(unsigned int i = 0; i < N - 1; i++)
		{
			for(unsigned int j = i + 1; j < N; j++)
				nbr = max(nbr, abs(vec[i] - vec[j]));
		}
		return nbr;
	}

	void	addMoreNumbers(vector<int>::iterator & begin ,vector<int>::iterator & end)
	{
		unsigned int size = distance(begin, end);
		if (vec.size() + 1 >  N)
			throw TooMuchNumber();
		if (vec.size() + size  > N)
		{
			vec.insert(vec.end(), begin, begin + (N - vec.size()));
			throw TooMuchNumber();
		}
		vec.insert(vec.end(), begin, end);
	}

	class TooMuchNumber: public std::exception
	{
		public:
		const char *	what(void) const throw()
		{
			return "Too much numbers !";
		}
	};

	class NotEnoughNumber: public std::exception
	{
		public:
		const char *	what(void) const throw()
		{
			return "Not enough numbers !";
		}
	};
};

#endif