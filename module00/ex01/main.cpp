/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:19:57 by vbronov           #+#    #+#             */
/*   Updated: 2025/06/13 11:56:08 by vbronov          ###   ########.fr       */
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
        if (!std::getline(std::cin, command)) {
            // Handle EOF (Ctrl+D)
            std::cout << "\nEOF detected, exiting program." << std::endl;
            break;
        }

        if (command == "ADD")
        {
            Contact contact;
            std::string input;

            std::cout << "First Name: ";
            if (!std::getline(std::cin, input)) {
                std::cout << "\nEOF detected, canceling add operation." << std::endl;
                break;
            }
            while (input.empty()) {
                std::cout << "Field cannot be empty. First Name: ";
                if (!std::getline(std::cin, input)) {
                    std::cout << "\nEOF detected, canceling add operation." << std::endl;
                    break;
                }
            }
            if (std::cin.eof()) break;
            contact.setFirstName(input);

            std::cout << "Last Name: ";
            if (!std::getline(std::cin, input)) {
                std::cout << "\nEOF detected, canceling add operation." << std::endl;
                break;
            }
            while (input.empty()) {
                std::cout << "Field cannot be empty. Last Name: ";
                if (!std::getline(std::cin, input)) {
                    std::cout << "\nEOF detected, canceling add operation." << std::endl;
                    break;
                }
            }
            if (std::cin.eof()) break;
            contact.setLastName(input);

            std::cout << "Nickname: ";
            if (!std::getline(std::cin, input)) {
                std::cout << "\nEOF detected, canceling add operation." << std::endl;
                break;
            }
            while (input.empty()) {
                std::cout << "Field cannot be empty. Nickname: ";
                if (!std::getline(std::cin, input)) {
                    std::cout << "\nEOF detected, canceling add operation." << std::endl;
                    break;
                }
            }
            if (std::cin.eof()) break;
            contact.setNickname(input);

            std::cout << "Phone Number: ";
            if (!std::getline(std::cin, input)) {
                std::cout << "\nEOF detected, canceling add operation." << std::endl;
                break;
            }
            while (input.empty() || !isValidPhoneNumber(input)) {
                if (input.empty())
                    std::cout << "Field cannot be empty. Phone Number: ";
                else
                    std::cout << "Invalid phone number. Must contain digits and only allowed symbols (+, -, space, parentheses). Phone Number: ";
                if (!std::getline(std::cin, input)) {
                    std::cout << "\nEOF detected, canceling add operation." << std::endl;
                    break;
                }
            }
            if (std::cin.eof()) break;
            contact.setPhoneNumber(input);

            std::cout << "Darkest Secret: ";
            if (!std::getline(std::cin, input)) {
                std::cout << "\nEOF detected, canceling add operation." << std::endl;
                break;
            }
            while (input.empty()) {
                std::cout << "Field cannot be empty. Darkest Secret: ";
                if (!std::getline(std::cin, input)) {
                    std::cout << "\nEOF detected, canceling add operation." << std::endl;
                    break;
                }
            }
            if (std::cin.eof()) break;
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
                if (!std::getline(std::cin, indexStr)) {
                    std::cout << "\nEOF detected, canceling search operation." << std::endl;
                    break;
                }
                
                std::istringstream iss(indexStr);
                if (iss >> index && iss.eof()) {
                    validInput = true;
                } else {
                    std::cout << "Invalid input. Please enter a valid number.\n";
                }
            }
            
            if (std::cin.eof()) break;
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
