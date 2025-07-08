#include "ElectricCar.h"
#include <iostream>
using namespace std;

ElectricCar::ElectricCar(){
    range = 300; // in km
}
ElectricCar::ElectricCar(const ElectricCar& rhs) : Car(rhs) {    // Call the base class copy constructor --> up casting
    this->range = rhs.range;
}
ElectricCar& ElectricCar::operator=(const ElectricCar& rhs) {
    this->range = rhs.range;
}
ElectricCar::~ElectricCar() {}

int ElectricCar::getter_range() const {
    return range;
}
void ElectricCar::setter_range(int new_range) {
    range = new_range;
}

void ElectricCar::MoreInformation() const {
    cout << "Range: " << range << " km" << endl;
}