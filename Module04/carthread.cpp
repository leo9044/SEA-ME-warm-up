#include "carthread.h"
#include<QDebug>

CarThread::CarThread(Car *c, RaceTrack *t, QMutex *m, QObject *parent)
    : QThread(parent), car(c), track(t), mutex(m), stopped(false) {}

// run()이 스레드 진입점 - 자동차가 결승선까지 움직임 반복
void CarThread::run() {
    stopped = false;

    // 결승선 도달 전까지 계속 이동
    //int i=0;
    while (!stopped && car->position < track->finishLine) {
        //qDebug() << i<<Qt::endl;

        mutex->lock();       // 공유 자원 보호 위해 락 획득
        car->move();         // 자동차 이동
        mutex->unlock();     // 락 해제

        msleep(10);          // 너무 빠른 이동 방지 위해 10ms 대기

        if (QThread::currentThread()->isInterruptionRequested()) {
            stopped = true;  // 중단 요청 시 루프 탈출
        }
        //i++;
    }
}

// 외부에서 스레드 중단을 요청하는 함수
void CarThread::stop() {
    stopped = true;
    requestInterruption();  // QThread 인터럽트 요청
}
