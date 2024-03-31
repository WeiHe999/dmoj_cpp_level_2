#include <bits/stdc++.h>
using namespace std;

int m, n, a;
vector <int> vec1(1001), vec2(1001), inp = {0};

bool check()
{
    int s1 = 0, s2 = 0;
    if (vec1[m] > 0) return false;
    for (int i = m - 1; i >= 1; i--)
    {
        s1 += vec1[i], s2 += vec2[i + 1];
        if (s1 > s2) return false;
    }
    return true;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        cin >> a;
        vec1[a]++;
        inp.emplace_back(a);
    }
    for (int i = 1; i <= n / 2; i++)
    {
        cin >> a;
        vec2[a]++;
        inp.emplace_back(a);
    }
    if (n % 2 == 1)
    {
        cin >> a;
        inp.emplace_back(a);
    }
    for (int i = n / 2; i >= 1; i--)
    {
        if (check())
        {
            cout << i << "\n";
            return 0;
        }
        vec1[inp[i]]--;
        vec2[inp[i]]++;
        vec2[inp[2 * i]]--;
        vec2[inp[2 * i - 1]]--;
    }
    cout << "0\n";
}
