#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	//INPUT
	int N; cin >> N;
	vector<int>fruits(N,0);
	for (int i = 0; i < N; i++) {
		cin >> fruits[i];
	}

	//CHECK
	int left = 0;
	map<int, int>dic;
	int maxLeng = 0;

	for (int right = 0; right < N; right++) {
		dic[fruits[right]]++;

		while (dic.size() > 2) {
			//left를 늘려 범위를 변경합니다
			dic[fruits[left]]--;
			if (dic[fruits[left]] == 0) {
				dic.erase(fruits[left]);
			}
			left++;
		}
		maxLeng = right - left + 1 > maxLeng ? right - left + 1 : maxLeng;
	}
	cout << maxLeng;
	
}