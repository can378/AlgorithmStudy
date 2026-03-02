#include <iostream>
#include <vector>

using namespace std;
vector<int>numbers;

void dfs(int start, int end) {
	if (start > end || end>=numbers.size() || start>=numbers.size()) return;
	int root = numbers[start];
	int idx = start+1;

	while (idx < numbers.size()) {
		if (numbers[idx] > root)break;
		idx++;
	}

	dfs(start+1, idx - 1);
	dfs(idx, end);
	cout << root<<"\n";
}
int main() {
	int n;
	while(cin >> n){
		numbers.push_back(n);
	}
	dfs(0, numbers.size() - 1);
}