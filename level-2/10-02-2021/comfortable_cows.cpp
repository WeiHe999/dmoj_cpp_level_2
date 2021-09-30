#include <bits/stdc++.h>
using namespace std;

int n;
bool a[1001][1001];
vector <int> dx = {-1,1,0,0};
vector <int> dy = {0,0,-1,1};
 
bool valid_position(int x,int y)
{
	return x >= 0 && x <= n && y >= 0 && y <= n;
}
 
bool comfortable(int x, int y)
{
	if (a[x][y] == 0) return 0;
	int neighbours = 0;
	for (int d = 0; d < 4; d++) if (valid_position(x + dx[d], y + dy[d]) && a[x + dx[d]][y + dy[d]]) neighbours++;
	if (neighbours == 3) return 1;
	return 0;
}
 
int main()
{
	int x, y;
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int d = 0; d < 4; d++) if (valid_position(x + dx[d], y + dy[d])) s -= comfortable(x + dx[d], y + dy[d]);
		a[x][y] = 1;
		for (int d = 0; d < 4; d++) if (valid_position(x + dx[d], y + dy[d])) s += comfortable(x + dx[d], y + dy[d]);
		s += comfortable(x, y);
		cout << s << endl;
	}
}
