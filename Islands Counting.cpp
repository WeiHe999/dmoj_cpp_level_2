#include <bits/stdc++.h>
using namespace std;

vector <vector <bool> > vis(1001, vector <bool>(1001, false));
vector <vector <int> > grid(1001, vector <int>(1001));

void dfs(int row, int col, int r, int c)
{
    vector <int> vec1 = {-1, -1, -1, 0, 0, 1, 1, 1}, vec2 = {-1, 0, 1, -1, 1, -1, 0, 1};
	vis[row][col] = true;
	for (int k = 0; k < 8; k++)
	{
	    if (row + vec1[k] >= 0 && row + vec1[k] < r && col + vec2[k] >= 0 &&
	    col + vec2[k] < c && grid[row + vec1[k]][col + vec2[k]] && !vis[row + vec1[k]][col + vec2[k]]) dfs(row + vec1[k], col + vec2[k], r, c);
	}
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, a, s = 0;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a;
            if (a) grid[i][j] = 1;
        }
    }
	for (int i = 0; i < r; i++)
	{
	    for (int j = 0; j < c; j++)
	    {
			if (grid[i][j] && !vis[i][j])
			{
				dfs(i, j, r, c);
				s++;
			}
	    }
	}
	cout << s << "\n";
}
