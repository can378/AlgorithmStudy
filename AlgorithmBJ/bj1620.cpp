#include <iostream>
#include<unordered_map>
#include <string>
using namespace std;

int main() {
	//INPUT, OUTPUT SPEED
	ios::sync_with_stdio(false);
	cin.tie(0);

	//INPUT
	int N, M;
	cin >> N >> M;
	string pocketmonName;
	unordered_map<int, string>dic1;
	unordered_map<string, int>dic2;

	for (int i = 1; i <= N; i++) {
		cin >> pocketmonName;
		dic1[i] = pocketmonName;
		dic2[pocketmonName] = i;
	}

	//CHECK
	string input;
	for (int i = 0; i < M; i++) {
		cin >> input;
		if ((int)input[0] >= 48 && (int)input[0] <= 57) {
			cout << dic1[stoi(input)] << "\n";
		}
		else {
			cout << dic2[input] << "\n";
		}
	}

}