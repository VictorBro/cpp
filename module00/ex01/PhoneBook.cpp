/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:04:47 by vbronov           #+#    #+#             */
/*   Updated: 2025/06/10 00:17:42 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &contact)
{
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
    {
        totalContacts++;
    }
}

void PhoneBook::searchContacts() const
{
    std::cout << "     Index|First Name| Last Name|  Nickname\n";
    std::cout << "----------+----------+----------+----------\n";
    for (int i = 0; i < totalContacts; ++i)
    {
        std::cout << std::setw(10) << std::right << i << "|";
        
        // Format first name
        std::string firstName = contacts[i].getFirstName();
        if (firstName.length() > 10)
            std::cout << firstName.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << std::right << firstName;
        
        std::cout << "|";
        
        // Format last name
        std::string lastName = contacts[i].getLastName();
        if (lastName.length() > 10)
            std::cout << lastName.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << std::right << lastName;
        
        std::cout << "|";
        
        // Format nickname
        std::string nickname = contacts[i].getNickname();
        if (nickname.length() > 10)
            std::cout << nickname.substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << std::right << nickname;
        
        std::cout << "\n";
    }
}

void PhoneBook::displayContact(int index) const
{
    if (index < 0 || index >= totalContacts)
    {
        std::cout << "Invalid index.\n";
        return;
    }
    const Contact &contact = contacts[index];
    std::cout << "First Name: " << contact.getFirstName() << "\n"
              << "Last Name: " << contact.getLastName() << "\n"
              << "Nickname: " << contact.getNickname() << "\n"
              << "Phone Number: " << contact.getPhoneNumber() << "\n"
              << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
}
