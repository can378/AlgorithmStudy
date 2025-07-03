#include<iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, B;
	cin >> N >> M >> B;
	vector<vector<int>> ground(N, vector<int>(M, 0));

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			cin >> ground[i][k];
			if (max < ground[i][k]) { max = ground[i][k]; }
		}
	}

	

}