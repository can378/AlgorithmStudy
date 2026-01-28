#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int knowTruthCount;
	cin >> knowTruthCount;

	vector<int> knowTruth(N + 1, 0);

	for (int i = 0; i < knowTruthCount; i++)
	{
		int n; cin >> n;
		knowTruth[n] = 1;
	}

	vector<vector<int>> parties(M);
	vector<vector<int>>graph(N + 1);
	for (int i = 0; i < M; i++) {
		int c; cin >> c;
		for (int k = 0; k < c; k++) {
			int p; cin >> p;
			parties[i].push_back(p);
		}

		for (int k = 0; k < c; k++)
		{
			int me = parties[i][k];
			for (int j = k+1; j < c; j++) {
				int you = parties[i][j];
				graph[me].push_back(you);
				graph[you].push_back(me);
			}
		}

	}

	//calculate

	queue <int> q;
	vector<int>visited(N + 1);

	for (int i = 1; i <= N; i++) {
		if (knowTruth[i] == 1) { q.push(i); visited[i] = 1; }
	}

	

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			if (visited[next] == 1)continue;

			knowTruth[next] = 1;
			visited[next] = 1;
			q.push(next);
		}

	}

	int result = 0;

	for (int i = 0; i < parties.size(); i++) {
		bool lie = true;

		for (int k = 0; k < parties[i].size(); k++) {

			if (knowTruth[parties[i][k]]) { lie = false; break; }
		}
		if (lie==true) { result++; }
	}
	cout << result;
}