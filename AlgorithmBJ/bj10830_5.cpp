#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> v;
typedef long long ll;
v m;
ll N, B;

v mul(v a,v b) {
	v result= vector<vector<int>>(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N; j++) {
				result[i][k] += a[i][j] * b[j][k];
				result[i][k] %= 1000;
			}
		}
	}
	return result;
}
int main() {
	cin >> N >> B;
	m = vector<vector<int>>(N, vector<int>(N, 0));
	v ans = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cin >> m[i][k];
			m[i][k] %= 1000;
		}
		ans[i][i] = 1;
	}

	while (B > 0) {
		if (B % 2 == 1) {
			ans = mul(ans, m);
		}
		B = B/2;
		m = mul(m, m);
	}

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cout << ans[i][k]%1000 << " ";
		}
		cout << "\n";
	}
}