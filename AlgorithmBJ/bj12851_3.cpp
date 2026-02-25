#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, K;
int MAX = 1000000000;



int main() {
	//INPUT
	cin >> N >> K;
	if (N== K) { cout << "0\n1"; return 0; }
	vector<int>way_count(100001,0); //n초 걸리는 경우의 시간
	vector<int> dist(100001,MAX);//n까지 가는 최소 시간.

	//CHECK
	queue<pair<int,int>>q;
	q.push({N,0});
	dist[N] = 0;
	way_count[N] = 1;

	while (!q.empty()) {

		int now_loc = q.front().first;
		int now_dist = q.front().second;
		q.pop();


		for (int next : {now_loc + 1, now_loc - 1, 2 * now_loc}) {
			if (next < 0 || next>100000)continue;

			//더 짧은거리 발견
			if (dist[next] > now_dist + 1) {
				dist[next] = now_dist + 1;
				q.push({ next,now_dist + 1 });
				way_count[next] = way_count[now_loc];
			}
			//같은 최단거리로 또 도착
			else if (dist[next] == dist[now_loc] + 1) {
				way_count[next] += way_count[now_loc];
			}
		}
	}

	//RESULT
	cout << dist[K] << "\n" << way_count[K];
}