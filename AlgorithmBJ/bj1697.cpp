#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>visited(200000, 0);
queue<pair<int, int>>q;//현재 위치, 이동 횟수

void visit(int loc, int nowCount) {
	if (loc < 0 || loc>=200000) return;

	if (visited[loc] == 0) {
		q.push({ loc,nowCount +1 });
		visited[loc] = 1;
	}
}
int main() {
	//INPUT
	int Me, Sister;
	cin >> Me >> Sister;
	
	//CHECK
	q.push({ Me,0 });
	visited[Me] = 1;

	while (!q.empty()) {
		//check now info
		int nowLoc = q.front().first;
		int nowCount = q.front().second;
		q.pop();

		if (nowLoc == Sister) {
			cout << nowCount;
			return 0;
		}

		visit(nowLoc + 1, nowCount);
		visit(nowLoc - 1, nowCount);
		visit(nowLoc * 2, nowCount);	
	}

	return 0;
}