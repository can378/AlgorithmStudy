#include <iostream>
using namespace std;
typedef long long ll;

ll target_num;
const int MOD = 1000000007;

struct Mat {
	ll m00, m01, m10, m11;
};

Mat mul(const Mat& x, const Mat& y){
	Mat result;
	result.m00 = (x.m00 * y.m00 % MOD + x.m01 * y.m10 % MOD) % MOD;
	result.m01 = (x.m00 * y.m01 % MOD + x.m01 * y.m11 % MOD) % MOD;
	result.m10 = (x.m10 * y.m00 % MOD + x.m11 * y.m10 % MOD) % MOD;
	result.m11 = (x.m10 * y.m01 % MOD + x.m11 * y.m11 % MOD) % MOD;
	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> target_num;
	if(target_num == 0) { cout << 0; return 0; }
	
	target_num--;
	Mat answer = { 1,0,0,1 };//단위행렬
	Mat matrix = { 1,1,1,0 };

	while (target_num > 0) {
		if (target_num % 2 == 1) { answer = mul(answer,matrix); }
		matrix = mul(matrix, matrix);
		target_num /= 2;
	}

	cout << answer.m00;
}