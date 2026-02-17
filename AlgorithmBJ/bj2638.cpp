#include <iostream>
#include <queue>
#include<vector>
using namespace std;
int N, M;
typedef pair<int, int> p;
vector<vector<int>>maps;
vector<vector<int>>visited;

vector<vector<int>> dirs = { {1,0},{0,1},{0,-1},{-1,0} };
int result = 0;

bool meltable(int x, int y) {

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int n_x = x + dirs[i][0];
		int n_y = y + dirs[i][1];

		if (n_x < 0 || n_y < 0 || n_x >= M || n_y >= N)continue;
		if (maps[n_y][n_x]!=0)continue;
		if (visited[n_y][n_x] == 0)continue;
		cnt++;
	}

	if (cnt >= 2) { return true; }
	return false;
}

bool is_all_melt() {
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			if (maps[i][k] == 1) { return false; }
		}
	}
	return true;
}

void melt() {

	if (is_all_melt()) { return; }
	result++;
	vector<p>candidates;
	visited = vector<vector<int>>(N, vector<int>(M, 0));

	queue<p>q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	while (!q.empty()) {

		p now = q.front();
		q.pop();
		int x = now.second;
		int y = now.first;

		for (int i = 0; i < 4; i++) {
			int n_x = x + dirs[i][0];
			int n_y = y + dirs[i][1];

			if (n_x < 0 || n_y < 0 || n_x >= M || n_y >= N)continue;
			if (visited[n_y][n_x])continue;

			visited[n_y][n_x] = 1;
			if (maps[n_y][n_x] == 1) {
				candidates.push_back({ n_x,n_y });
			}
			else {
			
				q.push({ n_y,n_x });
			}
		}
	}
	vector<p> remove;

	for (auto& c : candidates) {
		if (meltable(c.first, c.second)) { remove.push_back({ c.first,c.second }); }
	}

	for (auto& r : remove) {
		maps[r.second][r.first] = 0;
	}
	melt();
}



int main() {

	//INPUT
	cin >> N >> M;
	maps = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			cin >> maps[i][k];
		}
	}

	//CALCULATE
	melt();

	//RESULT
	cout << result;
}