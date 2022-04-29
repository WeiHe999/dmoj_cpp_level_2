#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s;
    int n, a, b, num_c, num_o, num_w;
    cin >> s >> n;
    vector <int> vec_c = {0}, vec_o = {0}, vec_w = {0};
    for (auto c : s)
    {
        if (c == 'C') vec_c.emplace_back(vec_c.back() + 1);
        else vec_c.emplace_back(vec_c.back());
        if (c == 'O') vec_o.emplace_back(vec_o.back() + 1);
        else vec_o.emplace_back(vec_o.back());
        if (c == 'W') vec_w.emplace_back(vec_w.back() + 1);
        else vec_w.emplace_back(vec_w.back());
    }
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        num_c = (vec_c[b] - vec_c[a - 1]) % 2;
        num_o = (vec_o[b] - vec_o[a - 1]) % 2;
        num_w = (vec_w[b] - vec_w[a - 1]) % 2;
        if (num_c == 1 && num_o == 0 && num_w == 0) cout << "Y";
        else if (num_c == 0 && num_o == 1 && num_w == 1) cout << "Y";
        else cout << "N";
    }
    cout << endl;
}
