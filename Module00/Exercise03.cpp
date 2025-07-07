#include<iostream>
#include<string>
#include <vector>
#include <unordered_map>

using namespace std;

class Contact {
    public:
        string name;
        string phoneNumber;
        string nickname;
        bool bookmarked;
};

class OldPhoneBook{
    private:
        vector<Contact> contacts;
        unordered_map<string, int> contactMap; // For quick lookup by phone number
    public: 
        void ADD() {
            Contact newContact;
            cout << "name: ";   getline(cin, newContact.name);
            cout << "phone number(Ex.12345678): ";  cin >> newContact.phoneNumber;
            cout << "nickname: ";   getline(cin, newContact.nickname);
            newContact.bookmarked = false;
            contacts.push_back(newContact);

            contactMap[newContact.phoneNumber] = contacts.size()-1; // Store in map for quick lookup
            return;
        }

        void PrintList() {
            cout << "###PhoneBook list###" << endl;
            for (int i = 0; i < contacts.size(); ++i) {
                const auto& contact = contacts[i];
                cout << i + 1 << ". " << contact.name << endl;
            }
        }

        void PrintDetail(const int i) {
            const auto& contact = contacts[i];
            cout << "###Contact Details###" << endl;
            cout << "Index: " << i + 1 << endl;
            cout << "name: " << contact.name << ", phone number: " << contact.phoneNumber 
                    << ", nickname: " << contact.nickname 
                    << ", bookmark: " << (contact.bookmarked ? "YES" : "NO") << endl;
            return;
        }

        void AddBookmark(void) {
            cout<< "###Add Bookmark###" << endl;
            cout<< "Enter the index of the contact to bookmark: ";
            int i;
            cin >> i;           --i; // Adjust for 0-based index
            if (i < 0 || i >= contacts.size()) {
                cout << "Invalid index." << endl;
                return;
            }
            contacts[i].bookmarked = true;
            cout << "It has been added to the bookmark!" << endl;
            return;
        }

        void SEARCH() {
            PrintList();
            
            int choice;
            cout<< "###Search Contacts###" << endl;
            cout<<"To add bookmarks: press 1" << endl;
            cout<<"To view details: press 2" << endl;
            cin>> choice;

            switch (choice) 
            {
            case 1:
                AddBookmark();
                break;
            
            case 2:
                int index;
                cout << "choose an index : ";
                cin >> index;
                for (int i = 0; i < contacts.size(); ++i)   if (i+1 == index) {PrintDetail(i); return;}
                cout << "There is no contact with that name." << endl;  return;   
                break;
            }
        }

        void REMOVE() {
            int choice;
            cout<<"###Remove Contact###" << endl;
            cout<<"deleting as an index: press 1" << endl;
            cout<<"deleting as a phone number: press 2" << endl;
            cin>> choice;
            
            switch (choice) 
            {
            case 1:
                {cout<<"Enter the index of the contact to delete: ";
                int index;
                cin >> index;           --index; // Adjust for 0-based index
                if (index < 0 || index >= contacts.size()) {
                    cout << "Invalid index." << endl;
                    return;
                }
                contacts.erase(contacts.begin() + index);
                cout << "contact has been deleted." << endl;
                return;}
            case 2:
                {cout << "Enter the phone number of the contact to delete: ";
                string phoneNumber;
                cin >> phoneNumber;
                auto it = contactMap.find(phoneNumber);     //반복자 반환   
                if (it != contactMap.end()) {
                    int index = it->second;         // Get the index from the map
                    contacts.erase(contacts.begin() + index);
                    contactMap.erase(it); // Remove from map
                    cout << "contact has been deleted." << endl;
                    return;
                }
                cout << "There is no contact for this phone number." << endl;
                return;}
            default:
                cout << "Invalid choice." << endl;
                return;
            };
        }

        void BOOKMARK() {
            cout << "###Bookmarked Contacts###" << endl;
            bool hasBookmark = false;
            for (int i = 0; i < contacts.size(); ++i) {
                if (contacts[i].bookmarked) {
                    PrintDetail(i);
                    hasBookmark = true;
                }
            }
            if (!hasBookmark) {
                cout << "There are no bookmarked contacts." << endl;
            }
        }

        void EXIT() {
            cout << "Shut down the program." << endl;
            exit(0);
        }
};

int main() {
    OldPhoneBook phoneBook;
    
    while (true) {
		std::system("clear"); // Clear the console screen
        cout << "Enter a command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT):	";
        string choice;
		getline(cin, choice);

        if(choice.empty()) {
            cout << "No input provided." << endl;
            continue;
        }
 
		if(choice == "ADD"){phoneBook.ADD();}
        else if(choice == "SEARCH"){phoneBook.SEARCH();}
        else if(choice == "REMOVE"){phoneBook.REMOVE ();}
        else if(choice == "BOOKMARK"){phoneBook.BOOKMARK();}
        else if(choice == "EXIT") {phoneBook.EXIT();} 
        else {cout << "Invalid input." << endl;}
		
        cout<< "Press any key to continue..." << endl;
        std::cin.ignore();      //버퍼를 비우기 위해 사용
        std::system("pause");
	}

    return 0;
}


