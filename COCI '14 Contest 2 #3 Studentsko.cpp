#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a, s = 0;
    cin >> n >> k;
    vector <int> vec1(n + 1), memo(n + 1);
    vector <pair <int, int> > vec2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        vec2[i] = {a, i};
    }
    sort(vec2.begin(), vec2.end());
    for (int i = 1; i <= n; i++) vec1[vec2[i].second] = (i - 1) / k;
    for (int i = 1; i <= n; i++)
    {
        memo[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (vec1[i] >= vec1[j]) memo[i] = max(memo[j] + 1, memo[i]);
        }
    }
    for (int i = 1; i <= n; i++) s = max(memo[i], s);
    cout << n - s << "\n";
}
