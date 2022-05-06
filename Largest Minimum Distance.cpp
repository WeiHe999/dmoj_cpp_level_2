#include <bits/stdc++.h>
using namespace std;

bool check(vector <int> vec1, int m, int s)
{
    int index = 0;
    int minimum = vec1[index];
    bool flag = true;
    for (int x = 1; x < m; x++)
    {
        minimum += s;
        index = lower_bound(vec1.begin(), vec1.end(), minimum) - vec1.begin();
        if (index == vec1.size())
        {
            flag = false;
            break;
        }
        minimum = vec1[index];
    }
    if (flag) return true;
    else return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int left = 1, right = INT_MIN, mid, n, m, a, ans = 1;
    cin >> n >> m;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        right = max(a, right);
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (check(vec1, m, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << endl;
}
