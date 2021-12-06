#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, a;
    cin >> n;
    vector <vector <int> > vec1;
    vector <int> tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = {};
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            tmp.emplace_back(a);
        }
        vec1.push_back(tmp);
    }
    vector <string> ans;
    for (int i = 0; i < n; i++)
    {
        if (vec1[i][0] == 1)
        {
            ans.emplace_back("R " + to_string(i + 1));
            for (int j = 0; j < n; j++)
            {
                if (vec1[i][j] == 1) vec1[i][j] = 0;
                else vec1[i][j] = 1;
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (vec1[0][j] == 1)
        {
            ans.emplace_back("C " + to_string(j + 1));
            for (int i = 0; i < n; i++)
            {
                if (vec1[i][j] == 1) vec1[i][j] = 0;
                else vec1[i][j] = 1;
            }
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vec1[i][j] == 1) s = 1;
        }
    }
    if (s == 1) cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for (auto a : ans) cout << a << endl;
    }
}
