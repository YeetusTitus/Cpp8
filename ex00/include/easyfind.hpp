/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:36:45 by jforner           #+#    #+#             */
/*   Updated: 2022/08/23 15:24:46 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H
# include <string>
# include <iostream>
# include <cstring>
# include <fstream>
# include <list>
# include <vector>

using namespace std;
class OutRange: public std::exception
{
    public:
    const char *	what(void) const throw()
    {
        return "Index out of range !";
    }
};

template <typename T>

typename T::iterator easyfind(T tp, int i)
{
    typename T::iterator it = find(tp.begin(), tp.end(), i);
    if (it == tp.end())
        throw OutRange();
    return it;
}
#endif