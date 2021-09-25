#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, b, ans, last_ind, ind;
    vector <int> now;
    vector <int> past;
    unordered_map <int, int> where;
    for (int x = 0; x < 10; x++)
    {
        now = {};
        past = {};
        where = {};
        cin >> n;
        for (int a = 0; a < n; a++)
        {
            cin >> b;
            where[b] = a;
            now.emplace_back(b);
        }
        ans = 0;
        last_ind = where[n];
        for (int c = n - 1; c > 0; c--)
        {
            ind = where[c];
            for (int d = 0; d < past.size(); d++) if (past[d] > ind) ind++;
            if (last_ind < ind)
            {
                now.insert(now.begin(), now[ind]);
                now.erase(now.begin() + ind + 1);
                past.emplace_back(ind);
                ans += ind;
                last_ind = 0;
            }
            else
            {
                last_ind = ind;
            }
        }
        cout << ans << endl;
    }
}
