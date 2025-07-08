#include<iostream>
#include<string>
#include<memory>    //smart pointers
#include<vector>
using namespace std;    

//My favorite car is Bentley Continental GT V8 (2021)
//I added the details of the SmartSystem, Suspension
//I used smart pointers

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
};

class Engine : public Part {
public:
    void EngineDetails() {
        cout << "4.0L V8 twin-turbo, 550 hp\n";
    }
    void print() override {
        EngineDetails();
    }
};

class Wheel : public Part {
public:
    void WheelDetails() {
        cout << "21-inch 10-spoke alloy wheels\n";
    }
    void print() override {
        WheelDetails();
    }
};

class Brake : public Part {
public:
    void BrakeDetails() {
        cout << "Carbon ceramic brakes\n";
    }
    void print() override {
        BrakeDetails();
    }
};

class Transmission : public Part {
public:
    void TransmissionDetails() {
        cout << "8-speed dual-clutch automatic transmission\n";
    }
    void print() override {
        TransmissionDetails();
    }
};

class SmartSystem : public Part {
public:
    void SmartSystemDetails() {
        cout << "Adaptive cruise control, lane assist, infotainment, night vision, and HUD\n";
    }
    void print() override {
        SmartSystemDetails();
    }
};

class Suspension : public Part {
public:
    void SuspensionDetails() {
        cout << "Adaptive air suspension with continuous damping control\n";
    }
    void print() override {
        SuspensionDetails();
    }
};

// In the UML diagram, Car and all the parts are in a composition relationship.
class Car {
public:
    Car() {
        engine_=make_unique<Engine>();
        for(int i = 0; i < 4; ++i) {
            wheels_.push_back(make_unique<Wheel>());
        }
        for(int i = 0; i < 4; ++i) {
            brakes_.push_back(make_unique<Brake>());
        }
        transmission_ = make_unique<Transmission>();
        SmartSystem_ = make_unique<SmartSystem>();
        suspension_ = make_unique<Suspension>();
    }
    
    void printParts() {
        cout<<"Engine: ";
        engine_->print();

        for(int i=0; i<4; ++i) {
            auto & ptr = wheels_[i];
            cout<< "Wheel " << i+1 << ": ";
            ptr->print();
        }

        for(int i=0; i<4; ++i) {
            auto & ptr = brakes_[i];
            cout<< "Brakes " << i+1 << ": ";
            ptr->print();
        }

        cout << "Transmission: ";
        transmission_->print();

        cout << "Smart System: ";
        SmartSystem_->print();

        cout << "Suspension: ";
        suspension_->print();
    }
    
    ~Car() {}
    
private:
    // Using smart pointers to up casting
    unique_ptr<Part> engine_;
    vector<unique_ptr<Part>> wheels_;
    vector<unique_ptr<Part>> brakes_;
    unique_ptr<Part> transmission_;
    unique_ptr<Part> SmartSystem_;
    unique_ptr<Part> suspension_;
};

int main() {
    
    Car myCar;
    cout << "My favorite car is Bentley Continental GT V8 (2021)\n";
    cout << "Here are the details of the car parts:\n";
    myCar.printParts();

    return 0;
}