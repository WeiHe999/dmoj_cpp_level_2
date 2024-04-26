#include <bits/stdc++.h>
using namespace std;

unordered_map <int, vector <int> > graph;
vector <int> vis_leaf;
int n, a, b;

void dfs(int cur, int prev)
{
    if (graph[cur].size()==1) vis_leaf.push_back(cur);
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        dfs(x, cur);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs(1, -1);
    
    int sz = vis_leaf.size();
    if (sz % 2 ==1) cout << sz/2 + 1 << endl;
    else cout << sz/2 << endl;
    for (int i=0; i<sz/2; i++)
    {
        cout << vis_leaf[i] << " " << vis_leaf[i + sz/2] << "\n";
    }
    if (sz % 2 ==1) cout << vis_leaf[0] << " " << vis_leaf.back() << "\n";

}
