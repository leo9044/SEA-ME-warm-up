#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car(){
    make = "leo";
    model = "LEO1";
    year = 2025;
}
Car::Car(const Car& rhs) : make(rhs.make), model(rhs.model), year(rhs.year) {}
Car& Car::operator=(const Car& rhs) {
    this->make = rhs.make;
    this->model = rhs.model;
    this->year = rhs.year;
}
Car::~Car() {}

void Car:: drive() const {        // just read-only method
    cout<<"###Base Car###"<<endl;;
    cout << "Driving " << year << " " << make << " " << model <<" edition"<< endl;
    MoreInformation(); // Call the pure virtual function
}

string Car::getter_make() const {
    return make;
}
string Car:: getter_model() const {
    return model;
}
int Car:: getter_year() const {
    return year;
}
void Car::setter_make(const string& new_make) {
    make = new_make;
}
void Car:: setter_model(const string& new_model) {
    model = new_model;
}
void Car:: setter_year(int new_year) {
    year = new_year;
}