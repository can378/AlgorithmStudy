#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//INPUT
	int N,num;
	vector<int> P;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		P.push_back(num);
	}


	//SORT
	sort(P.begin(), P.end());


	//CALCULATE
	vector<int>prefix_sum(N);
	prefix_sum[0] = P[0];
	int result = prefix_sum[0];

	for (int i = 1; i < P.size(); i++) {
		prefix_sum[i] = prefix_sum[i - 1] + P[i];
		result += prefix_sum[i];
	}


	//RESULT
	cout << result;
}