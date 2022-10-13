#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <vector <int> > grid(n, vector <int>(n));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            cin >> grid[x][y];
        }
    }
	if (grid[0][0] < grid[0][1] && grid[0][0] < grid[1][0])
	{
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++) cout << grid[a][b] << " ";
			cout << "\n";
		}
	}
	else if (grid[0][0] > grid[0][1] && grid[0][0] < grid[1][0])
	{
		for (int a = n - 1; a >= 0; a--)
		{
			for (int b = 0; b < n; b++) cout << grid[b][a] << " ";
			cout << "\n";
		}
	}
	else if (grid[0][0] > grid[0][1] && grid[0][0] > grid[1][0])
	{
		for (int a = n - 1; a >= 0; a--)
		{
			for (int b = n - 1; b >= 0; b--) cout << grid[a][b] << " ";
			cout << "\n";
		}
	}
	else
	{
		for (int a = 0; a < n; a++)
		{
			for (int b = n - 1; b >= 0; b--) cout << grid[b][a] << " ";
			cout << "\n";
		}
	}
}
