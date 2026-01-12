#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int>result;
vector<int>numbers;
int N, M;

void dfs(int now,int start) {

	if (result.size() == M) {
		for (int i = 0; i < M; i++) { cout << result[i]; }
		cout << "\n";
	}

	int pre = -1;

	for (int i = start; i < N; i++) {
		if (pre != numbers[i]) {
			result[now] = numbers[i];
			pre = numbers[i];
			dfs(now + 1,i);
		}
	}
}
int main() {
	cin >> N >> M;
	numbers = vector<int>(N, 0);
	for (int i = 0; i<N; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());

	dfs(0, 0);
 }