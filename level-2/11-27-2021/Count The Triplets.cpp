#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    set <int> s1;
    set <vector <int> > s2;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        s1.insert(a);
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = i + 1; j < vec1.size(); j++)
        {
            if (s1.count(vec1[i] + vec1[j]))
            {
                s2.insert({vec1[i], vec1[j], vec1[i] + vec1[j]});
            }
        }
    }
    if (s2.size() == 0) cout << -1 << endl;
    else cout << s2.size() << endl;
}
