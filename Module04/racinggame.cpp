#include "racinggame.h"
#include "ui_racinggame.h"

#include <QPixmap>

//생성자에서 많은 기능 수행
RacingGame::RacingGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RacingGame)
{
    ui->setupUi(this);

    //ui파일에 다 있으므로 이미지 넣을 필요 없음.
    //ui->trackLabel->setPixmap(QPixmap(":/new/prefix1/resources/racetrack.png"));
    //ui->trackLabel->setScaledContents(true);

    // 자동차 객체 2대 생성 및 초기 속도 설정
    track = new RaceTrack(100, 620);
    for (int i = 0; i < 2; ++i) {
        Car *car = new Car(this);
        car->speed=i+1;  // 자동차마다 속도 다르게
        cars.append(car);
    }

    // 자동차 위치 변경 시 UI 업데이트 시그널 연결
    connect(cars[0], &Car::positionChanged, this, &RacingGame::updateCar1);
    connect(cars[1], &Car::positionChanged, this, &RacingGame::updateCar2);

    // 버튼 클릭 시그널 연결
    connect(ui->startButton, &QPushButton::clicked, this, &RacingGame::startRace);
    connect(ui->pauseButton, &QPushButton::clicked, this, &RacingGame::pauseRace);
    connect(ui->exitButton, &QPushButton::clicked, this, &RacingGame::exitGame);

    // 자동차 위치 초기화
    resetPositions();
}

RacingGame::~RacingGame() {
    stopThreads();  // 종료 전 모든 스레드 안전 종료

    qDeleteAll(threads);
    qDeleteAll(cars);
    delete track;
    delete ui;
}

// 모든 자동차 위치를 0으로 초기화
void RacingGame::resetPositions() {
    for (Car *car : cars) {
        car->resetPosition();
    }

    // UI 상 자동차 레이블도 위치 초기화
    ui->car1Label->move(0, ui->car1Label->y());
    ui->car2Label->move(0, ui->car2Label->y());
}

// 스레드 모두 중단 요청하고 종료될 때까지 대기
void RacingGame::stopThreads() {
    for (CarThread *thread : threads) {
        thread->stop();      // 안전 중단 요청
        thread->wait();      // 종료 대기 (block)
    }
    qDeleteAll(threads);
    threads.clear();
}

// 경주 시작: 기존 스레드 중단 후 새 스레드 생성해 재시작
void RacingGame::startRace() {
    // 기존 스레드 안전 종료
    stopThreads();

    // 새 스레드 생성 및 실행
    for (Car *car : cars) {
        CarThread *thread = new CarThread(car, track, &mutex, this);
        threads.append(thread);
        thread->start();
    }
}

// 경주 일시정지: 스레드 중단 요청 및 종료 대기
void RacingGame::pauseRace() {
    stopThreads();
}

// 게임 종료 버튼: 윈도우 종료
void RacingGame::exitGame() {
    close();
}

// 1번 자동차 위치 UI 갱신
void RacingGame::updateCar1(int newPos) {
    // car1의 위치를 X = newPos, Y = 50으로 고정 (다른 차와 겹치지 않게)
    ui->car1Label->move(newPos, 40);
}

// 2번 자동차 위치 UI 갱신
void RacingGame::updateCar2(int newPos) {
    // car2의 위치를 X = newPos, Y = 100으로 고정 (car1과 겹치지 않게)
    ui->car2Label->move(newPos, 90);
}

