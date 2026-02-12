#include <iostream>
#include <string>

// 로봇의 상태를 나타내는 구조체
struct Robot {
    std::string name;
    int hp;
};

// [잘못된 수리공] - 복사본만 고침
void fakeRepair(Robot r) {
    std::cout << "--- [돌팔이 수리공] 수리 중... ---" << std::endl;
    r.hp = 100;
}

// [진짜 수리공] - 원본 주소(Pointer)를 찾아가서 고침
void realRepair(Robot* r) {
    std::cout << "--- [전문 수리공] 수리 중... ---" << std::endl;
    r->hp = 100; // 화살표(->)는 주소를 따라간다는 뜻
}

int main() {
    // 1. 고장 난 로봇 생성
    Robot myBot = {"Battle-Bot", 10};

    std::cout << "[상태] 수리 전 체력: " << myBot.hp << std::endl;

    // 2. 주소(&)를 넘겨서 진짜 수리
    realRepair(&myBot);
    
    std::cout << "[상태] 전문가 수리 후: " << myBot.hp << " (완전 회복!)" << std::endl;

    return 0;
}
