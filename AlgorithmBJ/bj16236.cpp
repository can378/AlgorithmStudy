#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

vector<vector<int>> dirs = { {-1,0},{0,-1},{0,1},{1,0} }; // 위,왼,오,아래
int visited[21][21];
int N;

int main() {

    //INPUT
    cin >> N;
    int shark_size = 2;
    int eat_count = 0;
    int _time = 0;
    int start_x = 0, start_y = 0;

    vector<vector<int>> sea(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> sea[i][k];
            if (sea[i][k] == 9) { start_x = k; start_y = i; sea[i][k] = 0; }
        }
    }

    //CHECK
    while (true) {
        // visited를 "거리"로 쓰기 (-1이면 미방문)
        memset(visited, -1, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({ start_y, start_x });
        visited[start_y][start_x] = 0;

        int bestDist = -1;
        int bestY = -1, bestX = -1;

        while (!q.empty()) {
            int now_y = q.front().first;
            int now_x = q.front().second;
            q.pop();

            int d = visited[now_y][now_x];
            if (bestDist != -1 && d > bestDist) continue; // 이미 더 가까운 먹이 찾았으면 더 먼 레벨은 볼 필요 없음

            for (int i = 0; i < 4; i++) {
                int next_y = now_y + dirs[i][0];
                int next_x = now_x + dirs[i][1];

                if (next_y < 0 || next_x < 0 || next_x >= N || next_y >= N) continue;
                if (visited[next_y][next_x] != -1) continue;
                if (sea[next_y][next_x] > shark_size) continue;

                visited[next_y][next_x] = d + 1;

                // 먹을 수 있는 물고기면 후보 갱신 (거리 최소, 그 다음 위, 그 다음 왼)
                if (sea[next_y][next_x] > 0 && sea[next_y][next_x] < shark_size) {
                    int nd = visited[next_y][next_x];
                    if (bestDist == -1 ||
                        nd < bestDist ||
                        (nd == bestDist && (next_y < bestY || (next_y == bestY && next_x < bestX)))) {
                        bestDist = nd;
                        bestY = next_y;
                        bestX = next_x;
                    }
                }

                q.push({ next_y, next_x });
            }
        }

        // 더 이상 먹을 게 없으면 종료
        if (bestDist == -1) break;

        // 1마리 먹고 상태 업데이트
        _time += bestDist;
        start_y = bestY;
        start_x = bestX;
        sea[start_y][start_x] = 0;

        eat_count++;
        if (eat_count == shark_size) {
            shark_size++;
            eat_count = 0;
        }
    }


    //RESULT
    cout << _time;
    return 0;
}
