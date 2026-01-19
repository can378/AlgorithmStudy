#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N,M;

vector<pair<int, int>>houses;
vector<pair<int, int>>chickens;

int chicken_map[51][51];
int min_chicken_dis = 10000000000;

//집들과의 치킨거리 계산
void check_chicken_dis(vector<int>picked) {
	int dis = 0;

	for (int i = 0; i < houses.size(); i++) {
		int min_dis=100000000;
		for (int k = 0; k < picked.size(); k++) {

			int now_dis= abs(houses[i].first - chickens[picked[k]].first) + abs(houses[i].second - chickens[picked[k]].second);
			if (now_dis < min_dis) { min_dis = now_dis; }

		}
		dis += min_dis;

	}
	if (dis < min_chicken_dis) { min_chicken_dis = dis; }
}

//치킨집 뽑기
void pick_chicken_store(int now, vector<int>picked) {
	if (picked.size() == M) {
		check_chicken_dis(picked);
		return;
	}

	for (int i = now; i < chickens.size(); i++) {
		picked.push_back(i);
		pick_chicken_store(i+1, picked);
		picked.pop_back();
	}

}
int main() {
	cin >> N>>M;//도시크기, 남길 치킨집수
	
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			cin >> chicken_map[i][k];

			if (chicken_map[i][k] == 1) { houses.push_back({ i,k }); }
			if (chicken_map[i][k] == 2) { chickens.push_back({ i,k }); }
		}
	}

	pick_chicken_store(0,{});

	cout << min_chicken_dis;
}