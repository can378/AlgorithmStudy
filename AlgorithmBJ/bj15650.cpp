#include <iostream>
#include <vector>
using namespace std;
int N, M;

void dfs(int start, vector<int> arr)
{
    if (arr.size() == M) 
    {
        for (int i = 0; i < M; i++) 
        { cout << arr[i] << " "; }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) 
    {
        arr.push_back(i);
        dfs(i + 1, arr);
        arr.pop_back();
    }
}
int main() 
{
    cin >> N >> M;
    vector<int>arr;
    dfs(1, arr);

    return 0;
}