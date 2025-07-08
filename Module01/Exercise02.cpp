#include<iostream>
#include<string>

using namespace std;

//1. 기본 클래스와 파생클래스 2개로 다형성 구현
//2. 기s보 클래스는 순수 가상 클래스로, 인터페이스 역할 --> ADT
//3. private에 변수 선언 및 getter, setter 메소드 구현 --> 캡슐화
//4. 상속
//5. 모듈화: 헤더파일, cpp 분리

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
        Car& operator=(const Car& rhs) {
            this->make = rhs.make;
            this->model = rhs.model;
            this->year = rhs.year;
        }
        ~Car() {}

        virtual void drive() const {        // just read-only method
            cout<<"###Base Car###"<<endl;;
            cout << "Driving " << year << " " << make << " " << model <<" edition"<< endl;
        }
};

class HybridCar : public Car {
    private:
        int batteryCapacity;
    public:
        HybridCar(){
            batteryCapacity = 100; // in kWh
        }
        HybridCar(const HybridCar& rhs) : Car(rhs) {    // Call the base class copy constructor --> up casting
            this->batteryCapacity = rhs.batteryCapacity;
        }
        HybridCar& operator=(const HybridCar& rhs) {
            // Call the base class assignment operator
            Car::operator=(rhs);  // Call the base class assignment operator
            this->batteryCapacity = rhs.batteryCapacity;
        }
        ~HybridCar() {}

        void drive() const override{
            cout<< "###Hybrid Car###"<<endl;;
            Car::drive();  // Call the base class method
            cout << "Battery capacity: " << batteryCapacity << " kWh" << endl;
        }
};

class ElectricCar : public Car {
    private:
        int range;
    public:
        ElectricCar(){
            range = 300; // in km
        }
        ElectricCar(const ElectricCar& rhs) : Car(rhs) {    // Call the base class copy constructor --> up casting
            this->range = rhs.range;
        }
        ElectricCar& operator=(const ElectricCar& rhs) {
            this->range = rhs.range;
        }
        ~ElectricCar() {}

        void drive() const override{
            cout<< "###Electric Car###"<<endl;
            Car::drive();  // Call the base class method
            cout << "Range: " << range << " km" << endl;
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

    
}