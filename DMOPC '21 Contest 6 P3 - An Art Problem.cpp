//DMOPC '21 Contest 6 P3 - An Art Problem

#include <bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int> >  start_nodes, vector<vector<int> > &grid, int rows, int cols, int k)
{
    vector<vector<int> > dist(rows+1, vector<int> (cols+1, -1));
    vector<vector<bool> > visited(rows+1, vector<bool> (cols+1, false));
    queue<pair<int, int> > q1;
    for (auto x: start_nodes)
    {

        q1.push({x[1], x[2]});
        dist[x[1]][x[2]] = 0;
        visited[x[1]][x[2]] = true;
    }
    int level = 0;
    while(!q1.empty())
    {
        pair<int, int> cur = q1.front();
        if (dist[cur.first][cur.second] > level) 
        {
            level++;
            if (level >= k) return;
        }
        q1.pop();
        vector<pair<int, int> >  children = { {cur.first-1, cur.second}, {cur.first+1, cur.second},
        {cur.first, cur.second-1}, {cur.first, cur.second+1} };
        for (auto x: children)
        {
            if (x.first>=1 && x.first<=rows && x.second>=1 && x.second<=cols && !visited[x.first][x.second])
            {
                if(grid[x.first][x.second]==0)
                {
                    grid[x.first][x.second] = grid[cur.first][cur.second];
                    //cout << "change (" << x[1] << ", " << x[2] << ") to: " << x[0] << endl;
                }
            dist[x.first][x.second]= dist[cur.first][cur.second] + 1;
            visited[x.first][x.second] = true; 
            q1.push(x);
            }
        }
        
    }
    
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int rows, cols, k, a;
    cin >> rows >> cols >> k;
    vector<vector<int> > grid(rows+1, vector<int> (cols+1, 0));
    vector<vector<int> > v1;
    for (int i=1; i<=rows; i++)
    {
        for (int j=1; j<=cols; j++)
        {
            cin >> a;
            grid[i][j] = a;
            if (a>0) v1.push_back({a, i, j});
        }
    }
    sort(v1.begin(), v1.end());
    bfs(v1, grid, rows, cols, k);
    for (int i=1; i<=rows; i++)
    {
        for (int j=1; j<=cols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    } 
    
    
}
