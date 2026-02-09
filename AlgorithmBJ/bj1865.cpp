#include <iostream>
#include <vector>

using namespace std;
struct node {
    int a, b;
    long long l;
};

vector<node>edges;
int N, M, W;


string bellman() {

    vector<int>dist(N + 1, 0);

    for (int i = 0; i < N; i++) {
        bool isUpdate = false;
        for (auto& e : edges)
        {
            if (dist[e.b] > dist[e.a] + e.l) {
                dist[e.b] = dist[e.a] + e.l;
                isUpdate = true;
            }
        }
        if (!isUpdate)break;
    }

    //음수 사이클확인
    for (auto& e : edges) {
        if (dist[e.b] > dist[e.a] + e.l) { return "YES"; }
    }
    return "NO";
}


void cases() {
    //INPUT
    cin >> N >> M >> W;
    int s, e, t;
    node n;
    edges.clear();
    //도로
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> t;
        n.a = s; n.b = e; n.l = t;
        edges.push_back(n);

        n.a = e; n.b = s; n.l = t;
        edges.push_back(n);
    }
    //웜홀
    for (int i = 0; i < W; i++) {
        cin >> s >> e >> t;
        n.a = s; n.b = e; n.l = -1 * t;
        edges.push_back(n);
    }

    //RESULT
    cout << bellman() << "\n";
}



int main() {
    int T; cin >> T;
    for (int i = 0; i < T; i++) { cases(); }
    return 0;
}