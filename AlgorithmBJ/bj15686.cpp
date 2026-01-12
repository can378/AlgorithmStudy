#include <iostream>
#include <vector>
using namespace std;
int map[51][51];
vector<pair<int,int>> houses;
vector<pair<int, int>> chicken_stores;
vector<int>picked_chickens;

int min_sum = 12000000;
int N, M;

void get_chicken_distance(vector<int> picked) {
	int dist_sum = 0;
	for (int i = 0; i < houses.size(); i++) {
		int house_x = houses[i].first;
		int house_y = houses[i].second;

		int min_dist = 10000000;
		for (int k = 0; k < picked.size(); k++) {
			int idx = picked[k];
			int store_x = chicken_stores[idx].first;
			int store_y = chicken_stores[idx].second;

			//도시의 치킨 거리의 최솟값
			//|r1-r2| + |c1-c2|
			int dist= abs(store_x - house_x) + abs(store_y - house_y);
			if (min_dist > dist) { min_dist = dist;}
		}
		dist_sum += min_dist;
	}
	if (dist_sum < min_sum) { min_sum = dist_sum; }
}
void pick_chicken_store(int now) {
	if (picked_chickens.size() == M) {
		get_chicken_distance(picked_chickens);
		return;
	}

	for (int i = now; i < chicken_stores.size(); i++) {
		picked_chickens.push_back(i);
		pick_chicken_store(i+1);
		picked_chickens.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	//INPUT
	//M=폐업시키지 않을 치킨집 개수
	cin >> N >> M;
	//0=빈칸, 1=집, 2=치킨집
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			int loc;
			cin >> loc;
			if (loc == 1) { houses.push_back({ i,k }); }
			else if (loc == 2) { chicken_stores.push_back({ i,k }); }
		}
	}

	//CHECK
	pick_chicken_store(0);
	
	//RESULT
	cout << min_sum;
}