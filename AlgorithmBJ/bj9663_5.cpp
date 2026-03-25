#include <iostream>
#include <vector>
using namespace std;
int N;

vector<int> diagonal1;
vector<int> diagonal2;
vector<int> row;
vector<int> column;

vector<int>pick;

void dfs(int row) {

	if (row == N) {
		return;
	}

	for (int col = 0; col <= N; col++) {
		pick.push_back(col);
		dfs(row+1);
		pick.pop_back();
	}
}
int main() {
	cin >> N;

	diagonal1 = vector<int>(2 * N + 1);
	diagonal2 = vector<int>(2 * N + 1);
	row = vector<int>(N + 1);
	column = vector<int>(N + 1);
	
	dfs(1);
}