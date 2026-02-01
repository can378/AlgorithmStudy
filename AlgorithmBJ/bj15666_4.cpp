#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
vector<int>num;
vector<int>result;
int N, M;
void dfs(int start, int idx) {

	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	int pre = 0;

	for (int i = start; i < N; i++) {

		if (num[i] == pre)continue;

		result[idx]=num[i];
		pre = num[i];
		dfs(i, idx + 1);
		
	}
}

int main() {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		num.push_back(n);
	}

	result = vector<int>(M);
	sort(num.begin(), num.end());
	
	dfs(0, 0);
}