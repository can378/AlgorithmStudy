#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, K;
typedef pair<int, int>p;

int MAX = 1000000000;
int main() {
	cin >> N >> K;

	vector<int>way_count(100001, 0);
	vector<int>dist(100001, MAX);
	queue<p>q;
	q.push({ 0,N });
	way_count[N] = 1;
	dist[N] = 0;


	while (!q.empty()) {
		p now = q.front();
		int now_loc = now.second;
		int now_dist = now.first;
		q.pop();
		
		for (auto next_loc : { now_loc + 1,now_loc - 1,now_loc * 2 }) {
			if (next_loc < 0 || next_loc >= 100001)continue;

			//더 짧은 거리를 찾았다
			if (dist[next_loc] > now_dist + 1) {
				dist[next_loc] = now_dist + 1;
				way_count[next_loc] = way_count[now_loc];
				q.push({ now_dist + 1,next_loc });
			}
			//이전과 같은 거리다
			else if (dist[next_loc] == now_dist + 1) {
				way_count[next_loc] += way_count[now_loc];
			}
		}
	}

	cout << dist[K]<<"\n" << way_count[K] << "\n";

}