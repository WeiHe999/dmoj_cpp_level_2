#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map <char, unordered_set <char> > m1, unordered_set <char> &visited, char start_node)
{
    visited.insert(start_node);
    for (auto x : m1[start_node])
    {
        if (!visited.count(x)) dfs(m1, visited, x);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    unordered_map <char, unordered_set <char> > m1, m2;
    vector <string> vec1;
    while (str1 != "**")
    {
        m1[str1[0]].insert(str1[1]);
        m1[str1[1]].insert(str1[0]);
        vec1.emplace_back(str1);
        cin >> str1;
    }
    int s = 0;
    for (auto a : vec1)
    {
        m2 = m1;
        m2[a[0]].erase(a[1]);
        m2[a[1]].erase(a[0]);
        unordered_set <char> visited;
        dfs(m2, visited, 'A');
        if (!visited.count('B'))
        {
            cout << a << "\n";
            s++;
        }
    }
    cout << "There are " << s << " disconnecting roads.\n";
}
