#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

const int MAX_CONTACTS = 100;

class Contact {
public:
    string name;
    string phone;
    string email;

    // Constructor to initialize a contact
    Contact(string n = "", string p = "", string e = "") : name(n), phone(p), email(e) {}

    // Static method to write contacts to file
    static void writeContactsToFile(const Contact contacts[], int numContacts);

    // Static method to read contacts from file
    static void readContactsFromFile(Contact contacts[], int& numContacts);

    // Static method to add a new contact
    static void addContact(Contact contacts[], int& numContacts);

    // Static method to delete all contacts
    static void deleteAllContacts(Contact contacts[], int& numContacts);

    // Static method to display contacts
    static void displayContacts(const Contact contacts[], int numContacts);

    // Static method to find index of contact by name
    static int findContactIndex(const Contact contacts[], int numContacts, const string& name);

    // Static method to edit a contact
    static void editContact(Contact contacts[], int numContacts);

    // Static method to delete a contact
    static void deleteContact(Contact* contacts, int& numContacts);

    // Static method to search a contact by name or phone number
    static void searchContact(const Contact contacts[], int numContacts);
};

#endif
