#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	int n, s1 = 0, s2 = 0, ind = 0;
	string str1;
	cin >> n >> str1;
	while (ind < n)
	{
		if (str1[ind] == 'F')
		{
			ind++;
			continue;
		}
		int next_ind = ind + 1;
		while (next_ind < n && str1[next_ind] == 'F') next_ind++;
		if (next_ind == n) break;
		int num = next_ind - ind - 1, size;
		if (str1[next_ind] == str1[ind])
		{
			if (num % 2 == 0) s1 += 1;
			s2 += num + 1;
		}
		else
		{
			if (num % 2 != 0) s1 += 1;
			s2 += num;
		}
		ind = next_ind;
	}
	int beg = 0, end = 0;
	while (beg < n && str1[beg] == 'F') beg++;
	while (end < n && str1[n - 1 - end] == 'F') end++;
	if (beg == n)
	{
		s1 = 0;
		s2 = n - 1;
	}
	else
	{
		s2 += beg;
		s2 += end;
	}
	vector <int> ans;
	if (beg == 0 && end == 0) for (int i = s1; i <= s2; i += 2) ans.emplace_back(i);
	else for (int i = s1; i <= s2; i++) ans.emplace_back(i);
	cout << ans.size() << "\n";
	for (auto x : ans) cout << x << "\n";
}
