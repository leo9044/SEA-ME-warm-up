#include<iostream>
#include<string>

using namespace std;

class Car{
    private:
        string make;
        string model;
        int year;
    public:
        Car(){
            make = "leo";
            model = "LEO1";
            year = 2025;
        }
        Car(const Car& rhs) : make(rhs.make), model(rhs.model), year(rhs.year) {}
        void operator=(const Car& rhs) {
            this->make = rhs.make;
            this->model = rhs.model;
            this->year = rhs.year;
        }
        ~Car() {}

        void drive() const {        // just read-only method
            cout << "Driving " << year << " " << make << " " << model <<" edition"<< endl;
        }
};

class SportsCar : public Car {
    private:
        int topSpeed;
    public:
        SportsCar(){
            topSpeed = 500;
        }
        SportsCar(const SportsCar& rhs) : Car(rhs) {    // Call the base class copy constructor --> up casting
            this->topSpeed=rhs.topSpeed;
        }
        void operator=(const SportsCar& rhs) {
            this->topSpeed = rhs.topSpeed;
        }
        ~SportsCar() {}

        void drive()    const {
            Car::drive();  // Call the base class method
            cout << "speed: " << topSpeed  << endl;
        }
};

int main(){
    cout<<"<Car c1>"<<endl;
    Car c1;
    c1.drive();
    cout<<"<Car c2>"<<endl;
    Car c2(c1);  // Copy constructor
    c2.drive();
    cout<<"<Car c3>"<<endl;
    Car c3;
    c3 = c2;     // Assignment operator
    c3.drive();

    cout<<"<Car sc1>"<<endl;
    SportsCar sc1;
    sc1.drive();
    cout<<"<SportsCar sc2>"<<endl;
    SportsCar sc2(sc1);  // Copy constructor
    sc2.drive();
    cout<<"<SportsCar sc3>"<<endl;
    SportsCar sc3;
    sc3 = sc2;     // Assignment operator
    sc3.drive();
}