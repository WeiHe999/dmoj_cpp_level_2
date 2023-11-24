#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    string a;
    cin >> n; cin.ignore();
    getline(cin, a);
    vector <long long> vec_i, vec_u, vec1, vec2;
    for (long long b = 0; b < a.size(); b++)
    {
        if (a[b] == 'I') 
        {
            vec_i.emplace_back(b);
            vec1.emplace_back(1);
        }
        else
        {
            vec_u.emplace_back(b);
            vec1.emplace_back(0);
        }
    }
    for (long long d = 0; d < vec1.size(); d++)
    {
        if (d == 0) vec2.emplace_back(vec1[d]);
        else vec2.emplace_back(vec2[d - 1] + vec1[d]);
    }
    for (long long c = 0; c < vec_i.size(); c++)
    {
        if (vec_i[c] < vec_u[c]) s += vec2[vec_u[c]] - vec2[vec_i[c]];
        else s += vec2[vec_i[c]] - vec2[vec_u[c]];
    }
    cout << s << endl;
}
