#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> graph;
vector<vector<int>> result;

void checkPath(int from, int to) {
	
	if (to >= N||from>=N)return;
	for (int i = 0; i < N; i++) {
		if (graph[to][i] == 1 && result[from][i] == 0) {
			result[from][i] = 1;
			checkPath(from, i);
		}
	}
}
int main() {
	cin >> N;
	graph = vector<vector<int>>(N, vector<int>(N, 0));
	result=vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cin >> graph[i][k];
		}
	}

	for (int i = 0; i < N; i++) {
		checkPath(i, i);
	}
	

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cout << result[i][k]<<" ";
		}
		cout << "\n";
	}
}