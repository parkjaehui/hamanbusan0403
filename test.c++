#include <iostream>
#include <cmath>

class point {
private:
    int x, y;

public:
    point(int a, int b) : x(a), y(b) {}

    double Dist(point p) {
        int dx = p.getX() - x;
        int dy = p.getY() - y;
        double d = sqrt(dx * dx + dy * dy);
        return d;
    }

    point operator+(point p) {
        int nx = x + p.getX();
        int ny = y + p.getY();
        return point(nx, ny);
    }

    void Info() {
        std::cout << "p(" << x << ", " << y << ")";
    }

    // 후위 증가 연산자 오버로딩
    point operator++(int) {
        point temp = *this;
        x++;
        y++;
        return temp;
    }

    // 전위 증가 연산자 오버로딩
    point& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // x 멤버에 대한 getter 함수
    int getX() const {
        return x;
    }

    // y 멤버에 대한 getter 함수
    int getY() const {
        return y;
    }
};

template <typename T>
T area(T x1, T x2, T y1, T y2) {
    return (x2 - x1) * (y2 - y1);
}

int main() {
    point p1(10, 10), p2(30, 30);

    std::cout << "p1";
    p1.Info();
    std::cout << "과 p2";
    p2.Info();
    std::cout << "의 거리는 " << p1.Dist(p2) << "입니다." << std::endl;

    std::cout << "p1+p2는 ";
    (p1 + p2).Info();
    std::cout << std::endl;

    std::cout << "연산의 결과는 p";
    (p1++).Info();
    std::cout << std::endl;

    std::cout << "연산의 결과는 p";
    (++p1).Info();
    std::cout << std::endl;

    std::cout << "면적 계산 (정수 10, 10, 30, 30): " << area(10, 10, 30, 30) << std::endl;

    // p2.x = 50; // 이 부분을 수정해야 합니다. private 멤버에 직접 접근하려는 시도이므로 오류 발생
    return 0;
}

