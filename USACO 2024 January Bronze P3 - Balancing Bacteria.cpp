#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0;
    cin >> n;
    vector <int> vec1(n), vec2(n);
    for (int i = 0; i < n; i++) cin >> vec1[i];
    for (int i = 0; i < n; i++)
    {
        vec2[i] = vec1[i];
        if (i > 0) vec2[i] -= vec1[i - 1];
    }
    vec1 = vec2;
    for (int i = 0; i < n; i++)
    {
        vec2[i] = vec1[i];
        if (i > 0) vec2[i] -= vec1[i - 1];
    }
    vec1 = vec2;
    for (int i = 0; i < n; i++) s += abs(vec1[i]);
    cout << s << "\n";
}
