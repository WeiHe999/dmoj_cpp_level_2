#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, str2 = "abcdefghijklmnopqrstuvwxyz";
    cin >> str1;
    vector <vector <int> > memo(str1.size() + 1, vector <int>(str2.size() + 1));
    for (int i = 1; i <= str1.size(); i++) memo[i][0] = 0;
    for (int i = 1; i <= str2.size(); i++) memo[0][i] = i;
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i - 1] == str2[j - 1]) memo[i][j] = memo[i - 1][j - 1];
            else memo[i][j] = min(memo[i - 1][j], memo[i][j - 1] + 1);
        }
    }
    cout << memo[str1.size()][str2.size()] << "\n";
}
