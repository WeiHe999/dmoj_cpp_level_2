#include <bits/stdc++.h>
using namespace std;

long long get_score(unordered_map <char, long long> m1, unordered_map <char, long long> m2)
{
    long long ss = 0;
    for (auto x : m2) 
    {
        if (m1.count(x.first)) ss += (m1[x.first] * x.second);
    }
    return ss;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long s, t, cnt = 0;
    string a, b;
    cin >> s >> t; cin.ignore();
    getline(cin, a);
    getline(cin, b);
    unordered_map <char, long long> m1, m2, m3;
    for (auto c : a) m1[c]++;
    for (auto d : b)
    {
        m2[d]++;
    }
    long long maxa = LLONG_MIN;
    char maxc;
    for (auto e : m1)
    {
        if (e.second > maxa)
        {
            maxa = e.second;
            maxc = e.first;
        }
    }
    cnt = get_score(m1, m2);
    for (auto f : m2)
    {
        m3 = m2;
        m3[maxc]++;
        m3[f.first]--;
        long long score = get_score(m1, m3);
        if (score > cnt)
        {
            cnt = score;
        }
    }
    cout << cnt << endl;
}
