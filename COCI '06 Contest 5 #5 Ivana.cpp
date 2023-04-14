#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0, odds = 0;
    cin >> n;
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        vec1[i] %= 2;
        if (vec1[i] == 1) odds++;
    }
    n--;
    for (int ind = 1; ind <= n + 1; ind++)
    {
        vector <int> vec2 = {0};
        for (int j = ind + 1; j <= n + 1; j++) vec2.emplace_back(vec1[j]);
        for (int j = 1; j <= ind - 1; j++) vec2.emplace_back(vec1[j]);
        vector <vector <int> > memo(n + 1, vector <int>(n + 1));
        for (int i = 1; i <= n; i++) memo[i][i] = vec2[i];
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n - k; i++)
            {
                int j = i + k;
                if (i + 1 == j) memo[i][j] = max(vec2[i], vec2[j]);
                else memo[i][j] = max(vec2[i] + min(memo[i + 2][j], memo[i + 1][j - 1]), vec2[j] + min(memo[i][j - 2], memo[i + 1][j - 1]));
            }
        }
        if (memo[1][n] < odds - memo[1][n] + vec1[ind]) s++;
    }
    cout << s << "\n";
}
