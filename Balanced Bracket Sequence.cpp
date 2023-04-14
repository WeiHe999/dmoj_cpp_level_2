#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    vector <vector <int> > memo(str1.size() + 1, vector <int>(str1.size() + 1));
    for (int i = 1; i <= str1.size(); i++) memo[i][i] = 1;
    for (int k = 1; k <= str1.size() - 1; k++)
    {
        for (int i = 1; i <= str1.size() - k; i++)
        {
            int j = i + k;
            if (j == i + 1)
            {
                if ((str1[i - 1] == '[' && str1[j - 1] == ']') || (str1[i - 1] == '(' && str1[j - 1] == ')')) memo[i][j] = 0;
                else memo[i][j] = 2;
                continue;
            }
            if ((str1[i - 1] == '[' && str1[j - 1] == ']') || (str1[i - 1] == '(' && str1[j - 1] == ')')) 
            {
                memo[i][j] = memo[i + 1][j - 1];
            }
            else memo[i][j] = min(memo[i + 1][j], memo[i][j - 1]) + 1;
            for (int m = i + 1; m <= j; m++) memo[i][j] = min(memo[i][m - 1] + memo[m][j], memo[i][j]);
        }
    }
    cout << memo[1][str1.size()] << "\n";
}
