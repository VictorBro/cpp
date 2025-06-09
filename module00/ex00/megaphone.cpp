/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:25:42 by vbronov           #+#    #+#             */
/*   Updated: 2025/06/08 00:28:00 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        std::string str(argv[i]);
        for (size_t j = 0; j < str.length(); ++j)
            str[j] = toupper(str[j]);
        std::cout << str;
    }
    std::cout << std::endl;

    return 0;
}