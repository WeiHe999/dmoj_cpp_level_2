#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, q, a;
    cin >> m >> q;
    string str1;
    vector <vector <int> > dp(q + 1, vector <int>(m + 1));
    vector <int> vec1(q + 1);
    vector <pair <string, int> > names(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> str1 >> a;
        names[i] = {str1, a};
    }
    for (int i = 1; i <= q; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j == 1)
            {
                dp[i][j] = dp[i - 1][1] + names[i].second;
                vec1[i] = 1;
                continue;
            }
            int s1 = names[i].second, s = INT_MAX;
            for (int k = 1; k <= j && i - k + 1 >= 1; k++)
            {
                s1 = max(names[i - k + 1].second, s1);
                if (dp[i - k][j] + s1 < s)
                {
                    s = dp[i - k][j] + s1;
                    vec1[i] = k;
                }
            }
            dp[i][j] = s;
        }
    }
    stack <string> stack1;
    int n = vec1[q], p = q;
    while (p > 0)
    {
        string tmp = names[p].first;
        for (int i = 1; i < n; i++) tmp = names[p - i].first + " " + tmp;
        p -= n;
        stack1.push(tmp);
        if (p > 0) n = vec1[p];
    }
    cout << "Total Time: " << dp[q][m] << "\n";
    while (!stack1.empty())
    {
        cout << stack1.top() << "\n";
        stack1.pop();
    }
}
