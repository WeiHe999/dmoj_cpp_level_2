#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a;
    long long s = 0;
    cin >> n;
    vector <long long> vec1, vec2, vec3, vec_psa = {0};
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec2.emplace_back(a);
    }
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec3.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    sort(vec3.begin(), vec3.end());
    for (long long i = 0; i < n; i++) vec_psa.emplace_back(n - (upper_bound(vec3.begin(), vec3.end(), vec2[i]) - vec3.begin()) + vec_psa[i]);
    for (long long b = 0; b < n; b++)
    {
        long long ind = upper_bound(vec2.begin(), vec2.end(), vec1[b]) - vec2.begin();
        if (ind < vec2.size()) s += vec_psa.back() - vec_psa[ind];
    }
    cout << s << endl;
}
