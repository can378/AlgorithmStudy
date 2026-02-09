#include <iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int>p;
vector<vector<p>>graph;
vector<int>items;
int areas, search, loads;
int MAX = 1000000000;

int daik(int start) {
	//dijkstra
	//cout << "start\n";
	vector<int>dist(areas + 1, MAX);
	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty())
	{
		p now = pq.top();
		pq.pop();

		int now_n = now.second;
		int now_l = now.first;
		//cout <<"now=" << now_n << "\n";

		for (int i = 0; i < graph[now_n].size(); i++) {
			p next = graph[now_n][i];
			int next_n = next.second;
			int next_l = next.first;

			if (dist[next_n] <= now_l + next_l) continue;
			dist[next_n] = now_l + next_l;
			pq.push({ now_l + next_l,next_n });
		}
	}

	int sum = 0;
	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] <= search) { sum += items[i-1]; }
		//cout << dist[i] << " ";
	}
	return sum;
}

int main() {
	cin >> areas >> search >> loads;
	for (int i = 0; i < areas; i++) {
		int n; cin >> n; items.push_back(n);
	}

	graph = vector<vector<p>>(areas + 1, vector<p>(areas+1));
	for (int i = 0; i < loads; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a].push_back({ l,b });
		graph[b].push_back({ l,a });
	}
	int result = 0;
	for (int i = 1; i <= areas; i++) {
		int s=daik(i);
		if (s > result) { result = s; }
	}
	cout << result;
}