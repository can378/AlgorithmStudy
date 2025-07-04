#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };


int main() {
	int N, M;
	cin >> N >> M;
	vector<string>campus(N, "");
	int result = 0;
	vector<vector<int>> visited(N, vector<int>(M, 0));

	int start_x, start_y;

	for (int i = 0; i < N; i++) {
		cin >> campus[i];
		for (int k = 0; k < M; k++) {
			if (campus[i][k] == 'I') {
				start_x = i; start_y = k;
			}
		}
	}

	queue<pair<int,int>>q;
	q.push({ start_x,start_y });

	while (!q.empty()) {

		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dir[i][0];
			int nextY = nowY + dir[i][1];

			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)continue;
			if (visited[nextX][nextY]==1)continue;
			if (campus[nextX][nextY] == 'X')continue;

			visited[nextX][nextY] = 1;
			q.push({ nextX,nextY });
			
			if (campus[nextX][nextY] == 'P') {
				result++;
			}
		}
	}

	if (result == 0) { cout<< "TT"; }
	else { cout<< result; }


}