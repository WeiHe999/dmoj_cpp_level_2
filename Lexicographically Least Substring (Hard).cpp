#include <bits/stdc++.h>
using namespace std;

long long base = 131, mod = 1e9+7, MM=1e6+7;
vector <long long> hash1(MM), power(MM);

long long search(long long ind1, long long ind2, long long k)
{
    long long l1 = ind1, r1 = l1 + k - 1, l2 = ind2, r2 = l2 + k - 1, m1, m2, ans = LLONG_MAX;
    while (l1 <= r1 && l2 <= r2)
    {
        m1 = (l1 + r1) / 2;
        m2 = (l2 + r2) / 2;
        if (((hash1[m1] - hash1[l1 - 1] * power[m1 - l1 + 1]) % mod + mod) % mod == ((hash1[m2] - hash1[l2 - 1] * power[m2 - l2 + 1]) % mod + mod) % mod)
        {
            l1 = m1 + 1;
            l2 = m2 + 1;
        }
        else
        {
            ans = min(m1 - ind1, ans);
            r1 = m1 - 1;
            r2 = m2 - 1;
        }
    }
    return ans;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, best;
    long long k, ind1 = 1;
    cin >> str1 >> k;
    if (k>=str1.size())
    {
        cout << str1 << endl;
        return 0;
    }
    power[0] = 1;
    map <char, vector <long long> > map1;
    for (int i = 0; i + k <= str1.size(); i++)
    {
        map1[str1[i]].emplace_back(i + 1);
    }
    for (long long i = 1; i <= str1.size(); i++)
    {
        hash1[i] = ((hash1[i - 1] * base + (str1[i - 1] - 'a')) % mod + mod) % mod;
        power[i] = ((power[i - 1] * base) % mod + mod) % mod;
    }
    vector <long long> v1 = map1.begin()->second;
    ind1 = v1.front();
    for (auto i: v1)
    {
        if (i==ind1) continue;
        long long offset = search(ind1, i, k);
        if (offset==LLONG_MAX) continue;
        if (str1[ind1 + offset-1 ] > str1[i + offset-1 ]) 
        {
            ind1 = i;
        }
    }
    cout << str1.substr(ind1 - 1, k) << "\n";
}
