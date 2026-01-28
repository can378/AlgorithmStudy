#include <iostream>
#include <vector>
#include<queue>
#include <climits>

const int MAX = INT_MAX;

using namespace std;


typedef pair<int, int> p;
int main() {
	int V, E;
	cin >> V >> E;
	int start;
	cin >> start;

	vector<vector<p>>graph(V+1);
	vector<int>dist_result(V + 1, MAX);

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ w,v });
	}

	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push({ 0,start });
	dist_result[start] = 0;

	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();

		int dist = now.first;
		int node = now.second;
		if (dist != dist_result[node]) continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int nextNode = graph[node][i].second;
			int nextDist = graph[node][i].first;

			if (dist_result[nextNode] < dist + nextDist) continue;
			dist_result[nextNode] = dist + nextDist;
			pq.push({ dist + nextDist, nextNode });
		}
	}

	for (int i = 1; i < dist_result.size(); i++) {
		if (dist_result[i] >= MAX) { cout << "INF\n"; }
		else { cout << dist_result[i] << "\n"; }
	}
	return 0;
}