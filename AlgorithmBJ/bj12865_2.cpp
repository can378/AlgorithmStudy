#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int>dp(K+1,0);

	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;

		for (int cur = K; cur >= w; cur--) {
			dp[cur] = max(dp[cur], dp[cur-w]+v);
		}
	}

	cout << dp[K];
}