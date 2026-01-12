#include <iostream>
#include<vector>
#include<queue>
#include <limits>

int maxInt = std::numeric_limits<int>::max();
using namespace std;

vector<int>dist(100000+1, maxInt);
deque<pair<int, int>> q;

void move(int nextLoc,int nextSec, bool isTeleport) {

	if (nextLoc < 0 or nextLoc>100000) { return; }
	if (dist[nextLoc] <= nextSec) { return; }

	if (isTeleport) { q.push_front({ nextLoc,nextSec }); }
	else { q.push_back({ nextLoc,nextSec }); }
	dist[nextLoc] = nextSec;
	return;
}
int main() {
	//INPUT
	int N, K;
	cin >> N >> K;
	q.push_front({ N, 0 });
	dist[N] = 0;

	//CHECK
	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop_front();
		int loc = now.first;
		int sec = now.second;

		int nextLoc = loc * 2;
		int nextSec=sec+0;
		move(nextLoc, nextSec, true);

		nextLoc = loc + 1;
		nextSec = sec + 1;
		move(nextLoc, nextSec, false);

		nextLoc = loc - 1;
		nextSec = sec + 1;
		move(nextLoc, nextSec, false);
	}

	//RESULT
	cout << dist[K];
}