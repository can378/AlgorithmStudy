#include<iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100000;
const int INF = 1e9;


int main() {
	//INPUT
	int young, old;
	cin >> old >> young;

	vector<int> dist(MAX + 1, INF); //dist[n]=n위치에 가는 가장 빠른 시간
	vector<int> ways(MAX + 1, 0); //ways[n]=n 위치에 최단 시간으로 도달하는 방법의 수
	
	//CHECK
	if (old == young) { cout << "0\n1"; return 0; }

	queue<int>q;
	q.push(old);
	dist[old] = 0;
	ways[old] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : {now - 1, now + 1, now * 2}) {
			if (next<0 || next>MAX)continue;
			if (dist[next] > dist[now] + 1) {
				//최소 시간 갱신
				dist[next] = dist[now] + 1;
				ways[next] = ways[now];
				q.push(next);
			}
			else if (dist[next] == dist[now] + 1) {
				ways[next] += ways[now];
			}
		}

	}

	//RESULT
	cout << dist[young] << "\n" << ways[young];
}