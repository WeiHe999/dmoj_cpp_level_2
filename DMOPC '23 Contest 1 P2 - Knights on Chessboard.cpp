#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <vector <bool> > vec1(n, vector <bool>(n, false));
    for (int i = 1; i < n - 1; i++) for (int j = 2; j < n - 2; j += 5) vec1[i][j] = true;
    for (int i = 1; i < n - 1; i++) vec1[i][n - 3] = true;
    for (int i = 0; i < n; i++)
    {
    	if (vec1[1][i] && !vec1[1][i + 1] && !vec1[1][i - 1])
    	{
    		vec1[1][i - 2] = true;
    		vec1[n - 2][i - 2] = true;
    	}
    }
    for (int i = 0; i < n - 4; i++)
    {
    	if (vec1[1][i] && vec1[1][i + 4] && ((i - 2) % 5))
    	{
    		vec1[1][i] = false;
    		vec1[n - 2][i] = false;
    	}
    }
    if (vec1[1][n - 4])
    {
        for (int i = 3; i < n - 4; i += 3)
        {
            vec1[i][n - 4] = false;
            vec1[i][n - 3] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < n; j++)
    	{
    	    if (vec1[i][j]) cout << "1 ";
    	    else cout << "0 ";
    	}
    	cout << "\n";
    }
}
