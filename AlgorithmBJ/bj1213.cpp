#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	string name; cin >> name;
	int size = name.size();
	
	vector<int> alphabet(26);
	vector<char> result(size);

	for (int i = 0; i < size; i++)
	{	alphabet[int(name[i]) - 65]++;	}


	int oddNum = 0;
	int lastOddNumIndex;
	int lastAlphabetIndex;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] % 2 == 1) { lastOddNumIndex = i; oddNum++; }
	}

	for (int i = 25; i >= 0; i--)
	{
		if (alphabet[i] != 0) { lastAlphabetIndex = i; break; }
	}


	int middleIndex = 0;
	if (oddNum == 0 || (oddNum==1 && lastAlphabetIndex==lastOddNumIndex)) 
	{
		for (int i = 0; i <= lastAlphabetIndex; i++)
		{
			if (alphabet[i] != 0) 
			{
				result.insert(result.begin() + middleIndex, alphabet[i], char(i + 65));
				middleIndex += (alphabet[i] / 2);
			}
		}
	}
	else if (oddNum == 1) 
	{
		for (int i = 0; i <=lastAlphabetIndex; i++)
		{
			if (alphabet[i] != 0)
			{
				if (alphabet[i] % 2 == 0) 
				{
					result.insert(result.begin() + middleIndex, alphabet[i], char(i + 65));
					middleIndex += (alphabet[i] / 2);
				
				}
				else 
				{
					result.insert(result.begin() + middleIndex, alphabet[i]-1, char(i + 65));
					middleIndex += (alphabet[i] / 2);
				}
				
			}
		}
		result.insert(result.begin() + middleIndex, 1, char(lastOddNumIndex + 65));
	}
	else { cout << "I'm Sorry Hansoo"; return 0; }
	
	for (char c : result) { cout << c; }

	return 0;

}