#include "HybridCar.h"
#include <iostream>
using namespace std;

HybridCar::HybridCar(){
    batteryCapacity = 100; // in kWh
}
HybridCar::HybridCar(const HybridCar& rhs) : Car(rhs) {    // Call the base class copy constructor --> up casting
    this->batteryCapacity = rhs.batteryCapacity;
}
HybridCar& HybridCar::operator=(const HybridCar& rhs) {
    // Call the base class assignment operator
    Car::operator=(rhs);  // Call the base class assignment operator
    this->batteryCapacity = rhs.batteryCapacity;
}
HybridCar::~HybridCar() {}

int HybridCar::getter_batteryCapacity() const {
    return batteryCapacity;
}
void HybridCar::setter_batteryCapacity(int new_capacity) {
    batteryCapacity = new_capacity;
}

void HybridCar::MoreInformation() const {
    cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
}