#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int result = 0;

void check(int y, int x, int size) {
    if (size == 1) return; // 더 이상 쪼갤 수 없으면 return

    int half = size / 2;
    int area = half * half;

    if (r < y + half && c < x + half) {
        // 1사분면 (왼쪽 위)
        check(y, x, half);
    }
    else if (r < y + half && c >= x + half) {
        // 2사분면 (오른쪽 위)
        result += area; // 1사분면 영역만큼 더하기
        check(y, x + half, half);
    }
    else if (r >= y + half && c < x + half) {
        // 3사분면 (왼쪽 아래)
        result += area * 2; // 1,2사분면 영역만큼 더하기
        check(y + half, x, half);
    }
    else {
        // 4사분면 (오른쪽 아래)
        result += area * 3; // 1,2,3사분면 영역만큼 더하기
        check(y + half, x + half, half);
    }
}

int main() {
    cin >> N >> r >> c;
    int size = pow(2, N);
    check(0, 0, size);
    cout << result << endl;
    return 0;
}
