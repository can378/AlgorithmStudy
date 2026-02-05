#include <iostream>
#include <vector>
#include<queue>

using namespace std;

typedef pair<int, int> p;
int N, M;
vector<vector<int>>map;
vector<int>picked_loc;
vector<p>blank;
vector<p>virus;
vector<p>dir = { {0,1},{0,-1},{1,0},{-1,0} };
int result = 0;

void calculate() {
	vector<vector<int>>map_copy = map;
	for (int i = 0; i < picked_loc.size(); i++) {
		p pick = blank[picked_loc[i]];

		map_copy[pick.first][pick.second] = 1;
	}

	
	queue<p>q;
	for (int i = 0; i < virus.size(); i++) {
		p v = virus[i];
		q.push({ v.first,v.second });
	}
	

	while (!q.empty()) {
		p now = q.front();
		q.pop();

		int y = now.first;
		int x = now.second;

		for (int i = 0; i < 4; i++) {
			int next_y = y + dir[i].first;
			int next_x = x + dir[i].second;

			if (next_y < 0 || next_x < 0 || next_x >= M || next_y >= N)continue;
			if (map_copy[next_y][next_x] == 1 || map_copy[next_y][next_x] == 2)continue;
			map_copy[next_y][next_x] = 2;
			q.push({ next_y,next_x });

		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			if (map_copy[i][k] == 0) { count++; }
		}
	}

	if (count > result) { result = count; }
}
void dfs(int start) {
	
	if (picked_loc.size() == 3) {
		calculate();
		return;
	}

	for (int i = start; i < blank.size(); i++) {
		picked_loc.push_back(i);
		dfs(i + 1);
		picked_loc.pop_back();
	}
}
int main() {
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M, 0));
	

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			int n; cin >> n;
			map[i][k] = n;
			if (n == 0) { blank.push_back({ i,k }); }
			if (n == 2) { virus.push_back({ i,k }); }
		}
	}


	dfs(0);

	cout << result;
}