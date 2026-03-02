#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int>nums;
vector<int>result;

void dfs(int start, int idx) {

	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i]<<" ";
		}
		cout << "\n";
		return;
	}

	int last = 0;
	for (int i = start; i < N; i++) {
		if (last == nums[i])continue;
		last = nums[i];
		result[idx] = nums[i];
		dfs(i, idx + 1);
	}
}
int main() {
	cin >> N >> M;
	nums.resize(N);
	result.resize(M);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	dfs(0, 0);
}