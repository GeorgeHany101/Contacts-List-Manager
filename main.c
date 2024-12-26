#include <iostream>
#include "Contact.h"

using namespace std;

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    char choice;

    // Read contacts from file when the program starts
    Contact::readContactsFromFile(contacts, numContacts);

    do {
        cout << "Contact Management System" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Edit Contact" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Search Contact" << endl;
        cout << "5. Display Contacts" << endl;
        cout << "6. Delete All Contacts" << endl;
        cout << "7. Save Contacts to File" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            Contact::addContact(contacts, numContacts);
            break;
        case '2':
            Contact::editContact(contacts, numContacts);
            break;
        case '3':
            Contact::deleteContact(contacts, numContacts);
            break;
        case '4':
            Contact::searchContact(contacts, numContacts);
            break;
        case '5':
            Contact::displayContacts(contacts, numContacts);
            break;
        case '6':
            Contact::deleteAllContacts(contacts, numContacts);
            break;
        case '7':
            Contact::writeContactsToFile(contacts, numContacts);
            cout << "Contacts saved to file." << endl;
            break;
        case '8':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != '8');

    return 0;
}
