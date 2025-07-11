#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // *** 추가된 코드: 시작 시 파일에서 연락처 불러오기 ***
    loadContactsFromFile();
    // *** 추가된 코드 끝 ***

    refreshAllContacts();

    //자동 슬롯 네이밍 규칙 문제
    //connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    //connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::on_removeButton_clicked);
    //connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // *** 추가된 코드: 종료 시 연락처 저장 ***
    saveContactsToFile();
    event->accept();
    // *** 추가된 코드 끝 ***
}

void MainWindow::on_addButton_clicked()
{
    QString name = ui->nameEdit->text().trimmed();  //  공백 제거
    QString phone = ui->phoneEdit->text().trimmed();
    QString email = ui->emailEdit->text().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Name cannot be empty!");
        return;
    }

    Contact newContact(name, phone, email);
    contactList.addContact(newContact);

    refreshAllContacts();

    ui->nameEdit->clear();
    ui->phoneEdit->clear();
    ui->emailEdit->clear();
}

void MainWindow::on_removeButton_clicked()
{
    int currentRow = ui->contactListWidget->currentRow();
    if (currentRow < 0 || currentRow >= contactList.getSize()) {
        QMessageBox::warning(this, "Warning", "No contact selected!");
        return;
    }
    contactList.removeContact(currentRow);
    refreshAllContacts();
}

void MainWindow::on_searchButton_clicked()
{
    QString query = ui->nameEdit->text();

    if (query.isEmpty()) {
        refreshAllContacts();
        return;
    }
    //result
    std::vector<Contact> results = contactList.search(query);
    //update UI List
    updateContactListWidget(results);
}

void MainWindow::updateContactListWidget(const std::vector<Contact> &contacts)
{
    ui->contactListWidget->clear();
    for (const auto &contact : contacts) {
        QString display = contact.getName() + " | " + contact.getPhone() + " | " + contact.getEmail();
        ui->contactListWidget->addItem(display);
    }
}

void MainWindow::refreshAllContacts()
{
    std::vector<Contact> allContacts;
    int size = contactList.getSize();
    for (int i = 0; i < size; ++i) {
        allContacts.push_back(contactList.getContact(i));
    }
    updateContactListWidget(allContacts);
}

// *** 추가된 함수들 ***

void MainWindow::saveContactsToFile()
{
    QFile file("contacts.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file to save contacts.");
        return;
    }

    QTextStream out(&file);
    int size = contactList.getSize();
    for (int i = 0; i < size; ++i) {
        const Contact &c = contactList.getContact(i);
        out << c.getName() << "," << c.getPhone() << "," << c.getEmail() << "\n";
    }
    file.close();
}

void MainWindow::loadContactsFromFile()
{
    QFile file("contacts.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 파일이 없으면 그냥 넘어가기 (첫 실행일 수 있음)
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 3) {
            Contact c(parts[0], parts[1], parts[2]);
            contactList.addContact(c);
        }
    }
    file.close();
}
// *** 추가된 함수들 끝 ***
