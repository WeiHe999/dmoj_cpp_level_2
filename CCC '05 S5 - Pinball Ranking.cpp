#include <bits/stdc++.h>
using namespace std;

vector <long long> bit(1e5 + 1);

void update(long long ind)
{
    for (long long i = ind; i <= 1e5; i += (i & -i)) bit[i]++;
}

long long query(long long ind)
{
    long long s = 0;
    for (long long i = ind; i >= 1; i -= (i & -i)) s += bit[i];
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, s = 0;
    cin >> n;
    vector <pair <int, int> > vec1;
    unordered_map <int, int> m1, m2;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a;
        vec1.push_back({a, i});
    }
    sort(vec1.begin(), vec1.end());
    for (int i = 1; i <= n; i++) m1[vec1[i - 1].second] = i;
    for (long long i = 1; i <= n; i++)
    {
        update(m1[i]);
        s += i - query(m1[i]) + 1;
    }
    cout << fixed << setprecision(2) << s / (n * 1.0) << "\n";
}
