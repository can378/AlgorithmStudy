#include <iostream>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX];
int N;

int main() {
    cin >> N;

    // ���� ��� �Է�
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    // �÷��̵�-���ȷ� ��� ��� Ž��
    for (int k = 0; k < N; k++) {         // ���İ��� ���
        for (int i = 0; i < N; i++) {     // ��� ���
            for (int j = 0; j < N; j++) { // ���� ���
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1; // i->k->j ��� ������ i->j�� ����
            }
        }
    }

    // ��� ���
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
