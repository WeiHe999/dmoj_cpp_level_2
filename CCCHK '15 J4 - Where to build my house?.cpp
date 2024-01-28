#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int l, n, a, b, s = 0, ans = -1, prev = 0;
    cin >> l >> n;
    vector <pair <int, int> > vec1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        vec1.push_back({a, 0});
        vec1.push_back({b, 1});
    }
    
    sort(vec1.begin(), vec1.end());
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i].second==0) 
        {
            s++;
            if (s == 1) ans = max(vec1[i].first - prev, ans);
            
        }
        if (vec1[i].second==1) 
        {
            s--;
            if (s == 0) prev = vec1[i].first;
        }
        
    }
    cout << max(ans, l - prev) << "\n";
}
