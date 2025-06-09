/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:19:57 by vbronov           #+#    #+#             */
/*   Updated: 2025/06/10 00:15:58 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>

bool isValidPhoneNumber(const std::string &phoneNumber)
{
    if (phoneNumber.empty())
        return false;
    
    bool hasDigit = false;
    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        // example: +1 (123) 456-7890
        if (!isdigit(phoneNumber[i]) && 
            phoneNumber[i] != ' ' && 
            phoneNumber[i] != '-' && 
            phoneNumber[i] != '(' && 
            phoneNumber[i] != ')' &&
            phoneNumber[i] != '+')
        {
            return false;
        }
        
        if (isdigit(phoneNumber[i]))
            hasDigit = true;
    }
    
    // Must have at least one digit
    return hasDigit;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            Contact contact;
            std::string input;

            std::cout << "First Name: ";
            std::getline(std::cin, input);
            while (input.empty()) {
                std::cout << "Field cannot be empty. First Name: ";
                std::getline(std::cin, input);
            }
            contact.setFirstName(input);

            std::cout << "Last Name: ";
            std::getline(std::cin, input);
            while (input.empty()) {
                std::cout << "Field cannot be empty. Last Name: ";
                std::getline(std::cin, input);
            }
            contact.setLastName(input);

            std::cout << "Nickname: ";
            std::getline(std::cin, input);
            while (input.empty()) {
                std::cout << "Field cannot be empty. Nickname: ";
                std::getline(std::cin, input);
            }
            contact.setNickname(input);

            std::cout << "Phone Number: ";
            std::getline(std::cin, input);
            while (input.empty() || !isValidPhoneNumber(input)) {
                if (input.empty())
                    std::cout << "Field cannot be empty. Phone Number: ";
                else
                    std::cout << "Invalid phone number. Must contain digits and only allowed symbols (+, -, space, parentheses). Phone Number: ";
                std::getline(std::cin, input);
            }
            contact.setPhoneNumber(input);

            std::cout << "Darkest Secret: ";
            std::getline(std::cin, input);
            while (input.empty()) {
                std::cout << "Field cannot be empty. Darkest Secret: ";
                std::getline(std::cin, input);
            }
            contact.setDarkestSecret(input);

            phoneBook.addContact(contact);
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContacts();
            
            std::string indexStr;
            int index;
            bool validInput = false;
            
            while (!validInput) {
                std::cout << "Enter index to display details: ";
                std::getline(std::cin, indexStr);
                
                std::istringstream iss(indexStr);
                if (iss >> index && iss.eof()) {
                    validInput = true;
                } else {
                    std::cout << "Invalid input. Please enter a valid number.\n";
                }
            }
            
            phoneBook.displayContact(index);
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}
