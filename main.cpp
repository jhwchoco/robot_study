#include <iostream>
#include <string>

// 로봇 팔(Arm)을 설계도(Class)로 정의
class RobotArm {
private:
    std::string name;
#include <iostream>
#include <string>

// 어제 만든 기본 클래스 (부모)
class RobotArm {
protected: // 자식 클래스에서 접근 가능하도록 private에서 protected로 변경
    std::string name;
    int batteryLevel;

public:
    RobotArm(std::string n) : name(n), batteryLevel(100) {
        std::cout << "[" << name << "] 시스템 기동." << std::endl;
    }

    void move(int angle) {
        std::cout << "[" << name << "] " << angle << "도로 이동." << std::endl;
        batteryLevel -= 5;
    }
};

// 상속을 받은 새로운 클래스 (자식): 센서 기능이 추가됨
class SensorArm : public RobotArm {
public:
    // 부모의 생성자를 호출
    SensorArm(std::string n) : RobotArm(n) {}

    // 새로운 기능: 물체 탐지
    void detectObject() {
        std::cout << "[" << name << "] 초음파 센서 작동... 물체 감지 완료!" << std::endl;
        batteryLevel -= 10;
    }

    // 부모의 기능을 재정의 (Overriding): 센서 로봇은 더 정밀하게 이동
    void move(int angle) {
        std::cout << "[" << name << "] 센서 보정 적용하여 " << angle << "도로 정밀 이동." << std::endl;
        batteryLevel -= 7;
    }

    void showBattery() {
        std::cout << "[" << name << "] 현재 잔량: " << batteryLevel << "%" << std::endl;
    }
};

int main() {
    // 센서가 달린 새로운 로봇 생성
    SensorArm myRobot("Sensor-Bot");

    myRobot.move(30);        // 재정의된(Overriding) 함수 실행
    myRobot.detectObject();  // 자식만 가진 새로운 기능 실행
    myRobot.showBattery();

    return 0;
}    int batteryLevel;

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
