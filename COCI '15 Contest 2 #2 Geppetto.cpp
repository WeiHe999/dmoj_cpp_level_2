#include <bits/stdc++.h>
using namespace std;

int counter(int x, int n, vector <vector <int> > vec1, vector <int> vec2)
{
    if (x == n) return 1;
    int tmp = counter(x + 1, n, vec1, vec2);
    bool flag = 1;
    for (auto y : vec1[x]) if (vec2[y]) flag = 0;
    if (flag)
    {
        vec2[x] = 1;
        tmp += counter(x + 1, n, vec1, vec2);
        vec2[x] = 0;
    }
    return tmp;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    vector <vector <int> > vec1(21);
    vector <int> vec2(21);
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        vec1[x - 1].emplace_back(y - 1);
        vec1[y - 1].emplace_back(x - 1);
    }
    cout << counter(0, n, vec1, vec2) << endl;
}
