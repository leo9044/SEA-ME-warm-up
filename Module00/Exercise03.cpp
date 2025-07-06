#include<iostream>
#include<string>

using namespace std;

class OldPhoneBook{
    private:
        

};

int main() {
    OldPhoneBook phoneBook;
    
    while (true) {
		std::system("cls");	
        
        string choice;
		cout << "전화번호부 프로그램" << endl;
		cin >> choice;
 
		if(choice == "ADD"){phoneBook.ADD();}
        else if(choice == "SEARCH"){phoneBook.SEARCH();}
        else if(choice == "REMOVE"){phoneBook.REMOVE ();}
        else if(choice == "BOOKMARK"){phoneBook.BOOKMARK();}
        else if(choice == "EXIT") {cout << "Shut down the program." << endl; exit(0);} 
        else {cout << "Invalid input." << endl;}
		
        cout<< "Press any key to continue..." << endl;
        std::cin.ignore();      //버퍼를 비우기 위해 사용
        std::system("pause");
	}

    return 0;
}


