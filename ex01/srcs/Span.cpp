/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:51:08 by jforner           #+#    #+#             */
/*   Updated: 2022/08/29 18:21:15 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

//constructor & destructor

Span::Span(unsigned int nbr) : N(nbr)
{

  std::cout << "Span created !" << std::endl;
}

Span::Span(const Span &copy) : N(copy.N)
{
    unsigned int size = distance(copy.vec.begin(), copy.vec.end());
    if (vec.size() + size  > N)
    {
        vec.insert(vec.end(), copy.vec.begin(), copy.vec.begin() + (N - vec.size()));
        throw TooMuchNumber();
    }
    vec.insert(vec.end(), copy.vec.begin(), copy.vec.end());
    std::cout << "Span created from a copy!" << std::endl;
}

Span::~Span(void)
{

  std::cout << "Span destroyed!" << std::endl;
}

//operation overloader
Span& Span::operator=(const Span &copy)
{
    unsigned int size = distance(copy.vec.begin(), copy.vec.end());
    vec.clear();
    if (vec.size() + size  > N)
    {
        vec.insert(vec.end(), copy.vec.begin(), copy.vec.begin() + (N - vec.size()));
        throw TooMuchNumber();
    }
    vec.insert(vec.end(), copy.vec.begin(), copy.vec.end());
    return *this;
}
int Span::operator[](unsigned int it)
{
    return (vec[it]);
}

//getter & setter

unsigned int Span::getN(void)
{
    return (this->N);
}
std::vector<int> Span::getVec(void)
{
    return (this->vec);
}
//other
void    Span::addNumber(int nbr)
{
    if (vec.size() + 1 > N)
        throw TooMuchNumber();
    vec.push_back(nbr);
}

long Span::shortestSpan()
{
    if (vec.size() <= 1)
        throw NotEnoughNumber();
    long nbr = UINT_MAX;
    for(unsigned int i = 0; i < N - 1; i++)
    {
        for(unsigned int j = i + 1; j < N; j++)
            nbr = min(nbr, labs((long)vec[i] - (long)vec[j]));
    }
    return nbr;
}

long Span::longestSpan()
{
    if (vec.size() <= 1)
        throw NotEnoughNumber();
    long nbr = 0;
    for(unsigned int i = 0; i < N - 1; i++)
    {
        for(unsigned int j = i + 1; j < N; j++)
            nbr = max(nbr, labs((long)vec[i] - (long)vec[j]));
    }
    return nbr;
}

void    Span::addMoreNumbers(vector<int>::iterator const &  begin ,vector<int>::iterator const &  end)
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

//exception
const char *Span::TooMuchNumber::what(void) const throw()
{
    return "Too much numbers !";
}

const char *Span::NotEnoughNumber::what(void) const throw()
{
    return "Not enough numbers !";
}
//bonus
std::ostream&	operator<<(std::ostream& os, Span& s2)
{
    for(unsigned int i=0 ; i < s2.getVec().size(); i++)
    {
    	os << i << " = " << s2.getVec()[i] << std::endl;
    }
    return os;
}