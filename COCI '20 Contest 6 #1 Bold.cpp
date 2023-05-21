#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <vector <char> > vec1(n + 1, vector <char>(m + 1, '.')), vec2(n + 1, vector <char>(m + 1, '.'));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> vec1[i][j];
            if (vec1[i - 1][j - 1] == '#')
            {
                vec2[i - 1][j - 1] = '#';
                vec2[i - 1][j] = '#';
                vec2[i][j - 1] = '#';
                vec2[i][j] = '#';
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << vec2[i][j];
        cout << "\n";
    }
}
