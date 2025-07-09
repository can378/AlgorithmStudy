#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M; string S;
	cin >> N >> M >> S;
	int count = 0;
	int result=0;

	for (int i = 1; i < M-1;) {
		if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
			count++;
			if (count >= N)result++;
			i += 2;
		}
		else {
			count = 0;
			i += 1;
		}
	}
	cout << result;
}