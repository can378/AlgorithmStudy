#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int result = 0;

void check(int y, int x, int size) {
    if (size == 1) return; // �� �̻� �ɰ� �� ������ return

    int half = size / 2;
    int area = half * half;

    if (r < y + half && c < x + half) {
        // 1��и� (���� ��)
        check(y, x, half);
    }
    else if (r < y + half && c >= x + half) {
        // 2��и� (������ ��)
        result += area; // 1��и� ������ŭ ���ϱ�
        check(y, x + half, half);
    }
    else if (r >= y + half && c < x + half) {
        // 3��и� (���� �Ʒ�)
        result += area * 2; // 1,2��и� ������ŭ ���ϱ�
        check(y + half, x, half);
    }
    else {
        // 4��и� (������ �Ʒ�)
        result += area * 3; // 1,2,3��и� ������ŭ ���ϱ�
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
