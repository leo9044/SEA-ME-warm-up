#include "racetrack.h"

RaceTrack::RaceTrack(int s, int f)
    : size(s), finishLine(f) {}

void RaceTrack::setFinishLine(int newFinishLine) {
    finishLine = newFinishLine;
}
