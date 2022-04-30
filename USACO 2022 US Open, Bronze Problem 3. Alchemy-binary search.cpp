#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> m1, m2;
unordered_map <int, vector <int> > graph, graph1;

bool make_metal(int start_node, int m)
{
    if (m1[start_node]>=m)
    {
        m1[start_node] -= m;
        return true;
    }
    int remaining = m - m1[start_node];
    m1[start_node] = 0;
    if (graph[start_node].size()==0) return false;

    for (auto a : graph[start_node])
    {
        if (!make_metal(a, remaining)) return false;
    }
    return true;
}


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a, want, m, c, tmp, ans;
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
    m2 = m1;
    graph1 = graph;

    int left = 0, right = 1000000, mid;
    while (left <= right)
    {
        m1 = m2; 
        graph = graph1;
        mid = (left+right)/2;
        if (make_metal(n, mid))
        {
            left = mid+1;
            ans = mid;
        }
        else
        {
            right = mid-1;
        }
    }

    cout << ans << endl;
    
 
}
