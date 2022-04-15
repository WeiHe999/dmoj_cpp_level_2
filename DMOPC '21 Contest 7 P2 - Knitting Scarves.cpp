#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, b, c, left, right;
    unordered_map<int, pair<int, int> > m1;
    cin >> n >> q;
    for (int i=0; i<=n; i++)
    {
        m1[i] = {i-1, i+1};
    }
    for (int i=0; i<q; i++)
    {
        cin >> a >> b >> c;
        int c_next = m1[c].second;
        int b_next = m1[b].second;
        int a_pre = m1[a].first;
        
        if (c_next!=a)
        {
            m1[c] = {m1[c].first, a};
            m1[a] = {c, m1[a].second};
            m1[b] = {m1[b].first, c_next};
            m1[c_next] = {b, m1[c_next].second};
            m1[b_next] = {a_pre, m1[b_next].second};
            m1[a_pre] = {m1[a_pre].first, b_next};            
        }
        

    }
    
    int k = 0, cnt = 0;
    while (k<=n)
    {
        if (cnt==n) break;
        if (cnt<n-1) cout << m1[k].second << " ";
        else cout << m1[k].second << endl;
        k = m1[k].second;
        cnt ++;
    }

    
}
