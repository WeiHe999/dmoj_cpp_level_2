#include <bits/stdc++.h>
using namespace std;

const int MM = 2*1e5;
vector<bool> vis(MM+1);
unordered_map <int, vector <int> > graph;
map<pair<int, int>, int > colors; // 0 is grey, 1 is red, 2 is blue
map<int, pair<int, int> > edges; // edge_id: {from, to}
unordered_map<int, char> m1 = {{0, 'G'}, {1, 'R'}, {2, 'B'}};

void dfs(int cur, int prev)
{
    vis[cur] = true;
    for (auto x: graph[cur])
    {
        if (x==prev) continue;
        if (!vis[x])
        {
            // cor the edge cur--> x based on prev-->cur
            if (prev==-1) 
            {
                colors[{min(x, cur), max(x, cur)}] = 1;
            }
            else
            {
                if (colors[{min(prev, cur), max(prev, cur)}] == 1) 
                {
                    colors[{min(x, cur), max(x, cur)}] = 2;
                }
                if (colors[{min(prev, cur), max(prev, cur)}] == 2) 
                {
                    colors[{min(x, cur), max(x, cur)}] = 1;
                }
            }
            
            dfs(x, cur);
            
        }
    }
    
}

int32_t main() {

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        edges[i] = {min(a, b), max(a, b)};
        colors[{min(a, b), max(a, b)}] = 0; // grey
        
    }
    
    for (int i=1; i<=n; i++)
    {
        if (!vis[i]) dfs(i, -1);
    }
    
    
    for (auto x: edges)
    {
        cout << m1[colors[x.second]];
    }
    cout << endl;
    
    
  
}
