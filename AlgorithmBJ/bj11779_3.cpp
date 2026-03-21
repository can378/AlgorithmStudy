#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
vector<vector<p>> graph;
int city, bus;
int MAX = 1000000000;

int main() {
	
	cin >> city >> bus;
	
	graph = vector<vector<p>>(city + 1);
	vector<int>pre_pos(city+1,0);
	vector<int>dist(city + 1, MAX);

	int f, t, w;
	for (int i = 0; i < bus; i++) {
		cin >> f >> t >> w;
		graph[f].push_back({ w,t });
	}

	int from, to;
	cin >> from >> to;


	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push({ 0,from });
	dist[from] = 0;
	pre_pos[from] = 0;

	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();

		int now_loc = now.second;
		int now_dist = now.first;

		if (dist[now_loc] < now_dist) continue;

		for (int i = 0; i < graph[now_loc].size(); i++) {
			p next = graph[now_loc][i];
			int next_loc = next.second;
			int next_dist = next.first;

			if (dist[next_loc] <= now_dist + next_dist)continue;
			dist[next_loc] = now_dist + next_dist;
			pre_pos[next_loc] = now_loc;
			pq.push({ now_dist + next_dist,next_loc });
		}
	}

	int l = to;
	vector<int>paths;
	paths.push_back(l);
	
	while (true) 
	{
		l = pre_pos[l];
		if (l == 0)break;
		paths.push_back(l);
	}

	cout << dist[to] << "\n" << paths.size() << "\n";
	for (int i = paths.size()-1; i >= 0;i--) { cout << paths[i] << " "; }
}