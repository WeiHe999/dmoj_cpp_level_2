#include <bits/stdc++.h>
using namespace std;
int n, m, lo, hi, arr[100005];
long long mid, ans;
bool check(long long x) {
    int count = 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + arr[i] <= x) sum += arr[i];
        else {
            count++;
            sum = arr[i];
        }
    }
    return count <= m;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}
