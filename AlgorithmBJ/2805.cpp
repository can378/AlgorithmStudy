#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	//INPUT
	int N, M;
	cin >> N >> M;
	vector<int> trees(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}


	sort(trees.begin(), trees.end(), greater<int>());
	int cutHeight = trees[0];//저르는 높이
	vector<int>woodBlocks(N, 0);

	
	for (int i = 0; i < N-1; i++) {
		
		//다음 나무와의 차이
		int diff = trees[i] - trees[i + 1];

		if (i != 0)
			woodBlocks[i] = diff*(i+1) + woodBlocks[i - 1];
		else
			woodBlocks[i] = diff;

		cout << "i=" << i << " - " << woodBlocks[i] << "\n";

		//diff만큼 잘라도 아직 모자라면
		if (woodBlocks[i] < M) {
			continue;
		}
		//diff만큼 자르면 딱 맞음
		else if(woodBlocks[i] == M) {

			cout <<"딱맞음=" << trees[i + 1];
			return 0;
		}
		//diff만큼 자르면 낭비임
		else {
			cout<<"조금 남음\n";
			cout << "현재 자를 나무 높이=" << trees[i] << "\n";
			cout << "다음꺼로 자르면 얻을 높이=" << woodBlocks[i] << "\n";
			cout << "오버되는 높이=" << woodBlocks[i]-M<<"\n";
			cout << "1을 자르면=" << woodBlocks[i - 1] + (i + 1);
			cout << "2을 자르면=" << woodBlocks[i - 1] + 2*(i + 1);
			cout << "3을 자르면=" << woodBlocks[i - 1] + 3*(i + 1);
			cout << "4을 자르면=" << woodBlocks[i - 1] + 4 * (i + 1);
			return 0;
		}
		
	}

	cout << cutHeight;
}