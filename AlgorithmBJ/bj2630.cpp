#include <iostream>
#include <vector>
using namespace std;

int white = 0, blue = 0;
int N;
vector<vector<int>> color;

bool isAllSame(int x, int y, int size) {
    int base = color[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (color[i][j] != base)
                return false;
        }
    }
    return true;
}

void checkColor(int x, int y, int size) {

    //CHECK COLOR
    if (isAllSame(x, y, size)) {
        if (color[x][y] == 1) blue++;
        else white++;
        return;
    }

    //TEAR THE PAPER
    int half = size / 2;
    checkColor(x, y, half);                          // ���� ��
    checkColor(x, y + half, half);                   // ������ ��
    checkColor(x + half, y, half);                   // ���� �Ʒ�
    checkColor(x + half, y + half, half);            // ������ �Ʒ�
}

int main() {
    //INPUT
    cin >> N;
    color = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> color[i][j];

    //CALCULATE
    checkColor(0, 0, N);

    //RESULT
    cout << white << '\n' << blue << '\n';
    return 0;
}
