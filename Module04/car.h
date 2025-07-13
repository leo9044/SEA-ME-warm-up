#pragma once

#include <QObject>

// Car 클래스: 자동차의 상태를 나타냄
class Car : public QObject {
    Q_OBJECT

public:
    // 멤버 변수 - 예제 단순화를 위해 public으로 선언
    int position;   // 현재 위치
    int speed;      // 이동 속도
    int direction;  // 이동 방향 (1: 오른쪽, -1: 왼쪽)

    explicit Car(QObject *parent = nullptr);

    // 자동차를 이동시키는 함수
    void move();

    // I added it. 위치를 초기화하는 함수 (경주 시작 전 호출)
    void resetPosition();

signals:
    // 위치가 변경되었을 때 발생하는 시그널
    void positionChanged(int newPosition);
};
