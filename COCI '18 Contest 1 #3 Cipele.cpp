#include <bits/stdc++.h>
using namespace std;

bool check(vector <int> left, vector <int> right, int mid)
{
    int pt1 = 0, pt2 = 0, cnt = 0;
    while (pt1 < left.size() && pt2 < right.size())
    {
        if (abs(right[pt2] - left[pt1]) <= mid)
        {
            cnt++;
            pt1++;
            pt2++;
        }
        else if (right[pt2] > left[pt1]) pt1++;
        else pt2++;
    }
    if (cnt == left.size() || cnt == right.size()) return true;
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, ans = INT_MAX;
    cin >> n >> m;
    vector <int> left(n), right(m);
    for (int x = 0; x < n; x++) cin >> left[x];
    for (int x = 0; x < m; x++) cin >> right[x];
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    int low = 0, high = max(right.back() - left[0], left.back() - right[0]), mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (check(left, right, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans << "\n";
}
