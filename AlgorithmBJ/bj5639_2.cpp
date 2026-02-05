#include <iostream>
#include <vector>

using namespace std;
vector<int>graph;


void dfs(int start, int end) {

	if (start > end) { return; }

	int root = graph[start];
	int idx = start + 1;

	while (idx <= end && graph[idx] < root) { idx++; }

	dfs(start+1, idx-1);
	dfs(idx, end);
	cout << root << "\n";
}
int main() {
	
	int n;
	while (cin >> n) {
		graph.push_back(n);
	}
	
	dfs(0,graph.size()-1);

	return 0;
}