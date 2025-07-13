#pragma once

#include <QMainWindow>
#include <QList>
#include <QMutex>

#include "car.h"
#include "racetrack.h"
#include "carthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RacingGame; }
QT_END_NAMESPACE

// 메인 윈도우 클래스 - 경주 게임 GUI 및 로직 관리
class RacingGame : public QMainWindow {
    Q_OBJECT

public:
    explicit RacingGame(QWidget *parent = nullptr);
    ~RacingGame();

private slots:
    void startRace();   // 경주 시작 버튼 처리
    void pauseRace();   // 경주 일시정지 버튼 처리
    void exitGame();    // 종료 버튼 처리

    void updateCar1(int newPos);  // 1번 자동차 위치 갱신
    void updateCar2(int newPos);  // 2번 자동차 위치 갱신

private:
    Ui::RacingGame *ui;

    RaceTrack *track;             // 레이스 트랙 객체
    QList<Car*> cars;             // 자동차 리스트 (2대)
    QList<CarThread*> threads;    // 자동차별 스레드 리스트
    QMutex mutex;                 // 동기화 객체 (mutex)

    void resetPositions();        // 모든 자동차 위치 초기화
    void stopThreads();           // 모든 스레드 안전하게 종료
};
