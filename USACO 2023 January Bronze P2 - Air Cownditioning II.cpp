#include <bits/stdc++.h>
using namespace std;

void rec(string cur, int m, int &ans, vector <pair <int, int> > vec1, vector <pair <int, int> > vec2,
vector <int> vec3, vector <int> vec4, vector <int> vec5)
{
	if (cur.size() == m)
	{
	    bool flag = true;
	    int p = 0;
	    vector <int> tmp(101);
    	for (int i = 1; i <= 100; i++)
    	{
    		for (int j = 0; j < vec2.size(); j++) if (cur[j] == '1' && vec2[j].first <= i && vec2[j].second >= i) tmp[i] += vec5[j];
    	}
    	for (int i = 0; i < vec1.size(); i++) for (int j = vec1[i].first; j <= vec1[i].second; j++) if (tmp[j] < vec3[i]) flag = false;
    	for (int i = 0; i < cur.size(); i++) if (cur[i] == '1') p += vec4[i];
    	if (flag) ans = min(p, ans);
	    return;
	}
	rec(cur + '1', m, ans, vec1, vec2, vec3, vec4, vec5);
	rec(cur + '0', m, ans, vec1, vec2, vec3, vec4, vec5);
}

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
	int n, m, s, t, c, a, b, p, ans = 1e9;
	cin >> n >> m;
	vector <pair <int, int> > vec1, vec2;
    vector <int> vec3, vec4, vec5;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t >> c;
		vec1.push_back({s, t});
		vec3.emplace_back(c);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> p >> c;
		vec2.push_back({a, b});
		vec5.emplace_back(p);
		vec4.emplace_back(c);
	}
	rec("", m, ans, vec1, vec2, vec3, vec4, vec5);
	cout << ans << "\n";
}
