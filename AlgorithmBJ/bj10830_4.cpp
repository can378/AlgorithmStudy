#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> v;
vector<vector<int>>m;
int N, B;


v mul(v a, v b) {
	v result(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N; j++) {
				result[i][k]+= a[i][j] * b[j][k];
				
				result[i][k] %= 1000;
				cout << result[i][k] << ", ";
			}
		}
	}
	return result;
}
int main() {
	cin >> N >> B;
	m = v (N, vector<int>(N,0));
	v answer(N, vector<int>(N,0));

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k ++ ) {
			cin >> m[i][k];
			m[i][k] %= 1000;
		}
	}

	while (B > 0) {
		if (B % 2 == 1) { answer = mul(answer, m); }
		m = mul(m, m);
		B = B / 2;
	}

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cout << answer[i][k] << " ";
		}
		cout << "\n";
	}
}