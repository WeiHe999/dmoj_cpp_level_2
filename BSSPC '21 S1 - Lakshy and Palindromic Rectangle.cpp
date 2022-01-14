#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, b;
    cin >> n >> m;
    vector <vector <char> > vec1(n, vector <char>(m));
    for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) cin >> vec1[x][y];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec1[i][m - j - 1] != '.'  && vec1[i][j] != '.' && vec1[i][m - j - 1] != vec1[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
            if (vec1[n - i - 1][j] != '.'  && vec1[i][j] != '.' && vec1[n - i - 1][j] != vec1[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
            if (vec1[i][m - j - 1] == '.' && vec1[i][j] != '.') 
            {
                vec1[i][m - j - 1] = vec1[i][j];
            }
            if (vec1[n - i - 1][j] == '.' && vec1[i][j] != '.')
            {
                vec1[n - i - 1][j] = vec1[i][j];
            }
        }
    }
    
 
    
    //fill remaining dots
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec1[i][j] == '.')
            {
                //row-wise
                char row_match = vec1[i][m - j - 1];
                char col_match = vec1[n - i - 1][j];
                if (row_match=='.' && col_match=='.') vec1[i][j] = 'a';
                else if (row_match=='.') vec1[i][j] = col_match;
                else if (col_match=='.') vec1[i][j] = row_match;
                else
                {
                    vec1[i][j] = row_match;
                }
            }
            
        }
    }
    for (auto a : vec1)
    {
        for (auto b : a) cout << b;
        cout << endl;
    }
}
