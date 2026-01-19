#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> know_truth(51,0);
vector<int> visited(51, 0);
vector<set<int>>graph;
vector<vector<int>> party;

int N, M;
int truth_num;
int result = 0;

void dfs(int cur) {
	visited[cur] = 1;
	for (int nxt : graph[cur]) {
		if (!visited[nxt]) dfs(nxt);
	}
}
int main() {
	//INPUT
	//사람수, 파티수
	cin >> N >> M;
	cin >> truth_num;
	graph.resize(N + 1);
	party.resize(M);

	for (int i = 0; i < truth_num; i++) { 
		int num; cin >> num; 
		know_truth[num]=1;
	}


	int p_count;
	for (int i = 0; i < M; i++) {
		cin >> p_count;//사람수

		// party에 몇명, 누가 있는지 입력
		party[i].resize(p_count);
		for (int k = 0; k < p_count; k++) {
			cin >> party[i][k];
		}

		//graph 생성
		for (int k = 0; k < p_count;k++) {
			for (int j = k+1; j < p_count; j++) {
				graph[party[i][k]].insert(party[i][j]);
				graph[party[i][j]].insert(party[i][k]);
			}
		}
	}

	//CHECK
	// 진실 전파: 진실 아는 사람들에서 DFS 시작
	for (int i = 1; i <= N; i++) {
		if (know_truth[i] && !visited[i]) dfs(i);
	}

	// 결과 계산: 파티에 진실 전파된 사람이 한 명이라도 있으면 거짓말 불가
	result = 0;
	for (int i = 0; i < M; i++) {
		bool hasTruth = false;
		for (int person : party[i]) {
			if (visited[person]) { hasTruth = true; break; }
		}
		if (!hasTruth) result++;
	}

	//RESULT
	cout << result;
}