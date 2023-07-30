#include <bits/stdc++.h>
using namespace std;

long long n, s = 0;

void frisbee(vector <int> vec1)
{
    vector <int> vec2(n + 1);
    for (int i = 0; i < n; i++) vec2[vec1[i]] = i;
    set <int> s1;
    for (int i = n; i > 0; i--)
    {
        auto it = s1.insert(vec2[i]).first;
        if (next(it) != s1.end()) s += *next(it) - vec2[i] + 1;
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    vector <int> vec1(n);
    for (int i = 0; i < n; i++) cin >> vec1[i];
    frisbee(vec1);
    reverse(vec1.begin(), vec1.end());
    frisbee(vec1);
    cout << s << "\n";
}
