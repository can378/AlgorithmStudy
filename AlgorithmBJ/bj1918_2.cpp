#include <iostream>
#include <vector>
#include <stack>
using namespace std;
string txt;
int priority(char c) {
	if (c == '*' || c == '/')return 2;
	if (c == '+' || c == '-')return 1;
	return 0;
}

int main() {
	cin >> txt;
	stack<char>stack_char;

	for (char s : txt) {

		if (int(s) >= int('A') && int(s) <= int('Z')) {
			cout << s;
		}
		else if (s == '(') {
			stack_char.push(s);
		}
		else if (s == ')') {
			while (!stack_char.empty() && stack_char.top()!='(') {
				cout << stack_char.top();
				stack_char.pop();
			}
			stack_char.pop();
		}
		else{
			while (!stack_char.empty() && priority(stack_char.top()) >= priority(s)) {
				cout << stack_char.top(); 
				stack_char.pop(); 
			}
			stack_char.push(s);
		}
	}

	while (!stack_char.empty()) {
		cout << stack_char.top();
		stack_char.pop();
	}


}