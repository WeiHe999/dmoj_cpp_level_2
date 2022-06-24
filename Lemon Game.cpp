#include <bits/stdc++.h>
using namespace std;

map <pair <int, int>, int> memo;

int dp(int s1, int s2, map <pair <int, int>, int> &memo)
{
    if (memo.count({s1, s2})) return memo[{s1, s2}];
    if (s1 % s2 == 0)
    {
        memo[{s1, s2}] = 1;
        return 1;
    }
    bool flag = false;
    for (int x=s1 / s2 * s2; x >= s2; x -= s2)
    {
        if (s1 - x > s2)
        {
            if (dp(s1 - x, s2, memo) % 2 == 0)
            {
                flag = true;
                break;
            }
        }
        else
        {
            if (dp(s2, s1 - x, memo) % 2 == 0)
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
    {
        memo[{s1, s2}] = 1;
        return 1;
    }
    else
    {
        memo[{s1, s2}] = 2;
        return 2;
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int q;
    cin >> q;
    for (int x = 0; x < q; x++)
    {
        int a, b;
        cin >> a >> b;
        if (dp(a, b, memo) % 2 == 0) cout << "Bob Win\n";
        else cout << "Alice Win\n";
    }
}
