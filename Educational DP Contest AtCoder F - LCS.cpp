#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, str2, output;
    cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    vector <vector <int> > memo(n + 1, vector <int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1]) memo[i][j] = memo[i - 1][j - 1] + 1;
            else memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
        }
    }
    int ind1 = n, ind2 = m;
    while (ind1 != 0 && ind2 != 0)
    {
        if (memo[ind1 - 1][ind2] == memo[ind1][ind2]) ind1--;
        else if (memo[ind1][ind2 - 1] == memo[ind1][ind2]) ind2--;
        else
        {
            output += str1[ind1 - 1];
            ind1--;
            ind2--;
        }
    }
    reverse(output.begin(), output.end());
    cout << output << "\n";
}
