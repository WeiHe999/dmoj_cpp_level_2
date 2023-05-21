#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    cin >> n;
    vector <long long> vec1(2 * n + 2), vec2(2 * n + 2);
    for (long long i = 1; i <= 2 * n + 1; i++)
    {
        cin >> vec1[i];
        s ^= vec1[i];
    }
    for (long long i = 1; i <= 2 * n + 1; i++)
    {
        cin >> vec2[i];
        s ^= vec2[i];
    }
    sort(vec2.begin(), vec2.end());
    for (long long i = 1; i <= 2 * n + 1; i++) vec1[i] ^= s;
    sort(vec1.begin(), vec1.end());
    bool flag = true;
    for (long long i = 1; i <= 2 * n + 1; i++)
    {
        if (vec1[i] != vec2[i])
        {
            flag = false;
            break;
        }
    }
    if (flag) cout << s << "\n";
    else cout << "-1\n";
}
