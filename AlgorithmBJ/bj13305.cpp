#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//INPUT
	int n; cin >> n;
	vector<pair<long, long>> city(n);

	for (int i = 0; i < n - 1; i++) { cin >> city[i].second; }
	for (int i = 0; i < n; i++) { cin >> city[i].first; }


	//SEARCH
	long long int result = 0;
	int priceIndex = 0;

	for (int i = 0; i < n - 1; i++)
	{
		result += city[priceIndex].first * city[i].second;
		if (city[priceIndex].first > city[i + 1].first)
		{
			priceIndex = i + 1;
		}
	}
	cout << result;

}