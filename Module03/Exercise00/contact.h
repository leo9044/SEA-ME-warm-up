#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact(QString name = "", QString phone = "", QString email = "");

    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;

    void setName(const QString &name);
    void setPhone(const QString &phone);
    void setEmail(const QString &email);

private:
    QString m_name;
    QString m_phone;
    QString m_email;
};

#endif // CONTACT_H
