#include <iostream>
using namespace std;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;

    int result = 0;  // ���
    int count = 0;   // IOI �ݺ� Ƚ��

    for (int i = 1; i < M - 1; ) {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            count++;         // IOI �� �� ã��
            if (count >= N)  // PN ���� ����
                result++;
            i += 2;          // IOI �������� �̵�
        }
        else {
            count = 0;       // ���ӵ� IOI ����
            i++;
        }
    }

    cout << result;
}
