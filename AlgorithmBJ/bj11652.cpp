#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	//INPUT
	long long N, num;
	cin >> N;

	map<long long, int> numbers;
	for (int i = 0; i < N; i++) {
		cin >> num;
		numbers[num]++;
	}

	// MAP -> VECTOR
	vector<pair<long long, int>> freq(numbers.begin(), numbers.end());

	// SORT
	sort(freq.begin(), freq.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
		if (a.second == b.second) return a.first < b.first; // 등장 횟수 같으면 숫자 작은 거
		return a.second > b.second; // 등장 횟수 기준 내림차순
		});

	//RESULT
	cout << freq[0].first << endl;

	return 0;
}
