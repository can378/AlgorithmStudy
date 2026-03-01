#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int>p;
int V;
int MAX = 1000000000;
vector<vector<p>>graph;

p daik(int start) {
	vector<int>dist(V + 1, MAX);
	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push({ 0,start });
	dist[start] = 0;
	dist[0] = 0;

	while (!pq.empty()) {
		p now = pq.top();
		int now_n = now.second;
		int now_d = now.first;
		pq.pop();

		for (int i = 0; i < graph[now_n].size(); i++) {
			int next_n = graph[now_n][i].second;
			int next_d = graph[now_n][i].first;

			if (dist[next_n] <= now_d + next_d)continue;

			dist[next_n] = now_d + next_d;
			pq.push({ now_d + next_d,next_n });
		}
	}

	int far_dist=0;
	int far_node=0;
	for(int i=1;i<=V;i++){
		//cout<< dist[i]<<" ";
		if (far_dist < dist[i]) { 
			far_dist = dist[i];
			far_node = i;
		}
	}
	//cout << "\n";
	return{ far_node,far_dist };
}

int main() {
	cin >> V;
	graph=vector<vector<p>>(V+1);

	int to,from,dist;
	for (int i = 0; i < V; i++) {
		cin >> from;

		while (true) {
			cin >> to;
			if (to == -1)break;

			cin >> dist;
			graph[from].push_back({ dist,to });
			graph[to].push_back({ dist,from });
		}
	}

	p far = daik(1);
	//cout << "far node=" << far.first << " far dist=" << far.second << "\n";
	p far2 = daik(far.first);
	//cout << "far node=" << far2.first << " far dist=" << far2.second << "\n";
	cout << far2.second;

}