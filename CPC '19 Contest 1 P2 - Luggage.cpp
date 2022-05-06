#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	int n, k, a, ans = 1;
	vector <int> vec1;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
	    cin >> a;
	    vec1.emplace_back(a);
	}
	sort(vec1.begin(), vec1.end());
	for (int i = 0; i < n; i++)
	{
	    ans = max((int)(upper_bound(vec1.begin(), vec1.end(), vec1[i] + k) - vec1.begin() - i), ans);
	}
    cout << ans << endl;
}
