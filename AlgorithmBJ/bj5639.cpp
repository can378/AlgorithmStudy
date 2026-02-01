#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;

void dfs(int start, int end) {
    if (start > end) return;

    int root = preorder[start];
    int idx = start + 1;

    // 오른쪽 서브트리 시작 위치 찾기
    while (idx <= end && preorder[idx] < root) {
        idx++;
    }

    // 왼쪽 서브트리
    dfs(start + 1, idx - 1);
    // 오른쪽 서브트리
    dfs(idx, end);
    // 후위 순회 출력
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x) {
        preorder.push_back(x);
    }

    dfs(0, preorder.size() - 1);
    return 0;
}
