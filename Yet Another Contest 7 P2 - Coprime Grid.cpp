#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        int n, m, cnt = 2;
        cin >> n >> m;
        if (n == 1 || m == 1)
        {
            cout << "-1\n";
            continue;
        }
        vector <vector <int> > vec1(n + 1, vector <int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 1)
            {
                for (int j = 1; j <= m; j++)
                {
                    vec1[i][j] = cnt;
                    cnt++;
                }
            }
            else
            {
                for (int j = m; j >= 1; j--)
                {
                    vec1[i][j] = cnt;
                    cnt++;
                }
            }
        }
        vec1[n][m] = 1;
        if (n%2==0)
        {
            vec1[n][m] = vec1[n][m-1] - 1;
            vec1[n][1] = 1;
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) cout << vec1[i][j] << " ";
            cout << "\n";
        }
    }
}
