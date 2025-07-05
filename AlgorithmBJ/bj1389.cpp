#include <iostream>
#include <vector>
#define INF 2147483647
using namespace std;

int main() {
	//INPUT
	int N, M;
	cin >> N >> M;
	vector<vector<int>>graph(N+1,vector<int>(N+1,INF));
	for (int i = 1; i <= N; i++) {
		graph[i][i] = 0; // 자기 자신은 0
	}
	int p1, p2;
	for (int i = 0; i < M; i++) {
		cin >> p1 >> p2;
		graph[p1][p2] = 1;
		graph[p2][p1] = 1;
	}

	//CHECK - Floyd Warshall Algorithm
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] == INF || graph[k][j] == INF) continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	cout << "graph=\n";
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			cout << graph[i][k]<<" ";
		}
		cout << "\n";
	}

	//CHECK - min
	int min = INF;
	int result = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int k = 1; k <= N; k++) {
			sum += graph[i][k];
		}
		if (sum < min) { min = sum; result = i; }
	}

	//RESULT
	cout << result;
}