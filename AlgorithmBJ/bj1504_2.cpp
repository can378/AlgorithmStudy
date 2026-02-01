#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<long long, int> p;
vector<vector<p>>graph;

long long LMAX = 10000000000;
int N, E;

vector<long long> daikstra(int start) {
	vector<long long>result(N+1,LMAX);

	priority_queue<p, vector<p>, greater<p>>pq;
	result[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();

		int node = now.second;
		int weight = now.first;

		if (result[node] < weight) continue;

		for (int i = 0; i < graph[node].size(); i++) {
			p next = graph[node][i];
			int next_node = next.second;
			int next_w = next.first;

			if (result[next_node] < weight + next_w) continue;
			result[next_node] = weight + next_w;

			pq.push({ weight+next_w,next_node });
		}
	}
	return result;
}

int main() {
	
	cin >> N >> E;

	graph = vector<vector<p>>(N+1);
	for (int i = 0; i < E; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back({ w,b });
		graph[b].push_back({ w,a });
	}

	int v1, v2;
	cin >> v1 >> v2;
	vector<long long>dist=daikstra(1);
	vector<long long>dist_v1 = daikstra(v1);
	vector<long long>dist_v2 = daikstra(v2);

	long long d1 = dist[v1] + dist_v1[v2]+dist_v2[N];
	long long d2 = dist[v2] + dist_v2[v1]+dist_v1[N];

	long long result = 0;
	if (d1 > d2) { result = d2; }
	else { result = d1; }

	if (result >= LMAX) { result = -1; }
	cout << result;
}