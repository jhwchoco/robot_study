#include <iostream>
#include <string>

// 로봇 팔(Arm)을 설계도(Class)로 정의
class RobotArm {
private:
    std::string name;
    int batteryLevel;

public:
    // 생성자: 로봇이 태어날 때 실행
    RobotArm(std::string n) {
        name = n;
        batteryLevel = 100;
        std::cout << "[" << name << "] 시스템 기동. 배터리: " << batteryLevel << "%" << std::endl;
    }

    // 행동: 움직이기
    void move(int angle) {
        std::cout << "[" << name << "] 징~ (모터 소리) -> " << angle << "도로 이동합니다." << std::endl;
        batteryLevel -= 10;
    }

    // 상태 확인
    void status() {
        std::cout << "[" << name << "] 현재 배터리 잔량: " << batteryLevel << "%" << std::endl;
    }
};

int main() {
    // 설계도를 바탕으로 실제 로봇 생성 (객체화)
    RobotArm myRobot("Alpha-1");

    // 로봇에게 명령 내리기
    myRobot.move(45);
    myRobot.move(90);
    myRobot.status();

    return 0;
}
