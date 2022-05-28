#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector <int> vec1, vec2;

bool check(int mid)
{
    int len = 0;
    for (int i = 0, j = 0; i < m; i++)
    {
        while (j < n && vec1[j] >= vec2[i] && vec1[j] - k <= vec2[i] && len < mid)
        {
            j++;
            len++;
        }
        len = 0;
        if (j == n) return true;
    }
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    int l = 1, r = n, a, ans = -1, mid;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (int x = 0; x < m; x++)
    {
        cin >> a;
        vec2.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << "\n";
}
