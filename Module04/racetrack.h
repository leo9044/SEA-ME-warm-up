#pragma once

// RaceTrack 클래스: 트랙 크기와 결승선을 관리
class RaceTrack {
public:
    int size;        // 트랙 길이
    int finishLine;  // 결승선 위치

    explicit RaceTrack(int s = 100, int f = 90);

    void setFinishLine(int newFinishLine);
};
