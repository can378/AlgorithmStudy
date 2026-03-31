#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 간선 정보 (정점 u, v, 가중치 w)
struct Edge { int u, v, w; };

// 가중치 기준 오름차순 정렬
bool cmp(Edge a, Edge b) { return a.w < b.w; }

vector<int> parent;

// find: 루트 노드 찾기 (경로 압축)
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// union: 두 집합 합치기 (사이클 체크)
bool unionSet(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false; // 이미 같은 집합 → 사이클 발생
    parent[b] = a;            // 서로 다른 집합 → 합치기
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    // 입력
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 각 정점 root를 자기 자신으로 초기화
    parent.resize(V + 1);
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    // 간선을 가중치 기준으로 오름차순 정렬
    sort(edges.begin(), edges.end(), cmp);

    int mst_cost = 0;

    // 작은 간선부터 하나씩 확인
    for (auto e : edges) {
        // 사이클이 생기지 않는 경우만 선택
        if (unionSet(e.u, e.v)) {
            mst_cost += e.w;
        }
    }

    cout << mst_cost;
}