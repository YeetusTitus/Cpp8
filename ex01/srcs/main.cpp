/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:28:44 by jforner           #+#    #+#             */
/*   Updated: 2022/08/29 18:22:35 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <Span.hpp>

int main(void)
{
    {
		cout << "\033[0;31m";
        Span s(3);
        Span s3(3);
		Span s4(2);
		Span s5(2);
		Span s6(10000);

		vector<int> v;
    	v.push_back(10);
    	v.push_back(20);
    	v.push_back(30);

		try
		{
			s.longestSpan();
		}
		catch(const std::exception& e)
		{
			cerr << "\033[0;32m" << e.what() << "\033[0m" << '\n';
		}
		
		s.addNumber(2);
		try
		{
			s.shortestSpan();
		}
		catch(const std::exception& e)
		{
			cerr << "\033[0;32m" << e.what() << "\033[0;31m" << '\n';
		}

		s3 = s;
		s.addNumber(42);
		Span s2(s);

        try
        {
			s.addNumber(3);
            s.addNumber(0);
        }
        catch(const std::exception& e)
        {
			cerr << "\033[0;32m" << e.what() << "\033[0m" << '\n';
        }
		
        try
        {
            s2.addNumber(8);
            //trhow
            s2.addNumber(0);
        }
        catch(const std::exception& e)
        {
			cerr << "\033[0;32m" << e.what() << "\033[0m" << '\n';
        }

		try
		{
			s4 = s2;
		}
		catch(const std::exception& e)
		{
			cerr << "\033[0;32m" << e.what() << "\033[0m" << '\n';
		}
		
		
		try
		{
			s3.addMoreNumbers(v.begin(), v.end());
		}
		catch(const std::exception& e)
		{
			cerr << "\033[0;32m" << e.what() << "\033[0m" << '\n';
		}

		cout << "\033[0;33m";
		s5.addNumber(INT_MAX);
		s5.addNumber(INT_MIN);


		for (int j = 0;j <10000 ; j++)
			s6.addNumber(j);
	
		cout << "s : " << s << "shortest span = " << s.shortestSpan() << endl << "longest span = " << s.longestSpan() << endl << endl;
		cout << "s2 : " << s2 << "shortest span = " << s2.shortestSpan() << endl << "longest span = " << s2.longestSpan() << endl << endl;
		cout << "s3 : " << s3 << "shortest span = " << s3.shortestSpan() << endl << "longest span = " << s3.longestSpan() << endl << endl;
		cout << "s4 : " << s4 << "shortest span = " << s4.shortestSpan() << endl << "longest span = " << s4.longestSpan() << endl << endl;
		cout << "s5 : " << s5 << "shortest span = " << s5.shortestSpan() << endl << "longest span = " << s5.longestSpan() << endl;
		// cout << "s6 : " << s6 << "shortest span = " << s6.shortestSpan() << endl << "longest span = " << s6.longestSpan() << std::endl;
		cout << "\033[0;31m";	
	}
	cout << "\033[0;0m";
    // system("leaks container");
    return 0;
}