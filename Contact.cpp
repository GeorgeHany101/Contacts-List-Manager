#include "Contact.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void Contact::writeContactsToFile(const Contact contacts[], int numContacts) {
    ofstream outputFile("contacts.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    outputFile << left << setw(20) << "Name" << setw(15) << "Phone" << setw(30) << "Email" << endl;
    for (int i = 0; i < numContacts; i++) {
        outputFile << left << setw(20) << contacts[i].name << setw(15) << contacts[i].phone << setw(30) << contacts[i].email << endl;
    }

    outputFile.close();

    // Display contacts with delay and color
    cout << "Contact List" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < numContacts; i++) {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
#endif
        cout << "Name: " << contacts[i].name << endl;
        cout << "Phone: " << contacts[i].phone << endl;
        cout << "Email: " << contacts[i].email << endl;
        cout << "-----------------------" << endl;

#ifdef _WIN32
        SetConsoleTextAttribute(hConsole, 15);
#endif
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
}

void Contact::readContactsFromFile(Contact contacts[], int& numContacts) {
    ifstream inputFile("contacts.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    numContacts = 0;
    while (numContacts < MAX_CONTACTS && inputFile >> contacts[numContacts].name >> contacts[numContacts].phone >> contacts[numContacts].email) {
        numContacts++;
    }

    inputFile.close();
}

void Contact::addContact(Contact contacts[], int& numContacts) {
    if (numContacts == MAX_CONTACTS) {
        cout << "Contact list is full." << endl;
        return;
    }

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, contacts[numContacts].name);
    cout << "Enter phone number: ";
    cin >> contacts[numContacts].phone;
    cout << "Enter email address: ";
    cin >> contacts[numContacts].email;

    numContacts++;
}

void Contact::deleteAllContacts(Contact contacts[], int& numContacts) {
    numContacts = 0;
    cout << "All contacts deleted." << endl;
}

void Contact::displayContacts(const Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        cout << "Contact list is empty." << endl;
        return;
    }

    cout << "Contact List" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < numContacts; i++) {
        cout << "Name: " << contacts[i].name << endl;
        cout << "Phone: " << contacts[i].phone << endl;
        cout << "Email: " << contacts[i].email << endl;
        cout << "-----------------------" << endl;
    }
}

int Contact::findContactIndex(const Contact contacts[], int numContacts, const string& name) {
    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name == name) {
            return i;
        }
    }
    return -1;
}

void Contact::editContact(Contact contacts[], int numContacts) {
    string searchPhone;
    cout << "Enter the Phone of the contact to edit: ";
    cin >> searchPhone;

    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].phone == searchPhone) {

            cout << "Enter new name: ";
            cin >> contacts[i].name;
            cout << "Enter new phone number: ";
            cin >> contacts[i].phone;
            cout << "Enter new email address: ";
            cin >> contacts[i].email;
            cout << "Contact updated successfully." << endl;
            return;
        }
    }

    cout << "Contact not found." << endl;
}

void Contact::deleteContact(Contact* contacts, int& numContacts) {
    string searchPhone;
    cout << "Enter the Phone of the contact to delete: ";
    cin >> searchPhone;

    bool found = false;
    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].phone == searchPhone) {
            found = true;
            for (int j = i; j < numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            numContacts--;
            cout << "Contact deleted successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found." << endl;
    }
}

void Contact::searchContact(const Contact contacts[], int numContacts) {
    string searchTerm;
    cout << "Enter the name or phone number of the contact to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name == searchTerm || contacts[i].phone == searchTerm) {
            found = true;
            cout << "Contact found:" << endl;
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone: " << contacts[i].phone << endl;
            cout << "Email: " << contacts[i].email << endl;
            cout << "-----------------------" << endl;
        }
    }

    if (!found) {
        cout << "Contact not found." << endl;
    }
}
