#include <iostream>
#include<vector>

using namespace std;
int N;
long long B;

vector<vector<int>>ans, m;
typedef long long ll;

vector<vector<int>> mul(vector<vector<int>>&a, vector<vector<int>>&b) {

	vector<vector<int>>result(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N; j++) {
				result[i][k] += a[i][j] * b[j][k];
			}
			result[i][k] %= 1000;
		}
	}
	return result;
}

int main() {
	cin >> N>>B;
	
	ans = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) ans[i][i] = 1;

	m = vector<vector<int>>(N, vector<int>(N));


	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cin >> m[i][k];
			m[i][k] %= 1000;
		}
	}


	while (B > 0) {
		
		if (B % 2 == 1) {ans=mul(ans, m);}
		m = mul(m, m);
		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cout << ans[i][k]<<" ";
		}
		cout << "\n";
	}

}