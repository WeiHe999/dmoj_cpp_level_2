#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int d, I, r;
    string str1, str2;
    cin >> d >> I >> r >> str1 >> str2;
    vector <vector <int> > memo(str1.size() + 1, vector <int>(str2.size() + 1));
    for (int i = 0; i <= str1.size(); i++)
    {
        for (int j = 0; j <= str2.size(); j++)
        {
            if (i == 0) memo[i][j] = j * I;
            else if (j == 0) memo[i][j] = i * d;
            else
            {
                if (str1[i - 1] == str2[j - 1]) memo[i][j] = memo[i - 1][j - 1];
                else memo[i][j] = min({memo[i - 1][j] + d, memo[i][j - 1] + I, memo[i - 1][j - 1] + r});
            }
        }
    }
    cout << memo[str1.size()][str2.size()] << "\n";
}
