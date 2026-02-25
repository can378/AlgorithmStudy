#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int>p;
int city, bus,from,to;
int MAX = 1000000000;

int main() {
	cin >> city >> bus;
	vector<vector<p>>graph(city+1);
	vector<int>dist(city + 1, MAX);
	vector<int>route(city + 1, 0);

	int a, b, w;
	for (int i = 0; i < bus; i++) {
		cin >> a >> b >> w;
		graph[a].push_back({ w,b });
	}
	cin >> from >> to;

	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push({ 0,from });
	dist[from] = 0;

	while (!pq.empty()) {

		p now = pq.top();
		pq.pop();

		int now_loc = now.second;
		int now_dist = now.first;

		if (dist[now_loc] < now_dist)continue;

		for (int i = 0; i < graph[now_loc].size(); i++) {
			int next_loc = graph[now_loc][i].second;
			int next_dist= graph[now_loc][i].first;

			if (dist[next_loc] <= next_dist + now_dist)continue;
			dist[next_loc] = next_dist + now_dist;
			route[next_loc] = now_loc;
			pq.push({ next_dist + now_dist,next_loc });
		}
	}

	vector<int>paths;

	int idx = to;
	while (true) {
		paths.push_back(idx);
		int pre = route[idx];
		idx = pre;
		if (idx == 0)break;
	}
	cout << dist[to] << "\n" << paths.size()<<"\n";
	for (int i= paths.size() - 1; i >= 0;i--) { cout << paths[i] << " "; }
	
	
}