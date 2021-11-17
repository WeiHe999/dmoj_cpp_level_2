#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t, n, a, s = 0, prev = 0, c = 0;
    cin >> t >> n;
    vector <pair <long long, long long> > vec1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.push_back({abs(a), a});
    }
    sort(vec1.begin(), vec1.end());
    for (long long x = 0; x < vec1.size(); x++)
    {
        if (s + abs(prev - vec1[x].second) > t) break;
        s += abs(prev - vec1[x].second);
        c++;
        prev = vec1[x].second;
    }
    cout << c << endl;
}
