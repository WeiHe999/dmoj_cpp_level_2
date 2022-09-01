#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, max_sum = 0;
    string a;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        int sum = 0;
        for (auto b : a) if ((b - '0') % 2 == 1) sum += (b - '0');
        max_sum = max(sum, max_sum);
    }
    cout << max_sum << "\n";
}
