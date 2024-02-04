#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b, c, d, s = 0;
    cin >> n >> m;
    vector <vector <int> > vec1;
    set <vector <int> > s1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> d;
        vec1.push_back({a, 0, b, d});
        vec1.push_back({c, 2, b, d});
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        vec1.push_back({a, 1, b, -1});
    }
    sort(vec1.begin(), vec1.end());
    for (auto x : vec1)
    {
        if (x[1] == 0) s1.insert({x[2], x[3]});
        else if (x[1] == 1)
        {
            bool flag = false;
            for (auto y : s1)
            {
                if (x[2] >= y[0] && x[2] <= y[1])
                {
                    flag = true;
                    break;
                }
            }
            if (flag) s++;
        }
        else s1.erase({x[2], x[3]});
    }
    cout << s << "\n";
}
