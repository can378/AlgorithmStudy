#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
int N, K;
vector<p>order1, order2;
vector<int>result;

bool cmp(p a, p b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main() {
	
	//INPUT
	int n;
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> n; order1.push_back({ n,i }); }
	sort(order1.begin(), order1.end(), cmp);

	cin >> K;
	for (int i = 0; i < K; i++) { cin >> n; order2.push_back({ n,i }); }
	sort(order2.begin(), order2.end(), cmp);


	//CHECK
	int start1 = 0;//order1에서의 위치
	int start2 = 0;//order2에서의 위치
	int loc1 = 0;//실제 배열1에서의 위치
	int loc2 = 0;//실제 배열2에서의 위치

	while (start1 < order1.size() && start2 < order2.size() && loc1<N && loc2<K) 
	{
		bool finish = false;
		bool is_update = false;
		for (int i = start1; i < order1.size(); i++) {
			
			int real_loc1 = order1[i].second;
			int largest1 = order1[i].first;

			if (finish == true)break;
			if (real_loc1 < loc1)continue;

			for (int k = start2; k < order2.size(); k++) {
				if (order2[k].first == largest1 && order2[k].second >= loc2) {

					result.push_back(order1[i].first);

					//cout << "\n" << order1[i].first << "(" << real_loc1 << ")" << " " << order2[k].first << "(" << order2[k].second << ")";
					start1 = i + 1;
					start2 = k + 1;
					loc1 = real_loc1;
					loc2 = order2[k].second;
					finish = true;
					is_update = true;
					break;
				}

				if (finish == true) break;
				if (order2[k].first < largest1) break;
			}
		}

		if (is_update == false)break;

	}

	//RESULT
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}