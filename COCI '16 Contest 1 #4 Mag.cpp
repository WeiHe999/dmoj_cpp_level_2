#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 1e6+1;

int n, a, b;
unordered_map <int, vector <int> > graph;
vector<int > cnt(MM); // number of continuous 1 before root
pair<int, int> ans = {1e9+1, 1};
int values[MM], dist1[MM], dist2[MM];

bool is_smaller(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first * p2.second < p1.second * p2.first;
}


void dfs1(int cur, int prev)
{
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        dfs1(x, cur);
        if (values[x]==1)
        {
          if (dist1[x] + 1 > dist1[cur])
          {
            dist2[cur] = dist1[cur];
            dist1[cur] = dist1[x] + 1;
          }
          else if (dist1[x] + 1 > dist2[cur])
          {
            dist2[cur] = dist1[x] + 1;
          }
        }
    }
}

void dfs2(int cur, int prev, int plen)
{
  pair<int, int> ans1 = {values[cur], max(plen, dist2[cur]) + dist1[cur] + 1};
  if (is_smaller(ans1, ans)) ans = ans1;
  for (auto x: graph[cur])
  {
    if (x==prev) continue;
    int p1 = 0;
    if (values[cur]==1)
    {
      if (dist1[x] + 1 == dist1[cur]) p1 = max(plen, dist2[cur]) + 1;
      else p1 = max(plen, dist1[cur]) + 1;
    }
    dfs2(x, cur, p1);
  }
  
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) 
    {
        cin >> values[i];
        if (is_smaller({values[i], 1}, ans)) 
        {
            ans = {values[i], 1};
        }
    }
    
    dfs1(1, -1);
    dfs2(1, -1, 0);
    int g = __gcd(ans.first, ans.second);
    
    cout << ans.first/g << "/" << ans.second/g << "\n";
}
