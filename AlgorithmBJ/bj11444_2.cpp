#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
struct mat {
	ll m00, m01,m10, m11;
};
ll n;
int mod = 1000000007;

mat mul(const mat m1,const mat m2) {
	mat result;
	result.m00 = (m1.m00 * m2.m00 + m1.m01 * m2.m10)%mod;
	result.m01 = (m1.m00 * m2.m01 + m1.m01 * m2.m11)%mod;
	result.m10 = (m1.m10 * m2.m00 + m1.m11 * m2.m10)%mod;
	result.m11 = (m1.m10 * m2.m01 + m1.m11 * m2.m11)%mod;

	return result;
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	
	cin >> n;
	if (n == 0) { cout << 0; return 0; }
	n--;
	
	mat ans;
	ans.m00 = 1;
	ans.m01 = 0;
	ans.m10 = 0;
	ans.m11 = 1;

	mat m;
	m.m00 = 1;
	m.m01 = 1;
	m.m10 = 1;
	m.m11 = 0;

	while (n > 0) {
		if (n % 2 == 1) {
			ans = mul(ans, m);
		}
		n /= 2;
		m = mul(m, m);
	}

	cout << ans.m00%mod;
}