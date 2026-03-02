#include <iostream>
#include<vector>
#include <stack>
using namespace std;

string str;

int score(char s) {
	if (s == '*' || s == '/')return 2;
	if (s == '+' || s == '-')return 1;
	return 0;
}
int main() {
	stack<char>stck;

	cin >> str;
	for (char s : str) {
		//cout << "now=" << s << ", ";
		if (int(s) >= int('A') && int(s) <= int('Z')) {
			cout << s;
		}
		else if (s == '(') { stck.push(s); }
		else if(s==')'){
			while (!stck.empty()) {
				if (stck.top() == '(') { 
					stck.pop();
					break; 
				}
				if (score(stck.top()) >= score(s)) { 
					cout << stck.top();
					stck.pop(); 
				}
			}
			
		}
		else {
			
			while (!stck.empty()) {
				//cout << "test ";
				bool isupdate = false;
				if (score(stck.top()) >= score(s)) {
					cout << stck.top();
					stck.pop();
					isupdate = true;
				}
				if (!isupdate)break;
			}
			stck.push(s);
			
		}
	}

	while (!stck.empty()) {
		cout << stck.top();
		stck.pop();
	}
}