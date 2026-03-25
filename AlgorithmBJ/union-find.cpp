#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) { parent[b] = a; }
}

int main() {
    int n, m; // 그래프 노드수, 간선수
    cin >> n >> m;

    parent.resize(n + 1);

    // 초반에는 본인이 본인의 root이다.
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (find(a) == find(b)) { cout << "사이클 발생\n"; }
        else { unionSet(a, b); }
    }
}