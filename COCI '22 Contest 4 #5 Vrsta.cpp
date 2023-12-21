#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> t(1 << 19);

void update(int x, int val)
{
	for (; x > 0; x /= 2) t[x] += val;
}

int query(int x, int val)
{
	if (x >= (1 << 18)) return x - (1 << 18);
	if (t[x * 2] >= val) return query(x * 2, val);
	return query(x * 2 + 1, val - t[x * 2]);
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	int n, s = 0, tmp = 0;
	cin >> n;
	vector <int> vec1(n), cnt(n), vec2, vec3(n);
	map <int, int> ind;
	for (int i = 0; i < n; i++)
	{
	    cin >> vec1[i] >> cnt[i];
		vec2.push_back(vec1[i]);
	}
	sort(vec2.begin(), vec2.end());
	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
	for (int i = 0; i < vec2.size(); i++)
	{
		ind[vec2[i]] = s;
		vec3[s] = vec2[i];
		s++;
	}
	for (int i = 0; i < n; i++)
	{
		tmp += cnt[i];
		update(ind[vec1[i]] + (1 << 18), cnt[i]);
		cout << vec3[query(1, (tmp + 1) / 2)] << "\n";
	}
}
