#include "contactlist.h"
#include <QFile>
#include <QTextStream>

void ContactList::addContact(const Contact &contact) {
    contacts.push_back(contact);
}

void ContactList::removeContact(int index) {
    if (index >= 0 && index < contacts.size()) {
        contacts.erase(contacts.begin() + index);
    }
}

const Contact &ContactList::getContact(int index) const {
    return contacts.at(index);
}

int ContactList::getSize() const {
    return contacts.size();
}

std::vector<Contact> ContactList::search(const QString &query) const {
    std::vector<Contact> results;
    for (const Contact &c : contacts) {
        if (c.getName().contains(query, Qt::CaseInsensitive)) {
            results.push_back(c);
        }
    }
    return results;
}

bool ContactList::saveToFile(const QString &filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    for (const Contact &c : contacts) {
        out << c.getName() << "," << c.getPhone() << "," << c.getEmail() << "\n";
    }
    file.close();
    return true;
}

bool ContactList::loadFromFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    contacts.clear();

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() >= 3) {
            Contact c(parts[0], parts[1], parts[2]);
            contacts.push_back(c);
        }
    }
    file.close();
    return true;
}
