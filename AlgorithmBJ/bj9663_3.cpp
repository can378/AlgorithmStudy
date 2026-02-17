#include <iostream>
#include <vector>

using namespace std;

vector<int> pick;
bool used[15];
int N;
int result = 0;

void dfs() {
    if (pick.size() == N) {
        
        return;
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;

        used[i] = true;
        pick.push_back(i);
        dfs();
        pick.pop_back();
        used[i] = false;
    }
}

int main() {
    cin >> N;
    dfs();
    cout << result;
}
