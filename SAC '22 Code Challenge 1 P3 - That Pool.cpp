#include <bits/stdc++.h>
using namespace std;

const int MM = 101;
char grid[MM][MM];
int n, m, q, a;
char ch;



int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin >> ch;
            grid[i][j] = ch;
        }
    }
    cin >> q;
    for (int i=1; i<=q; i++)
    {
        cin >> a;
        if (a==1)
        {
            for (int r=n; r>0; r--)
            {
                for (int c=1; c<=m; c++)
                {
                    if (grid[r][c]=='X')
                    {
                       grid[r][c] = '.';
                       if (r+1<=n) grid[r+1][c] = 'X';
                    }
                }
            }
            
            while (true)
            {
                bool move_left = false, move_down = false;
                // left
                for (int r=n; r>0; r--)
                {
                    for (int c=1; c<=m; c++)
                    {
                        if (grid[r][c]=='W')
                        {
                            int cur_c = c, next_c = c - 1, cur_r = r;
                            // move left
                            while( next_c > 0 && grid[cur_r][next_c]=='.')
                            {
                               grid[cur_r][next_c] = 'W';
                               grid[cur_r][cur_c] = '.';
                               cur_c = next_c;
                               next_c = cur_c - 1;
                               move_left = true;
                            }
                        }
                    }
                }

                // down
                char grid1[MM][MM];
              for (int i=1; i<=n; i++)
              {
                  for (int j=1; j<=m; j++) grid1[i][j] = grid[i][j];
              }
                for (int r=n; r>0; r--)
                {
                    for (int c=1; c<=m; c++)
                    {
                        if (grid1[r][c]=='W')
                        {
                            int cur_c = c, cur_r = r, next_r = r + 1;
                            //move down
                            if ( next_r <= n && grid1[next_r][cur_c]=='.')
                            {
                               grid[next_r][cur_c] = 'W';
                               grid[cur_r][cur_c] = '.';
                               cur_r = next_r;
                               next_r = cur_r + 1;
                               move_down = true;
                            }
                        }
                    }
                }
                
                if (!move_left && !move_down) break;
                
            }
            
        }
        else
        {
           for (int i=1; i<=n; i++)
           {
               for (int j=1; j<=m; j++) cout << grid[i][j];
               cout << endl;
               
           }
        }
    }
    


    
    

}
