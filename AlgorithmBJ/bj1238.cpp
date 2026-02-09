#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, X;
typedef pair<int, int>p;
int MAX = 1000000000;
vector<vector<p>>graph;
vector<vector<p>>graph_re;

vector<int> dijkstra(const vector<vector<p>>&g, int start) {
	vector<int>dist(N+1, MAX);

	priority_queue <p, vector<p>, greater<p>>pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();

		int now_n = now.second;
		int now_l = now.first;

		if (dist[now_n] < now_l) continue;

		for (int i = 0; i < g[now_n].size(); i++) {
			p next = g[now_n][i];
			int next_n = next.second;
			int next_l = next.first;

			if (dist[next_n] <= next_l + now_l)continue;
			dist[next_n] = next_l + now_l;
			pq.push({ next_l + now_l,next_n });

		}
	}

	return dist;
}
int main() {
	
	//INPUT
	cin >> N >> M >> X;

	graph = vector<vector<p>>(N + 1);
	graph_re= vector<vector<p>>(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph_re[b].push_back({ c,a });
	}

	//CHECK
	vector<int>d1 = dijkstra(graph, X);
	vector<int>d2 = dijkstra(graph_re, X);

	//RESULT
	int result = 0;
	for (int i = 1; i <= N; i++) {
		int n = d1[i] + d2[i];
		if (result < n) { result = n; }
	}
	cout << result;
}