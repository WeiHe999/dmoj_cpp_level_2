#include <bits/stdc++.h>
using namespace std;

vector <int> bit(1000001, -1), vec1(100000), dp(100000);

void update(int ind, int val)
{
    for (int i = ind; i <= 1000000; i += (i & -i)) if (bit[i] == -1 || dp[val] > dp[bit[i]] ) bit[i] = val;
}

int query(int ind)
{
    int s = -1;
    for (int i = ind; i > 0; i -= (i & -i)) if (bit[i] != -1 && (s == -1 || dp[bit[i]] > dp[s])) s = bit[i];
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    vector <pair <int, int> > intervals;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    sort(intervals.begin(), intervals.end(), [](pair <int, int> a, pair <int, int> b){if (a.first != b.first) return a.first > b.first;
    else if (a.second != b.second) return a.second < b.second; else return false;});
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        vec1[i] = -1;
        int x = query(intervals[i].second);
        if (x != -1)
        {
            dp[i] = dp[x] + 1;
            vec1[i] = x;
        }
        update(intervals[i].second, i);
        if (dp[i] > dp[s]) s = i;
    }
    cout << dp[s] << "\n";
    while (s != -1)
    {
        cout << intervals[s].first << " " << intervals[s].second << "\n";
        s = vec1[s];
    }
}
