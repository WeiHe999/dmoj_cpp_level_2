#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> m1;
unordered_map <int, vector <int> > graph;

bool make_metal(int start_node)
{
    if (m1[start_node]>0)
    {
        m1[start_node]--;
        return true;
    }
    
    if (graph[start_node].size()==0) return false;

    for (auto a : graph[start_node])
    {
        if (!make_metal(a)) return false;
    }
    return true;
}


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a, want, m, c, tmp, ans = 0;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        m1[x + 1] = a;
    }
    cin >> k;
    for (int b = 0; b < k; b++)
    {
        cin >> want >> m;
        for (int y = 0; y < m; y++)
        {
            cin >> c;
            graph[want].emplace_back(c);
        }
    }
    int cnt = m1[n];
    m1[n] = 0;
    while (make_metal(n))
    {
        cnt++;
    }

    cout << cnt << endl;
    
 
}
