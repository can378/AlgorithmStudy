#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	//INPUT
	int N, L;
	cin >> N >> L;

	vector <float> leak(N);
	for (int i = 0; i < N; i++) { cin >> leak[i]; }
	sort(leak.begin(), leak.end());


	//SEARCH
	int count = 1;
	float startPos = leak[0] - 0.5;
	float lastPos = startPos + L;

	for (int i = 0; i < N; i++)
	{
		if (leak[i] > lastPos)
		{
			startPos = leak[i] - 0.5;
			lastPos = startPos + L;

			count++;
		}
	}

	cout << count;

}