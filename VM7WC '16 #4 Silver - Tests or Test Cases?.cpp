#include <bits/stdc++.h>
using namespace std;

void generate_words(string prefix, int current_len, int total_len, int current_level, unordered_map <int, vector <char> > m1, int max_levels, vector <string> &vec1)
{
    if (current_len > total_len) return;
    for (int x = current_level + 1; x <= max_levels; x++)
    {
        for (auto y : m1[x])
        {
            string str1 = prefix;
            str1 += y;
            int new_len = current_len + 1;
            if (new_len <= total_len) vec1.emplace_back(str1);
            generate_words(str1, new_len, total_len, x, m1, max_levels, vec1);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, l, m;
    char a;
    cin >> n >> l;
    unordered_map <int, vector <char> > m1;
    for (int x = 0; x < n; x++)
    {
        cin >> m;
        for (int y = 0; y < m; y++)
        {
            cin >> a;
            m1[x + 1].emplace_back(a);
        }
    }
    vector <string> vec1;
    for (auto c : m1[1])
    {
        string str1;
        vec1.emplace_back(str1 + c);
        generate_words(str1 + c, 1, l, 1, m1, n, vec1);
    }
    sort(vec1.begin(), vec1.end());
    for (auto c : vec1) cout << c << endl;
    // for (auto b : m1)
    // {
    //     cout << b.first << ": ";
    //     for (auto c : b.second) cout << c << " ";
    //     cout << endl;
    // }
}
