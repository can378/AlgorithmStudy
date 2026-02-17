#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int priority(char s) {
	if (s == '*' || s == '/')return 2;
	if (s == '+' || s == '-')return 1;
	return 0;
}
int main() {
	string str; cin >> str;
	
	stack<char>st;

	for (char s : str) {

		//문자열
		if (int(s) >= int('A') && int(s) <= int('Z')) {
			cout << s;
		}
		// ( )
		else if (s == '(') { st.push(s); }
		else if (s == ')') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		// 연산자
		else {
			while (!st.empty() && priority(st.top()) >= priority(s)) {
				cout << st.top();
				st.pop();
			}
			st.push(s);
		}
	}


	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}


}