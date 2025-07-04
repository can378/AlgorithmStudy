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
		if (a.second == b.second) return a.first < b.first; // ���� Ƚ�� ������ ���� ���� ��
		return a.second > b.second; // ���� Ƚ�� ���� ��������
		});

	//RESULT
	cout << freq[0].first << endl;

	return 0;
}
