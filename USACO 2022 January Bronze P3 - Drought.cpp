#include <bits/stdc++.h>
using namespace std;
 
using i64 = int64_t;
 
i64 solve(const vector<i64>& H) {
	const int N = (int)H.size();
	i64 f = 0;
	for (int i = 0; i < N; ++i)
		f += (i%2 == 0 ? 1 : -1)*H[i];
	if (N%2 == 0) {
		if (f != 0) return -1;
	} else {
		if (f < 0) return -1;
	}
	i64 last_o = 0;
	vector<i64> o(N-1);
	for (int i = 0; i+1 < N; ++i) {
		last_o = o[i] = H[i]-f-last_o;
		if (o[i] < 0) return -1;
	}
	if (N%2 == 0) {
		i64 mn = o[0];
		for (int i = 0; i < N; i += 2)
			mn = min(mn,o[i]);
		for (int i = 0; i < N; i += 2)
			o[i] -= mn;
	}
	i64 sum_o = 0;
	for (i64 i: o) sum_o += i;
	return 2*sum_o;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		int N; cin >> N;
		vector<i64> H(N);
		for (auto& i: H) cin >> i;
		cout << solve(H) << "\n";
	}
}
