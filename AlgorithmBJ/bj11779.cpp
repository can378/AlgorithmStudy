#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int>p;
int from, to;
int city, bus;
vector<vector<p>>graph;
vector<int>path;
int MAX=1000000000;


void daik(int start) {
	path.resize(city + 1); //path[n]=도시 n까지의 최소거리일때 거치는 직전 도시
	vector<int>dist(city + 1, MAX);

	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push({ 0,start });
	dist[start] = 0;
	
	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();
		int now_city = now.second;
		int now_dist = now.first;

		if (dist[now_city] != now_dist)continue;

		for (int i = 0; i < graph[now_city].size(); i++) {
			p next = graph[now_city][i];
			int next_city = next.second;
			int next_dist = next.first;

			if (dist[next_city] <= next_dist + now_dist)continue;

			dist[next_city] = next_dist + now_dist;
			pq.push({ next_dist + now_dist,next_city });
			path[next_city] = now_city;
		}
	}


	//RESULT
	cout << dist[to]<<"\n";

	vector<int>route = { to };
	int n = to;
	while (path[n]) {
		route.push_back(path[n]);
		n = path[n];
	}

	cout << route.size() << "\n";
	for (int r=route.size()-1; r >=0;r--) { cout << route[r] << " "; }

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//INPUT
	cin >> city >> bus;
	graph.resize(city + 1);
	int a, b, w;
	for (int i = 0; i < bus; i++) {
		cin >> a >> b >> w;
		graph[a].push_back({ w,b });
	}

	cin >> from >> to;

	//START
	daik(from);
}