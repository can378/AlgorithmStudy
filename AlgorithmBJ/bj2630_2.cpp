#include <iostream>
#include<vector>
using namespace std;

int N;
vector<vector<int>>paper;
int blue = 0;
int white = 0;

bool isAllSame(int x, int y,int size) {
	for (int i = x; i < x+size; i++) {
		for (int k = y; k < y+size; k++) {
			if (paper[i][k]!=paper[x][y]) {
				return false;
			}
		}
	}
	return true;
}
void checkPaper(int x, int y, int size) {

	if (isAllSame(x, y, size)) {
		if (paper[x][y] == 1) { blue++; }
		else { white++; }
	}
	else {
		checkPaper(x, y, size / 2);//왼쪽위
		checkPaper(x, y + size / 2, size / 2);//오른쪽위
		checkPaper(x + size / 2, y, size / 2);//왼쪽 아래
		checkPaper(x + size / 2, y + size / 2, size / 2);//오른쪽 아래
	}
}
int main() {
	
	//INPUT
	cin >> N;
	paper= vector<vector<int>>(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cin >> paper[i][k];
		}
	}

	//
	checkPaper(0,0,N);

	cout << white << "\n" << blue;
}