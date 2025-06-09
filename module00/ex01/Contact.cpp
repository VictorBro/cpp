/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:44:24 by vbronov           #+#    #+#             */
/*   Updated: 2025/06/10 00:18:41 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(const std::string &firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
    this->darkestSecret = darkestSecret;
}
std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}
std::string Contact::getNickname() const
{
    return nickname;
}
std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}
