#include<iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int, int> p;
int N, E, v1, v2;
vector<vector<p>> graph;
const int INF = (int)1e9;
const long long INFLL = 4e18;

vector<int> dijkstra(int start) {

	vector<int> dist(N+1, INF);
	priority_queue<p, vector<p>, greater<p>>pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int nowNode = pq.top().second;
		int nowDist = pq.top().first;
		pq.pop();

		if (nowDist > dist[nowNode]) continue;

		for ( auto &node : graph[nowNode]) {
			int nextNode = node.second;
			int nextDist = node.first;

			if (dist[nowNode] + nextDist < dist[nextNode]) {
				dist[nextNode] = dist[nowNode] + nextDist;
				pq.push({ dist[nextNode],nextNode });
			}
		}
	}
	
	return dist;
}

int main() {
	
	cin >> N >> E;

	graph = vector<vector<p>>(N + 1);
	for (int i = 0; i < E; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;

		graph[a].push_back({ dist,b });
		graph[b].push_back({ dist,a });
	}

	cin >> v1 >> v2;

	vector<int>dist = dijkstra(1);
	vector<int>dist_v1 = dijkstra(v1);
	vector<int>dist_v2 = dijkstra(v2);

	long long n1 = dist[v1] + dist_v1[v2] + dist_v2[N];
	long long n2 = dist[v2] + dist_v2[v1] + dist_v1[N];

	if (dist[v1] >= INF || dist_v1[v2] >= INF || dist_v2[N] >= INF) n1 = INFLL;
	if (dist[v2] >= INF || dist_v2[v1] >= INF || dist_v1[N] >= INF) n2 = INFLL;

	long long result = min(n1, n2);
	if (result >= INFLL) result = -1;
	cout << result;

}