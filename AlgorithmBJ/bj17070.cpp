#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;
int N;
int pipe_map[17][17];
int result = 0;
vector<pair<int, int>> directions = { {1, 0}, { 0,1 }, { 1,1 } };
map<pair<int, int>, int> no_dir_map = {
	{{1,0}, 1},
	{{1,1},-1},
	{{0,1},0}
};

bool checkNext(int x,int y,pair<int,int>next_dir) {
	int nextX = x + next_dir.first;
	int nextY = y + next_dir.second;
	if (nextX<1 || nextY<1 || nextX>N || nextY>N) return false;
	if (pipe_map[nextX][nextY] != 0) return false;
	return true;
}
void dfs(int x, int y, pair<int,int>now_dir) {
	if (x == N && y == N) { result++; return; }

	for (int i = 0; i < 3; i++) {

		if (no_dir_map[now_dir] == i) continue;
		int nextX = x + directions[i].first;
		int nextY = y + directions[i].second;

		if (!checkNext(x, y, directions[i])) continue;		

		//1,1방향일경우에는 (1,0) (0,1) (1,1) 모두가 뚫려있나 확인해야함
		if (directions[i].first==1 && directions[i].second==1)
		{
			if (!checkNext(x, y, {1,0}))continue;
			if (!checkNext(x, y, { 0,1 }))continue;
		}

		dfs(nextX, nextY, directions[i]);
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			cin >> pipe_map[i][k];
		}
	}

	pipe_map[1][1] = 2;
	pipe_map[1][2] = 2;
	dfs(1, 2, { 0,1 });

	cout << result;
}