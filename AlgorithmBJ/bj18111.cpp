#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ground;
int N, M, B;

vector<int> neededSoil(int cut) {
	int leftover = 0;
	int scarce = 0;
	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			if (cut < ground[i][k]) {
				leftover += ground[i][k] - cut;
				time += 2 * (ground[i][k] - cut);
			}
			else if (cut > ground[i][k]) {
				scarce += cut - ground[i][k];
				time += (cut - ground[i][k]);
			}
		}
	}
	return { leftover, scarce, time };
}

int main() {
	//INPUT
	cin >> N >> M >> B;
	ground = vector<vector<int>>(N, vector<int>(M));

	int min_height = 256;
	int max_height = 0;

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			cin >> ground[i][k];
			if (ground[i][k] < min_height) min_height = ground[i][k];
			if (ground[i][k] > max_height) max_height = ground[i][k];
		}
	}

	//CHECK
	int best_time = 200000000;
	int best_height = 0;

	for (int h = min_height; h <= max_height; h++) {
		vector<int> n = neededSoil(h);
		if (n[0] + B >= n[1]) {
			if (n[2] <= best_time) {
				// 더 높은 높이를 우선 선택
				if (n[2] < best_time || h > best_height) {
					best_time = n[2];
					best_height = h;
				}
			}
		}
	}

	//RESULT
	cout << best_time << " " << best_height << "\n";
}
