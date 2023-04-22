#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, q, a, b, s = 0;
    cin >> n;
    vector <long long> vec1(n + 1), psa = {0};
    unordered_map <long long, long long> m1, m2;
    for (long long i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        m1[i] = vec1[i];
    }
    sort(vec1.begin(), vec1.end());
    for (long long i = 1; i <= n; i++)
    {
        psa.emplace_back(vec1[i] + psa.back());
        s += i * vec1[i];
        m2[vec1[i]] = i;
    }
    cin >> q;
    for (long long i = 1; i <= q; i++)
    {
        cin >> a >> b;
        long long ind = upper_bound(vec1.begin(), vec1.end(), b) - vec1.begin();
        if (ind > m2[m1[a]]) ind--;
        long long sum = s + ind * b - m2[m1[a]] * m1[a];

        if (m2[m1[a]] >= ind) 
        {
            sum += psa[m2[m1[a]] - 1] - psa[ind - 1];
        }
        else sum += psa[m2[m1[a]]] - psa[ind];
        cout << sum << "\n";
    }
}
