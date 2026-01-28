#include <iostream>
#include<set>
#include<vector>
using namespace std;

vector<int> knowTruth;
vector<set<int>>graph;
vector<vector<int>>parties;
vector<int>visited(51);

void dfs(int now) {

	if (knowTruth[now] == 0) return;
	if (visited[now]) return;
	visited[now] = 1;

	
	for (int next : graph[now]) {

		knowTruth[next] = 1;
		dfs(next);
	}

}
int main() {
	int people_count, party_count;
	cin >> people_count >> party_count;
	int knowTruthCount;
	cin >> knowTruthCount;

	knowTruth=vector<int>(people_count+1,0);
	int n;
	for (int i = 0; i < knowTruthCount; i++) {
		cin >> n;
		knowTruth[n] = 1;
	}

	graph= vector<set<int>>(people_count+1);

	for (int i = 0; i < party_count; i++) {
		int p_count;
		cin >> p_count;

		vector<int>party(p_count);
		for (int k = 0; k < p_count; k++) {
			cin >> party[k];
		}

		//graph
		for (int k = 0; k < p_count; k++) {
			for (int j = k+1; j < p_count; j++) {
				graph[party[k]].insert(party[j]);
				graph[party[j]].insert(party[k]);
			}
		}
		parties.push_back(party);
	}

	//check
	//cout << "\n\n";
	//for (int i = 1; i < graph.size(); i++) {
	//	cout << i << " = ";
	//	for (int n : graph[i]) {
	//		cout << " " << n;
	//	}
	//	cout << "\n";
	//}
	
	//check who knows truth
	
	for (int i = 1; i < people_count + 1; i++) 
	{ dfs(i); }
	

	int result = 0;
	for (int i = 0; i < parties.size(); i++) {
		bool canLie = true;
		for (int p:parties[i]) {
			if (knowTruth[p]) { canLie = false; break; }
		}
		if (canLie) { result++; }
	}
	
	cout << result;
}