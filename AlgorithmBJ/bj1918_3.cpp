#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int score(char s) {
	if (s == '*' || s == '/')return 2;
	else if (s == '+' || s == '-')return 1;
	else return 0;
}


int main() {
	string str;
	cin >> str;
	stack<char>sign;

	for (char s : str) {

		if (int(s) >= int('A') && int(s) <= int('Z')) {
			cout << s;
		}
		else if (s == '(') { sign.push(s); }
		else if(s==')'){
			while (!sign.empty()) {
				if (sign.top() == '(') { sign.pop(); break; }
				cout << sign.top();
				sign.pop();
			}
		}
		else {
			
			while (!sign.empty() && sign.top() != '(' && score(sign.top()) >= score(s)) {
				cout << sign.top();
				sign.pop();
			}
			sign.push(s);
		}
	}

	while (!sign.empty()) {
		cout << sign.top();
		sign.pop();
	}



}