#include <bits/stdc++.h>
using namespace std;
int dif[10000001], l, r, N, ans;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> l >> r;
        dif[l] += 1;
        dif[r] -= 1;
    }
    for (int i = 1; i <= 1e7; ++i) {
        dif[i] += dif[i - 1];
        ans = max(ans, dif[i]);
    }
    cout << ans << "\n";
    return 0;
}
