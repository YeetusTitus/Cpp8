/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:28:44 by jforner           #+#    #+#             */
/*   Updated: 2022/09/01 21:24:46 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <MutantStack.hpp>

int main(void)
{
    {
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();

		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737);
		//[...] mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack); return 0;	
	}
	cout << "\033[0;0m";
    // system("leaks container");
    return 0;
}