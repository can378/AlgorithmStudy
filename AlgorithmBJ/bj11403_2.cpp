#include <iostream>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX];
int N;

int main() {
    cin >> N;

    // 인접 행렬 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    // 플로이드-워셜로 모든 경로 탐색
    for (int k = 0; k < N; k++) {         // 거쳐가는 노드
        for (int i = 0; i < N; i++) {     // 출발 노드
            for (int j = 0; j < N; j++) { // 도착 노드
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1; // i->k->j 경로 있으면 i->j도 연결
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
