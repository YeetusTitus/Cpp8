/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:49:00 by jforner           #+#    #+#             */
/*   Updated: 2022/09/05 14:42:20 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <string>
# include <iostream>
# include <cstring>
# include <fstream>
# include <stack>
# include <list>

using namespace std;

template <typename T>
class MutantStack :  public stack<T> {

public:
    MutantStack(void): MutantStack<T>::stack()
    {}
    ~MutantStack(void)
    {}
        
    MutantStack(MutantStack<T> const &other) : MutantStack<T>::stack(other)
    {}

    MutantStack<T> operator=(MutantStack<T> &other)
    {
        MutantStack<T>::stack::operator=(other);
        return *this;
    }

    typedef typename MutantStack::stack::container_type::iterator iterator;
    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }

    typedef typename MutantStack::stack::container_type::const_iterator const_iterator;
    const_iterator cbegin() const
    {
        return this->c.cbegin();
    }

    const_iterator cend() const
    {
        return this->c.cend();
    }

    typedef typename MutantStack::stack::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin()
    {
        return this->c.rbegin();
    }

    reverse_iterator rend()
    {
        return this->c.rend();
    }

    typedef typename MutantStack::stack::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator crbegin() const
    {
        return this->c.crbegin();
    }

    const_reverse_iterator crend() const
    {
        return this->c.crend();
    }
};


#endif