#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int k;
    cin >> k;
    for (int t = 1; t <= k; t++)
    {
        int r, c, left, right, s = 0;
        cin >> r >> c;
        vector <vector <char> > grid(r + 1, vector <char>(c + 1));
        for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> grid[i][j];
        vector <int> histogram(c + 2);
        histogram[c + 1] = -1;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (grid[i][j] == 'R') histogram[j] = 0;
                else histogram[j]++;
            }
            stack <pair <int, int> > s1;
            for (int j = 1; j <= c + 1; j++)
            {
                while (!s1.empty() && s1.top().first >= histogram[j])
                {
                    pair <int, int> cur = s1.top();
                    s1.pop();
                    if (s1.empty()) left = 0;
                    else left = s1.top().second;
                    right = j;
                    s = max((right - left - 1) * cur.first, s);
                }
                s1.push({histogram[j], j});
            }
        }
        cout << 3 * s << "\n";
    }
}
