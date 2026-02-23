#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int>p;
int area, search, load;
vector<vector<p>>graph;
vector<int>item_count;
int result = 0;
int MAX = 1000000000;

void daik(int start) {
	vector<int>dist(area + 1,MAX);

	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		p now = pq.top();
		pq.pop();
		int now_loc = now.second;
		int now_dist = now.first;
		/*cout << "next ";
		if (dist[now_loc] <= now_dist)continue;*/

		for (int i = 0; i < graph[now_loc].size(); i++) {
			p next = graph[now_loc][i];
			int next_loc = next.second;
			int next_dist = next.first;

			if (dist[next_loc] <= next_dist + now_dist)continue;
			dist[next_loc] = next_dist + now_dist;
			pq.push({ next_dist + now_dist,next_loc });
		}
	}

	int sum = 0;
	for (int i = 1; i <= area; i++) {
		if (dist[i] <= search) { sum += item_count[i-1]; }
	}

	if (result < sum) { result = sum; }
}
int main() {

	//INPUT
	cin >> area >> search >> load;
	item_count= vector<int>(area + 1);
	graph= vector<vector<p>>(area + 1);
	for (int i = 0; i < area; i++) { cin >> item_count[i]; }
	int a, b, l;
	for (int i = 0; i < load; i++) {
		cin >> a >> b >> l;
		graph[a].push_back({ l,b });
		graph[b].push_back({ l,a });
	}


	//CHECK
	for (int i = 1; i <= area; i++) {
		daik(i);
	}

	//RESULT
	cout << result;
}