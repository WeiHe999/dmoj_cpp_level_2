#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, c, a, b;
    cin >> n >> q;
    vector <int> vec1;
    vector <pair <int, int> > pre_max = {{0, 1}};
    for (int x = 0; x < n; x++)
    {
        cin >> c;
        vec1.emplace_back(c);
        if (pre_max[x].first > c) pre_max.push_back({pre_max[x].first, pre_max[x].second});
        else if (pre_max[x].first < c) pre_max.push_back({c, 1});
        else pre_max.push_back({pre_max[x].first, pre_max[x].second + 1});
    }
    
	vector<pair<int, int> > suf_max(vec1.size() + 1, {0, 1});
	for (int i=vec1.size()-1; i>=0; i--)
	{
	    if (vec1[i] > suf_max[i+1].first) suf_max[i] = {vec1[i], 1};
	    else if (vec1[i] < suf_max[i+1].first) suf_max[i] = suf_max[i+1];
	    else suf_max[i] = {suf_max[i+1].first, suf_max[i+1].second+1};
	}   
    
    for (int y = 0; y < q; y++)
    {
        cin >> a >> b;
        if (pre_max[a - 1].first > suf_max[b].first) cout << pre_max[a - 1].first << " " << pre_max[a - 1].second << endl;
        else if (pre_max[a - 1].first < suf_max[b].first) cout << suf_max[b].first << " " << suf_max[b].second << endl;
        else cout << pre_max[a - 1].first << " " << pre_max[a - 1].second + suf_max[b].second << endl;
    }
}
