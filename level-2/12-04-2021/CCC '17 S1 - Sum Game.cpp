#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, k = 0, score1 = 0, score2 = 0;
	cin >> n;
    vector <int> team1, team2;
	for (int x = 0; x < n; x++)
	{
		cin >> a;
		team1.emplace_back(a);
	}
	for (int x = 0; x < n; x++)
	{
		cin >> a;
		team2.emplace_back(a);
	}
	for (int b = 0; b < n; b++)
	{
		score1 += team1[b];
		score2 += team2[b];
		if (score1 == score2) k = b + 1;
	}
	cout << k;
}
