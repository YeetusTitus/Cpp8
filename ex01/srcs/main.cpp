/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:28:44 by jforner           #+#    #+#             */
/*   Updated: 2022/08/23 18:34:24 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <Span>

int main(void)
{
    {
        std::vector<int> vec;

        vec.push_back (2);
        vec.push_back(42);
		std::cout << vec[0] << std::endl;
		std::cout << vec[1] << std::endl;
    }
    // system("leaks template");
    return 0;
}