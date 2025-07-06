#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int main() {
	//INPUT
	int N; cin >> N;
	vector<string>map(N);
	vector<vector<int>>visited(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	int complex = 0;//단지 개수
	vector<int>result;//집 개수 저장할 vector

	//CHECK
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {

			if (map[i][k] == '0' || visited[i][k] == 1) {
				visited[i][k] = 1;
				continue;
			}

			queue<pair<int, int>>q;
			q.push({ i,k });
			visited[i][k] = 1;
			complex += 1;
			int houseCount = 1;

			while (!q.empty()) {
				int nowX = q.front().first;
				int nowY = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int nextX = nowX + dir[d][0];
					int nextY = nowY + dir[d][1];

					if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)continue;
					if (visited[nextX][nextY] == 1)continue;

					visited[nextX][nextY] = 1;
					if (map[nextX][nextY] == '1') {
						houseCount++;
						q.push({ nextX,nextY });
					}

				}
			}
			result.push_back(houseCount);
		}
	}

	//RESULT
	sort(result.begin(), result.end());
	cout << complex << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	
}