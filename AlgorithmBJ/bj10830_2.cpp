#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll ans[5][5];
ll n[5][5];
ll N, B;

void calculate(ll n1[5][5], ll n2[5][5]) {

	ll tmp[5][5];
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			tmp[i][k] = 0;
			for (int j = 0; j < N; j++) {
				tmp[i][k] += (n1[i][j] * n2[j][k]);
			}
			tmp[i][k] %= 1000;
		}
	}

	//UPDATE
	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
			n1[i][k] = tmp[i][k];
}
int main() {
	//INPUT
	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cin >> n[i][k];
		}
		ans[i][i] = 1;
	}

	while (B > 0) {
		if (B % 2 == 1) {
			calculate(ans, n);
		}
		calculate(n, n);
		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cout << ans[i][k] << " ";
		}
		cout << "\n";
	}

}