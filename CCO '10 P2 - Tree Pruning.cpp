#include <bits/stdc++.h>
using namespace std;

const int MM = 303;
int dp[MM][2*MM], cnt[MM], values[MM];
unordered_map<int, vector<int> > graph;
int n, diff;

void dfs(int cur)
{
  // base case
  if (graph[cur].size()==0)
  {
    cnt[cur] = 1;
    dp[cur][values[cur] + n] = 0;
    dp[cur][0 + n] = 1;
  }
  // recursive case
  cnt[cur] = 1;
  dp[cur][0 + n] = 1;
  for (auto x: graph[cur])
  {
    dfs(x);
    cnt[cur] += cnt[x];
  }

  // case-1: there is only one child
  if (graph[cur].size()==1)
  {
    int v = graph[cur][0]; // child
    // loop through all possible difference in the child
    for (int d = -1*cnt[v]; d<= cnt[v]; d++)
    {
      dp[cur][d + values[cur] + n] = min(dp[cur][d + values[cur] + n], dp[v][d + n]);
    }
  }
  
  // case-2: there is two children
  if (graph[cur].size()==2) 
  {
    int v1 = graph[cur][0], v2 = graph[cur][1];
    for (int d1 = -1*cnt[v1]; d1<= cnt[v1]; d1++)
    {
      for (int d2 = -1*cnt[v2]; d2<= cnt[v2]; d2++)
      {
        dp[cur][d1 + d2 + values[cur] + n] = min(dp[cur][d1 + d2 + values[cur] + n], 
          dp[v1][d1+n] + dp[v2][d2+n]); 
      }
    }
    
  }
  
}

int main() 
{
    cin >> n >> diff;
    for (int i=0, a, b , c; i<n; i++)
    {
      cin >> a >> b >> c;
      if (b==1) values[a] = 1;
      else values[a] = -1; // 1 for white, -1 for black
      for (int j=0, m; j<c; j++)
      {
        cin >> m;
        graph[a].push_back(m); // directed graph
      }
    }
    
    
    memset(dp, 0x3f, sizeof(dp));
    dfs(0);
    if (dp[0][diff+n] > 1e9) cout << -1 << endl;
    else cout << dp[0][diff+n] << endl;
    return 0;
}
