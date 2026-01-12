#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> result;
vector<int> nums;

void dfs(int start, int loc) {

	if (loc == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i]<<" ";
		}
		cout << "\n";
		return;
	}

	int last = 0;
	for (int i= start; i < N; i++) {
		if (last != nums[i]) {
			result[loc] = nums[i];
			last = nums[i];
			dfs(i, loc + 1);
		}
	}
}

int main() {
	//INPUT
	cin >> N >> M;
	result = vector<int>(M);
	nums = vector<int>(N);
	for (int i = 0; i < N; i++) { cin >> nums[i]; }

	//SORT
	sort(nums.begin(), nums.end());

	//START
	dfs(0, 0);
}