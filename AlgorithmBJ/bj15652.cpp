#include <iostream>
#include <vector>
using namespace std;
int N, M;

bool dfs(int start, vector<int>& arr)
{
    if (arr.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return true;
    }
    int num = start;
    while (num <= N)
    {
        arr.push_back(num);
        if (dfs(num, arr)) { num++; }
        arr.pop_back();
    }
    return true;
}
int main() {
    cin >> N >> M;
    vector<int>arr;
    dfs(1, arr);

    return 0;
}