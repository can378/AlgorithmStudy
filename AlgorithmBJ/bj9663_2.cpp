#include <iostream>
#include<vector>
using namespace std;

int N;
long long result = 0;
vector<int> colUsed, diag1, diag2;

void dfs(int row) {
    if (row == N) { result++; return; }

    for (int col = 0; col < N; col++) {
        int d1 = row - col + (N - 1);
        int d2 = row + col;
        if (colUsed[col] || diag1[d1] || diag2[d2]) continue;

        colUsed[col] = diag1[d1] = diag2[d2] = 1;
        dfs(row + 1);
        colUsed[col] = diag1[d1] = diag2[d2] = 0;
    }
}

int main() {
    cin >> N;
    colUsed.assign(N, 0);
    diag1.assign(2 * N - 1, 0);
    diag2.assign(2 * N - 1, 0);

    dfs(0);
    cout << result;
}
