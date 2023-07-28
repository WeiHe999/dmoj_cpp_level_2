#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, s = 1000000;
	cin >> n;
	for (long long i = 1; i <= 1000001; i++)
	{
		while (i + s > 1000001 || ((i * (i - 1) >> 1) + (s * (s - 1) >> 1)) > n) s--;
		if (((i * (i - 1) >> 1) + (s * (s - 1) >> 1)) == n)
		{
			cout << i + s - 1 << "\n";
			for (long long j = 1; j < i; j++)
			{
				cout << 0;
				if (j == i - 1 && s == 0) cout << "\n";
				else cout << " ";
			}
			for (long long j = 0; j < s; j++)
			{
				if (!j) cout << 1;
				else cout << 0;
				if (j == s - 1) cout << "\n";
				else cout << " ";
			}
			return 0;
		}
	}
	cout << "-1\n";
}
