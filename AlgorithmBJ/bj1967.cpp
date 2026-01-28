#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>>graph;

int farNode = 0;
int maxDist = 0;
int n;

//나랑 제일 먼 길이 찾기
void bfs(int node) {

	maxDist = 0;
	farNode = 0;

	vector<int>visited(n + 1);
	queue<p>q;
	q.push({ node,0 });
	visited[node] = 1;

	while (!q.empty()) {

		p now = q.front();
		int nowNode = now.first;
		int nowW = now.second;
		q.pop();

		if (nowW > maxDist) {
			maxDist = nowW;
			farNode = nowNode;
		}

		for (int i = 0; i < graph[nowNode].size(); i++) {
			int nextNode = graph[nowNode][i].first;
			int nextW = graph[nowNode][i].second;

			if (visited[nextNode]) { continue; }
			visited[nextNode] = 1;
			q.push({ nextNode,nowW + nextW });

		}
	}

}


int main() {
	cin >> n;

	graph = vector<vector<p>>(n + 1);

	for (int i = 1; i < n; i++) {
		int parent, child, w;
		cin >> parent >> child >> w;
		graph[parent].push_back({ child,w });
		graph[child].push_back({ parent,w });
	}

	bfs(1);
	bfs(farNode);

	cout << maxDist;

}