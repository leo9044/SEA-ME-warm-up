#include "Car.h"

class ElectricCar : public Car {
    private:
        int range;
    public:
        ElectricCar();
        ElectricCar(const ElectricCar& rhs);
        ElectricCar& operator=(const ElectricCar& rhs);
        ~ElectricCar();

        int getter_range() const ;
        void setter_range(int new_range) ;

        void MoreInformation() const override ;
};