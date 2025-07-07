#include <iostream>
using namespace std;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;

    int result = 0;  // 결과
    int count = 0;   // IOI 반복 횟수

    for (int i = 1; i < M - 1; ) {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            count++;         // IOI 한 번 찾음
            if (count >= N)  // PN 패턴 만족
                result++;
            i += 2;          // IOI 다음으로 이동
        }
        else {
            count = 0;       // 연속된 IOI 끊김
            i++;
        }
    }

    cout << result;
}
