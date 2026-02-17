#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int city, bus;
int MAX = 1000000000;
vector<vector<int>>dist;

int main() {
	cin >> city >> bus;
	dist = vector<vector<int>>(city + 1, vector<int>(city+1,MAX));

	for (int i = 0; i < bus; i++) {
		int a, b, w; cin >> a >> b >> w;
		if (dist[a][b] > w) { dist[a][b] = w; }
	}
	
	for (int i = 1; i <= city; i++) { dist[i][i] = 0; }
	for (int i = 1; i <= city; i++) {
		for (int k = 1; k <= city; k++) {
			for (int j = 1; j <= city; j ++ ) {
				dist[k][j] = min( dist[k][i] + dist[i][j],dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= city; i++) {
		for (int k = 1; k <= city; k++) {
			int d = dist[i][k];
			if (d >= MAX)d = 0;
			cout << d << " ";
		}
		cout << "\n";
	}

}