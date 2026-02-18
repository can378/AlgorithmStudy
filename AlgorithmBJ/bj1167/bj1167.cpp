#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;
vector<vector<p>>graph;
int V;

struct result {
	int long_node, long_dist;
};

result check_dist(int start) {
	
	int long_dist = 0;
	int long_node = start;
	
	vector<int>visited(V+1, 0);
	visited[start] = 1;
	queue<p>q;
	q.push({ start,0 });

	while (!q.empty()) {
		p now = q.front();
		q.pop();
		int now_node = now.first;
		int now_dist = now.second;

		for (int i = 0; i < graph[now_node].size(); i++) {
			
			int next_node = graph[now_node][i].first;
			int next_dist = graph[now_node][i].second;
			
			if (visited[next_node] == 1)continue;
			visited[next_node] = 1;

			if (long_dist < now_dist + next_dist)
			{
				long_node = next_node;
				long_dist = now_dist + next_dist;
			}

			q.push({ next_node,now_dist + next_dist });
		}
	}

	return { long_node,long_dist };
}



int main() {

	//INPUT
	cin >> V;
	graph.resize(V + 1);

	int node,n,w;
	for (int i = 0; i < V; i++) {
		cin >> node;
		
		while (true) {
			cin >> n;
			if (n == -1)break;
			cin >> w;
			graph[node].push_back({ n,w });
		}
	}

	//CHECK
	result res = check_dist(1);
	result real_res = check_dist(res.long_node);

	//RESULT
	cout << real_res.long_dist;
}
