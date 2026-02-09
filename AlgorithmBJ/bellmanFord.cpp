#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

const long long INF = 4e18;

int N, M; // 정점 수, 간선 수
vector<Edge> edges;
vector<long long> dist;

bool bellman_ford(int start) {
    dist=vector<long long>(N + 1, INF);
    dist[start] = 0;

    // 1) 거리계산
    for (int i = 1; i <= N - 1; i++) {
        bool updated = false;
        for (auto& e : edges) {
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    // 2) 음수 사이클 체크
    for (auto& e : edges) {
        if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
            return true;
        }
    }
    return false;
}

int main() {
    //INPUT
    cin >> N >> M;
    edges=vector<Edge>(M);

    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    //CHECK
    bool hasNegCycle = bellman_ford(1);

    //RESULT
    if (hasNegCycle) {
        cout << "negative cycle..\n";
    }
    else {
        for (int i = 1; i <= N; i++) {
            if (dist[i] == INF) cout << "INF\n";
            else cout << dist[i] << "\n";
        }
    }
}
