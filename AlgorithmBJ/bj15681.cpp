#include <iostream>
#include <vector>
using namespace std;
int N, Root, Query;

vector<vector<int>>graph;
vector<int>visited;
vector<int>result;

void dfs(int n) {
	result[n] = 1;

	for (int i = 0; i < graph[n].size(); i++) {
		int next_n = graph[n][i];
		if (visited[next_n] == 1)continue;
		visited[next_n] = 1;
		dfs(next_n);
		result[n] += result[next_n];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> Root >> Query;

	graph = vector<vector<int>>(N + 1);
	visited = vector<int>(N + 1, 0);
	result = vector<int>(N + 1, 0);

	int n1, n2;
	for (int i = 0; i < N-1; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	visited[Root] = 1;
	dfs(Root);


	int q;
	for (int i = 0; i < Query; i++) {
		cin >> q;
		cout <<result[q] << "\n";
	}
}