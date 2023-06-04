#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int k, a, n = 0;
    cin >> k;
    vector <int> lights;
    vector <vector <int> > group;
    for (int i = 1; i <= k; i++)
    {
        cin >> a;
        lights.emplace_back(a);
    }
    group.push_back({0, 0});
    for (int i = 0; i < k; i++)
    {
        if (lights[i] == 1)
        {
            if (group[n][1] == 0)
            {
                group[n][0] = i;
                group[n][1] = i;
            }
            group[n][1]++;
        }
        else if (group[n][1] != 0)
        {
            n++;
            group.push_back({0, 0});
        }
    }
    if (group[n][1] == 0)
    {
        n--;
        group.pop_back();
    }
    n++;
    vector <int> min_switches(n + 1);
    int s = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        min_switches[i] = 1e9;
        int num = 0, j = i;
        while (j < n && (group[j][1] - group[i][0]) <= 7)
        {
            num += group[j][1] - group[j][0];
            int size = max(4, group[j][1] - group[i][0]), t = size - num;
            if (size == 6 && lights[group[i][0] + 2] == 1 && lights[group[i][0] + 3] == 1) t = 1e9;
            else if (size == 7 && lights[group[i][0] + 3] == 1) t = 1e9;
            min_switches[i] = min(t + min_switches[j + 1], min_switches[i]);
            j++;
        }
    }
    cout << min_switches[0] << "\n";
}
