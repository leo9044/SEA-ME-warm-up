#include "contact.h"

Contact::Contact(QString name, QString phone, QString email)
    : m_name(name), m_phone(phone), m_email(email) {}

QString Contact::getName() const { return m_name; }
QString Contact::getPhone() const { return m_phone; }
QString Contact::getEmail() const { return m_email; }

void Contact::setName(const QString &name) { m_name = name; }
void Contact::setPhone(const QString &phone) { m_phone = phone; }
void Contact::setEmail(const QString &email) { m_email = email; }
