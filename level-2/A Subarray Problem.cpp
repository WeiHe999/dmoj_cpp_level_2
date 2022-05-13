#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, max_ind = 0, min_ind = INT_MAX, len = 0, s = 0;
    cin >> n;
    unordered_map <int, int> index;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        index[a] = x + 1;
    }
    for (int y = 1; y <= n; y++)
    {
        max_ind = max(index[y], max_ind);
        min_ind = min(index[y], min_ind);
        len++;
        if (max_ind - min_ind + 1 <= len) s++;
    }
    cout << s << endl;
}
