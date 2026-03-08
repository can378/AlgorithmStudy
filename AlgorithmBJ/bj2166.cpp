#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<long long>x(N);
	vector<long long>y(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	long long sum1 = 0;
	long long sum2 = 0;
	for (int i = 0; i < N-1; i++) {
		sum1 += x[i] * y[i + 1];
		sum2 +=y[i] * x[i + 1];
	}
	sum1 += x[N - 1] * y[0];
	sum2 += y[N - 1] * x[0];

	double area = llabs(sum1 - sum2) / 2.0;
	printf("%.1f", area);
}