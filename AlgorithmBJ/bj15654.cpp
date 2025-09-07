#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 9
int N, M;
int original[MAX];
int visited[MAX];

void dfs(vector<int>& arr) {

    if (arr.size() == M) {
        //RESULT
        for (int i = 0; i < M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        arr.push_back(original[i]);
        dfs(arr);
        arr.pop_back();
        visited[i] = 0;
    }
}

int main() {
    //INPUT
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> original[i];
    sort(original, original + N);
    vector<int> arr;

    //CHECK
    dfs(arr);
    return 0;
}
