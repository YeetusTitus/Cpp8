/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:49:00 by jforner           #+#    #+#             */
/*   Updated: 2022/09/01 21:52:57 by jforner          ###   ########.fr       */
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
    MutantStack(void);
    ~MutantStack(void);
        
    MutantStack(const MutantStack &copy);

    MutantStack<T>& operator=(MutantStack &copy);

    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
    iterator begin();
    iterator end();

    typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
    const_iterator cbegin() const;
    const_iterator cend() const;

    typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin();
    reverse_iterator rend();

    typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
};


#endif