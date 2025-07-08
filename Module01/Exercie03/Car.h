#include<string>

class Car{
    private:
        std::string make;
        std::string model;
        int year;
    public:
        Car();
        Car(const Car& rhs);
        Car& operator=(const Car& rhs);
        ~Car();

        virtual void Car::MoreInformation() const = 0; // Pure virtual function to enforce derived classes to implement this method

        void drive() const;        // just read-only method

        std::string getter_make() const;
        std::string getter_model() const;
        int getter_year() const;
        void setter_make(const std::string& new_make);
        void setter_model(const std::string& new_model);
        void setter_year(int new_year);
};