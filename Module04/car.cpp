#include "car.h"
#include<QDebug>

Car::Car(QObject *parent)
    : QObject(parent), position(0), speed(0), direction(1) {}

void Car::move() {
    position += speed * direction;  // 현재 위치에 속도 * 방향만큼 더함
    //qDebug() << "Car moved to" << position;
    emit positionChanged(position); // 위치 변경 신호 발생
}

void Car::resetPosition() {
    position = 0;                   // 위치를 시작점으로 초기화
    emit positionChanged(position); // 초기 위치 알림
}
