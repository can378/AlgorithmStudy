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
	int cutHeight = trees[0];//������ ����
	vector<int>woodBlocks(N, 0);

	
	for (int i = 0; i < N-1; i++) {
		
		//���� �������� ����
		int diff = trees[i] - trees[i + 1];

		if (i != 0)
			woodBlocks[i] = diff*(i+1) + woodBlocks[i - 1];
		else
			woodBlocks[i] = diff;

		cout << "i=" << i << " - " << woodBlocks[i] << "\n";

		//diff��ŭ �߶� ���� ���ڶ��
		if (woodBlocks[i] < M) {
			continue;
		}
		//diff��ŭ �ڸ��� �� ����
		else if(woodBlocks[i] == M) {

			cout <<"������=" << trees[i + 1];
			return 0;
		}
		//diff��ŭ �ڸ��� ������
		else {
			cout<<"���� ����\n";
			cout << "���� �ڸ� ���� ����=" << trees[i] << "\n";
			cout << "�������� �ڸ��� ���� ����=" << woodBlocks[i] << "\n";
			cout << "�����Ǵ� ����=" << woodBlocks[i]-M<<"\n";
			cout << "1�� �ڸ���=" << woodBlocks[i - 1] + (i + 1);
			cout << "2�� �ڸ���=" << woodBlocks[i - 1] + 2*(i + 1);
			cout << "3�� �ڸ���=" << woodBlocks[i - 1] + 3*(i + 1);
			cout << "4�� �ڸ���=" << woodBlocks[i - 1] + 4 * (i + 1);
			return 0;
		}
		
	}

	cout << cutHeight;
}