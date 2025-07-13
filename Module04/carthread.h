#pragma once

#include <QThread>
#include <QMutex>
#include "car.h"
#include "racetrack.h"

// 자동차 움직임을 별도 스레드에서 처리하는 클래스
class CarThread : public QThread {
    Q_OBJECT

public:
    // 생성자: 자동차와 트랙, 뮤텍스(동기화 객체) 참조 전달
    explicit CarThread(Car *car, RaceTrack *track, QMutex *mutex, QObject *parent = nullptr);

    // 스레드 실행 함수 재정의
    void run() override;

    // 안전하게 스레드 중단 요청
    void stop();

private:
    Car *car;
    RaceTrack *track;
    QMutex *mutex;
    bool stopped = false;  // 스레드 중단 상태 플래그
};
