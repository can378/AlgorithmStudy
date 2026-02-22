#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int>nums;
vector<int>result;

void dfs(int start,int idx) {

	if (idx == M) {
		for (int n : result) { cout << n<<" "; }
		cout << "\n";
		return;
	}

	int pre = 0;
	for (int i = start; i < N; i++) {
		if (nums[i] == pre)continue;
		result[idx] = nums[i];
		pre = nums[i];
		dfs(i , idx + 1);
	}
}
int main() {
	cin >> N >> M;
	nums = vector<int>(N,0);
	result = vector<int>(M,0);
	for (int i = 0; i < N; i++) { cin >> nums[i]; }
	sort(nums.begin(), nums.end());

	dfs(0, 0);
}