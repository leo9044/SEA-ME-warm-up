#include<iostream>
#include<string>
#include "Car.h"
#include "HybridCar.h"
#include "ElectricCar.h"

using namespace std;

//o 1. 기본 클래스와 파생클래스 2개로 다형성 구현
//o 2. 기s보 클래스는 순수 가상 클래스로, 인터페이스 역할 --> ADT
//o 3. private에 변수 선언 및 getter, setter 메소드 구현 --> 캡슐화
//o 4. 상속
//o 5. 모듈화: 클래스 분리, 헤더파일, cpp 분리


int main(){
    Car * c= new HybridCar(); //up casting
    cout<<"<HybridCar hc>"<<endl;
    c->drive(); // Calls the drive method of HybridCar, which in turn calls MoreInformation
    delete c; 

    c=new ElectricCar(); //up casting
    cout<<"<ElectricCar ec>"<<endl;
    c->drive(); // Calls the drive method of ElectricCar, which in turn calls MoreInformation
    delete c;
}