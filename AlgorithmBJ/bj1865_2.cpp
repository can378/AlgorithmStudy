#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int>p;
vector<vector<p>>graph;
int n, load, wormhole;
int MAX = 1000000000;

string bellman() {

	vector<int>dist(n + 1,0);
	for (int iter = 1; iter <= n; iter++) {
		bool is_update = false;
		for (int u = 1; u <= n; u++) {
			for (auto p : graph[u]) {
				int w = p.first, v = p.second;
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					is_update = true;
				}
			}
		}
		if (!is_update) break;
	}

	for (int u = 1; u <= n; u++) {
		for (auto p : graph[u]) {
			int w = p.first, v = p.second;
			if (dist[v] > dist[u] + w) return "YES";
		}
	}
	return "NO";
}

void task() {
	cin >> n >> load >> wormhole;

	graph.assign(n + 1, {});
	int s, e, t;
	for (int i = 0; i < load; i++) {
		cin >> s >> e >> t;
		graph[s].push_back({ t,e });
		graph[e].push_back({ t,s });
	}

	for (int i = 0; i < wormhole; i++) {
		cin >> s >> e >> t;
		graph[s].push_back({ -t,e });
	}


	cout<<bellman()<<"\n";
}

int main() {
	int task_case;
	cin >> task_case;
	for (int i = 0; i < task_case; i++) { task(); }
}