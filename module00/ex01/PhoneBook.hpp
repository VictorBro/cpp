/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:23:12 by vbronov           #+#    #+#             */
/*   Updated: 2025/06/10 00:19:23 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact &contact);
    void searchContacts() const;
    void displayContact(int index) const;
};
