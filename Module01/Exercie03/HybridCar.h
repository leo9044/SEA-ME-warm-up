#include"Car.h"

class HybridCar : public Car {
    private:
        int batteryCapacity;
    public:
        HybridCar();
        HybridCar(const HybridCar& rhs) ;
        HybridCar& operator=(const HybridCar& rhs) ;
        ~HybridCar() ;

        int getter_batteryCapacity() const ;
        void setter_batteryCapacity(int new_capacity) ;

        void MoreInformation() const override ;
};
