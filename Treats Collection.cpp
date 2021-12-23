#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, a, min = LLONG_MAX, s;
    cin >> n >> k;
    vector <long long> vec1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (long long i = 0; i <= n - k; i++)
    {
        if (vec1[i] < 0 && vec1[i + k - 1] > 0)
        {
            if (vec1[i + k - 1] > abs(vec1[i])) s = (2 * abs(vec1[i])) + vec1[i + k - 1];
            else s = (2 * vec1[i + k - 1]) + abs(vec1[i]);
        }
        else if (vec1[i] < 0)
        {
            s = abs(vec1[i]);
        }
        else
        {
            s = vec1[i + k - 1];
        }
        if (s < min) min = s;
    }
    cout << min << endl;
}
