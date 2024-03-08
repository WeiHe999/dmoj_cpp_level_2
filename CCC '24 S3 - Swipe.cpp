#include <bits/stdc++.h>
using namespace std;


int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector<int> v1(n+1), v2(n+1);
    for (int i=1; i<=n; i++) cin >> v1[i];
    for (int i=1; i<=n; i++) cin >> v2[i];
    if (v1==v2)
    {
        cout << "YES\n";
        cout << "0\n";
        return 0;
    }
    
    vector<pair<int, int> > vs;
    int start_p = 1;
    for (int i=1; i<=n; i++)
    {
        if (v2[i]!=v2[start_p]) 
        {
            vs.push_back({start_p, i-1});
            start_p = i;
        }
    }
    vs.push_back({start_p, n});
   
    int cur_p = 1;
    vector<pair<int, int> > left_sw, right_sw;
    for (auto x: vs)
    {
        int left = x.first, right = x.second;
        int value = v2[left];
        int ind = -1;
        for (int i=cur_p; i<=n; i++)
        {
            if (v1[i]==value)
            {
                ind = i;
                cur_p = i+1;
                break;
            }
        }
        if (ind==-1)
        {
            cout << "NO\n";
            return 0;
        }
        

        if (ind <= left)
        {
            // right swipe
            right_sw.push_back({ind, right});
        }
        else if (ind >= right)
        {
            // left swipe
            left_sw.push_back({left, ind});
        }
        else
        {
            // both left swipe and right swipe
            left_sw.push_back({left, ind});
            right_sw.push_back({ind, right});
        }
    }
    
    cout << "YES\n";
    cout << left_sw.size() + right_sw.size() << "\n";
    for (auto x: left_sw)
    {
        cout << "L " << x.first-1 << " " << x.second-1 << "\n";
    }
    for (int i=right_sw.size()-1; i>=0; i--)
    {
        cout << "R " << right_sw[i].first-1 << " " << right_sw[i].second-1 << "\n";
    }
    
    
    
}
