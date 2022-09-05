/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:28:44 by jforner           #+#    #+#             */
/*   Updated: 2022/09/05 15:16:27 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <MutantStack.hpp>

int main(void)
{
    {
		cout << "\033[0;31m" << "case 0" << endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top = " << mstack.top() << std::endl;
		mstack.pop();

		std::cout << "size = " << mstack.size() << std::endl;
		cout << endl;
		mstack.push(3); mstack.push(5); mstack.push(737);


		MutantStack<int> s(mstack);

		s.pop();
		s.pop();
		s.pop();
		s.push(9);
		s.push(10);
		s.push(21);
		s.push(42);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		MutantStack<int>::iterator sit = s.begin();
		MutantStack<int>::iterator site = s.end();

		while (sit != site)
		{
			if (it < ite)
			{
				std::cout << it - mstack.begin() << " mstack = " << *it << std::endl;
				++it;
			}
			std::cout << sit - s.begin() << " s = " << *sit << std::endl;
			++sit;
		}
		
		cout << endl;

		stack<int> stck(mstack);

		std::cout << "top stck = " << stck.top() << std::endl;
		cout << endl;
	}


	{
		cout << "\033[0;32m" << "case 1" << endl;
		MutantStack<string> s1stack;
		MutantStack<string> s2stack;

		s1stack.push("yolo");
		s1stack.push("ptdr");
		s2stack.push("issou");

		MutantStack<string>::reverse_iterator si1 = s1stack.rbegin();
		MutantStack<string>::reverse_iterator s1e = s1stack.rend();
		MutantStack<string>::reverse_iterator si2 = s2stack.rbegin();
		MutantStack<string>::reverse_iterator s2e = s2stack.rend();

		
		while (si1 != s1e)
		{

			std::cout << s1e - (si1 + 1) << " s1 = " << *si1 << std::endl;
			++si1;
			if (si2 != s2e)
			{
				std::cout << s2e - (si2 + 1) << " s2 = " << *si2 << std::endl;
				++si2;
			}
			
		}

		cout << endl;
		s2stack = s1stack;

		s2stack.pop();
		s2stack.push("xd");

		si1 = s1stack.rbegin();
		si2 = s2stack.rbegin();
		
		while (si1 != s1e)
		{

			std::cout << s1e - (si1 + 1) << " s1 = " << *si1 << std::endl;
			++si1;
			if (si2 != s2e)
			{
				std::cout << s2e - (si2 + 1) << " s2 = " << *si2 << std::endl;
				++si2;
			}
		}

	}
	cout << "\033[0m";
    // system("leaks container");
    return 0;
}