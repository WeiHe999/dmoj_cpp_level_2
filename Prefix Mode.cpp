#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n;
    cin >> n;
    vector <long long> vec1(n + 1);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    vector <pair <long long, long long> > vec2(n + 1);
    for (long long i = 1; i <= n; i++) vec2[i] = {vec1[i], i};
    sort(vec2.begin(), vec2.end());
    long long k = n, ind = 1, s = 0, m = n;
    while (k > 0)
    {
        s += (vec2[ind].first - vec2[ind - 1].first) * m * k;
        m--;
        vec1[vec2[ind].second] = 0;
        ind++;
        while (vec2[ind] == vec2[ind - 1])
        {
            vec1[vec2[ind].second] = 0;
            ind++;
        }
        while (!vec1[k]) k--;
    }
    cout << s << "\n";
}
