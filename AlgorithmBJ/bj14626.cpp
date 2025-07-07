#include <iostream>
#include <string>
using namespace std;


int main() {
	string org_ISBN = "";
	string ISBN = "";
	cin >> org_ISBN;

	int result = 0;
	if (org_ISBN[12] == '*') {
		int m;
		int sum = 0;
		for (int i = 0; i < 12; i++) {
			if (i % 2 != 0) {
				sum += org_ISBN[i] - '0';
			}
			else {
				sum += (org_ISBN[i] - '0') * 3;
			}
		}
		m = 10 - sum % 10;
	}
	else {

	}
}