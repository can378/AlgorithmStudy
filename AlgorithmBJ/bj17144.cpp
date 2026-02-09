#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>maps;
int R, C, T;
vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
vector<pair<int, int>> machine;

void spread() {
	vector<vector<int>> next(R, vector<int>(C, 0));

	// 공기청정기 위치는 그대로 -1 유지
	for (auto& m : machine) {
		next[m.first][m.second] = -1;
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {

			int now = maps[y][x];
			if (now <= 0) continue;           // 0이거나 -1이면 패스
			int spr = now / 5;

			int cnt = 0;
			for (int t = 0; t < 4; t++) {
				int ny = y + dirs[t][0];      // dy
				int nx = x + dirs[t][1];      // dx

				if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
				if (maps[ny][nx] == -1) continue;

				next[ny][nx] += spr;
				cnt++;
			}

			next[y][x] += now - spr * cnt;    // 남은 먼지
		}
	}

	maps = next;
}


void clean() {
	int up = machine[0].first;    // 위 공기청정기 y
	int down = machine[1].first;  // 아래 공기청정기 y

	// 위쪽 (반시계)
	// 왼쪽 열 ↑
	for (int y = up - 1; y > 0; y--) maps[y][0] = maps[y - 1][0];
	// 윗줄 ←
	for (int x = 0; x < C - 1; x++) maps[0][x] = maps[0][x + 1];
	// 오른쪽 열 ↓
	for (int y = 0; y < up; y++) maps[y][C - 1] = maps[y + 1][C - 1];
	// 청정기 윗줄 →
	for (int x = C - 1; x > 1; x--) maps[up][x] = maps[up][x - 1];
	maps[up][1] = 0; // 청정기 바로 오른쪽은 0

	// 아래쪽 (시계)
	// 왼쪽 열 ↓
	for (int y = down + 1; y < R - 1; y++) maps[y][0] = maps[y + 1][0];
	// 아랫줄 ←
	for (int x = 0; x < C - 1; x++) maps[R - 1][x] = maps[R - 1][x + 1];
	// 오른쪽 열 ↑
	for (int y = R - 1; y > down; y--) maps[y][C - 1] = maps[y - 1][C - 1];
	// 청정기 아랫줄 →
	for (int x = C - 1; x > 1; x--) maps[down][x] = maps[down][x - 1];
	maps[down][1] = 0; // 청정기 바로 오른쪽은 0

	// 공기청정기 위치 유지
	maps[up][0] = -1;
	maps[down][0] = -1;
}


int main() {
	cin >> R >> C >> T;
	maps=vector<vector<int>>(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++) {
		for (int k = 0; k < C; k++) {
			int n; cin >> n;
			maps[i][k]=n;
			if (n == -1) { machine.push_back({i,k}); }
		}
	}

	for (int i = 0; i < T; i++) {
		spread();
		clean();
	}

	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int k = 0; k < C; k++) {
			if (maps[i][k] == -1)continue;
			result += maps[i][k];
		}
	}
	cout << result;

}