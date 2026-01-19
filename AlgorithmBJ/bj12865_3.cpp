#include <iostream>
#include<vector>
#include <math.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int>dp(K + 1);

	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;

		for (int j = K; j >=w; j--) {
			dp[j] = max(dp[j], dp[j-w]+v);
		}
	}

	cout << dp[K];
}