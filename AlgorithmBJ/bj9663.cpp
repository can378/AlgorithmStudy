#include<iostream>
#include <vector>
using namespace std;
int N;

vector<vector<int>>map;
int result = 0;

int canPlace(int row, int col) {
	// 같은 열 체크
	for (int r = 0; r < row; r++) {
		if (map[r][col] == 1) return 0;
	}

	// 왼쪽 위 대각선 (↖)
	for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
		if (map[r][c] == 1) return 0;
	}

	// 오른쪽 위 대각선 (↗)
	for (int r = row - 1, c = col + 1; r >= 0 && c < N; r--, c++) {
		if (map[r][c] == 1) return 0;
	}

	return 1;
}

void dfs(int row) {

	if (row == N) { result++; return; }

	//col
	for (int i = 0; i < N; i++) {
		
		if (canPlace(row, i) == 0) continue;

		map[row][i] = 1;
		dfs(row + 1);
		map[row][i] = 0;
	}
}
int main() {
	
	cin >> N;
	map=vector<vector<int>>(N, vector<int>(N));

	dfs(0);

	cout << result;

}