#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, start, end;
    long long k;
    cin >> n >> k;
    vector <vector <int> > blame(n + 1, vector <int>(n + 1));
    for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) cin >> blame[x + 1][y + 1];
    set <pair <int, int> > s1 = {{1, 2}};
    vector <int> vec1 = {1, 2};
    int prev = 1, cur = 2;
    while (true)
    {
        int tmp = cur;
        cur = blame[cur][prev];
        prev = tmp;
        vec1.emplace_back(cur);
        if (s1.count({prev, cur})) break;
        s1.insert({prev, cur});
    }
    end = vec1.size() - 2;
    pair <int, int> find = {vec1[vec1.size() - 2], vec1[vec1.size() - 1]};
    for (int x = 0; x < vec1.size() - 1; x++)
    {
        if (vec1[x] == find.first && vec1[x + 1] == find.second)
        {
            start = x + 1;
            break;
        }
    }
    if (k <= (long long)start) cout << vec1[(int)k - 1] << "\n";
    else
    {
        k -= (long long)start;
        k %= (long long)(end - start + 1);
        cout << vec1[start + (int)k - 1] << "\n";
    }
}
