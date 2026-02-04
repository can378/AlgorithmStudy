#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int MOD = 1000;

vector<vector<ll>> mul(const vector<vector<ll>>& A, const vector<vector<ll>>& B, int N) {
    vector<vector<ll>> C(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            ll a = A[i][k] % MOD;
            if (a == 0) continue;
            for (int j = 0; j < N; j++) {
                C[i][j] = (C[i][j] + a * (B[k][j] % MOD)) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> identity(int N) {
    vector<vector<ll>> I(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) I[i][i] = 1;
    return I;
}

int main() {
    int N;
    long long B;
    cin >> N >> B;

    vector<vector<ll>> A(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] %= MOD;
        }
    }

    vector<vector<ll>> res = identity(N);

    while (B > 0) {
        if (B & 1LL) res = mul(res, A, N);
        A = mul(A, A, N);
        B >>= 1LL;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (res[i][j] % MOD) << (j + 1 == N ? '\n' : ' ');
        }
    }
    return 0;
}
