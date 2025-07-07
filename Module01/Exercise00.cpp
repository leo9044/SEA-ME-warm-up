#include <iostream>
#include <string>

using namespace std;

class Orthodox {
private:
    string name;
    int speed;

public:
    Orthodox() : name("leo"), speed(0) {
        cout << "Orthodox default constructor called" << endl;
        print();
    }

    Orthodox(const Orthodox& rhs) : name(rhs.name), speed(rhs.speed) {
        cout << "Orthodox copy constructor called" << endl;
        print();
    }

    void operator=(const Orthodox& rhs) {
        name = rhs.name;
        speed = rhs.speed;
        cout << "Orthodox copy assignment operator called" << endl;
        print();
    }

    void print() const {
        cout << "  [name: " << name << ", speed: " << speed << "]" << endl;
    }

    ~Orthodox() {
        cout << "Orthodox destructor called" << endl;
    }
};

int main() {
    cout << "--- Create x1 ---" << endl;
    Orthodox x1;                     

    cout << "--- Create x2 from x1 ---" << endl;
    Orthodox x2(x1);                

    cout << "--- Create x3 = x2 ---" << endl;
    Orthodox x3 = x2;         // This will call the copy constructor  

    cout << "--- Assign x3 = x2 ---" << endl;
    x3 = x2;                       

    cout << "--- End of main ---" << endl;
    return 0;
}
