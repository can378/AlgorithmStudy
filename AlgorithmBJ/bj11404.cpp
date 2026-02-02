#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int city_count,bus_count;
typedef long long ll;
ll LMAX = 10000000000000;
vector<vector<ll>>graph;

int main() {
	//INPUT
	cin >> city_count >>bus_count;
	graph = vector<vector<ll>>(city_count+1, vector<ll>(city_count+1,LMAX));
	for (int i = 0; i <= city_count; i++) { graph[i][i] = 0; }
	for (int i = 0; i < bus_count; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if(graph[from][to]>cost) graph[from][to] = cost;
	}

	// 플로이드 와샬
	for (int i = 1; i <= city_count; i++) {
		for (int k = 1; k <= city_count; k++) {
			for (int j = 1; j <= city_count; j++) {
				graph[k][j] = min(graph[k][j],graph[k][i]+graph[i][j]);
			}
		}
	}

	//RESULT
	for (int i = 1; i <= city_count; i++) {
		for (int k = 1; k <= city_count; k++) {
			if (graph[i][k] >= LMAX) cout << 0 << " ";
			else cout<< graph[i][k]<<" ";
		}
		cout << "\n";
	}
}