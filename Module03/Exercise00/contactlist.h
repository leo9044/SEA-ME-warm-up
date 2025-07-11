#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <vector>
#include "contact.h"

class ContactList {
public:
    void addContact(const Contact &contact);
    void removeContact(int index);
    const Contact &getContact(int index) const;
    int getSize() const;
    std::vector<Contact> search(const QString &query) const;

    // file I/O
    bool saveToFile(const QString &filename) const;
    bool loadFromFile(const QString &filename);

private:
    std::vector<Contact> contacts;
};

#endif // CONTACTLIST_H
