#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

void combinations(string s, string t, string &current, int ind1, int ind2, unordered_set <string> &s1)
{
    if (current.size() == s.size() + t.size())
    {
        if (!s1.count(current))
        {
            s1.insert(current);
            cout << current << endl;
        }
        return;
    }
    string str1 = current;
    if (ind1 < s.size())
    {
        str1 += s[ind1];
        combinations(s, t, str1, ind1 + 1, ind2, s1);
    }
    if (ind2 < t.size())
    {
        str1 = current;
        str1 += t[ind2];
        combinations(s, t, str1, ind1, ind2 + 1, s1);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s, t, current;
    cin >> s >> t;
    int ind1 = 0, ind2 = 0;
    unordered_set <string> s1;
    combinations(s, t, current, ind1, ind2, s1);
}
