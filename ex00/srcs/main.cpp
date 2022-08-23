/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:28:44 by jforner           #+#    #+#             */
/*   Updated: 2022/08/23 15:54:01 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>

int main(void)
{
    {
        int ar[] = {1, 2, 3, 4, 5};
        list<int>  li(ar, ar + sizeof(ar) / sizeof(int));

        cout << "list 4 = " << *easyfind(li, 4) << endl;
        try
        {
            cout << "list 6 = " << *easyfind(li, 6) << endl;
        }
        catch(const std::exception& e)
        {
            cerr << e.what() << '\n';
        }

        vector<int>  ve(ar, ar + sizeof(ar) / sizeof(int));

        cout << "vector 4 = " << *easyfind(ve, 3) << endl;
        try
        {
            cout << "vector 6 = " << *easyfind(ve, 6) << endl;
        }
        catch(const std::exception& e)
        {
            cerr << e.what() << '\n';
        }
        
    }
    // system("leaks template");
    return 0;
}