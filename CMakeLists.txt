# 최소 CMake 버전 지정
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름
project(Exercise02)

# 사용할 C++ 표준
set(CMAKE_CXX_STANDARD 17)

# 1. 분할된 소스 파일 목록 정의
set(EX_SOURCES
    Module01/main.cpp
    Module01/Car.cpp
    Module01/ElectricCar.cpp
    Module01/HybridCar.cpp
)

# 2. 실행 파일 생성 (이름: Ex)
add_executable(Ex ${EX_SOURCES})

# 3. 헤더파일(.h) 경로 지정 → #include 오류 방지용
target_include_directories(Ex PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Module01)
