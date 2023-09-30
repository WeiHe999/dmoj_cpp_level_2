#include <bits/stdc++.h>
using namespace std;

void update(long long ind, long long val, vector <long long> &bit, long long n)
{
	for (long long i = ind; i <= n; i += (i & -i)) bit[i] = max(bit[i], val);
}

long long query(long long ind, vector <long long> &bit)
{
	long long s = 0;
	for (long long i = ind; i >= 1; i -= (i & -i)) s = max(s, bit[i]);
	return s;
}

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	long long n, tmp;
	cin >> n;
	vector <long long> vec1(n + 1), vec2(n + 1), bit(n + 1);
	for (long long i = 1; i <= n; i++) cin >> vec1[i];
	for (long long i = 1; i <= n; i++) cin >> vec2[i];
	for (long long i = 1; i <= n; i++)
	{
	    tmp = query(vec1[i] - 1, bit) + vec2[i];
	    update(vec1[i], tmp, bit, n);
	}
	cout << query(n, bit) << "\n";
}
