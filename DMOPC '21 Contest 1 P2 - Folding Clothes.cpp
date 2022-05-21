#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1(n), stk, ans;
    for (int x = 0; x < n; x++) cin >> vec1[x];
    stk.emplace_back(vec1[0]);
    ans.emplace_back(1);
    for (int i = 1; i < n; i++)
    {
        int p = lower_bound(stk.begin(), stk.end(), vec1[i]) - stk.begin();
        if (p > 0)
        {
            ans.emplace_back(-p);
        }
        ans.emplace_back(p + 1);
        stk.insert(stk.begin() + p, vec1[i]);
    }
    ans.emplace_back(-n);
    cout << ans.size() << "\n";
    for (auto b : ans) cout << b << "\n";
}
