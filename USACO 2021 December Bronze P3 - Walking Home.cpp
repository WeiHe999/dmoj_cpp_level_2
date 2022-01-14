#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int t, n, tot_turns;
    cin >> t;
    char a;
    for (int x = 0; x < t; x++)
    {
        vector <vector <char> > graph;
        vector <char> tmp;
        cin >> n >> tot_turns;
        for (int i = 0; i < n; i++)
        {
            tmp = {};
            for (int j = 0; j < n; j++)
            {
                cin >> a;
                tmp.emplace_back(a);
            }
            graph.push_back(tmp);
        }
        vector <vector <vector <vector <int> > > > dp(51, vector <vector <vector <int> > >(51, vector <vector <int> >(tot_turns + 1, vector <int>(2))));
        dp[0][0][0][0] = 1;
        dp[0][0][0][1] = 1;
        for (int r=0; r<n; r++)
        {
            for(int c=0; c<n; c++)
            {
                for(int k=0; k<=tot_turns; k++)
                {
                    if(dp[r][c][k][0]>0)
                    {
                        if (c+1 < n && graph[r][c+1]=='.')
                        {
                            dp[r][c+1][k][0] += dp[r][c][k][0];
                        }
                        if (r+c>0 && r+1 < n && graph[r+1][c]=='.' && k+1 <= tot_turns)
                        {
                            dp[r+1][c][k+1][1] += dp[r][c][k][0];
                        }
                    }
                    if(dp[r][c][k][1]>0)
                    {
                        if (r+1<n && graph[r+1][c]=='.')
                        {
                            dp[r+1][c][k][1] += dp[r][c][k][1];
                        }
                        if (r+c>0 && c+1<n && graph[r][c+1]=='.' && k+1<=tot_turns)
                        {
                            dp[r][c+1][k+1][0] += dp[r][c][k][1];
                        }
                    }                    
                    
                }
            }
        }
        int ans = 0;
        for(int k=0; k<=tot_turns; k++)
        {
            for (int f=0; f<2; f++)
            {
                ans += dp[n-1][n-1][k][f];
            }
        }
        cout << ans << endl;
    }
}
