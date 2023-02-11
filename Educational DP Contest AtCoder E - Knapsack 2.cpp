#include <bits/stdc++.h>
using namespace std;

const int MM = 1e9;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, w, a, b, val = 0;
    vector <int> vec1, vec2;
    cin >> n >> w;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        vec1.emplace_back(a);
        vec2.emplace_back(b);
        val += b;
    }
    vector <int> memo(val + 1, MM);
    memo[0] = 0;
    for (int i = 0; i < n; i++)
    {
        vector <pair <int, int> > vec3;
        for (int j = 0; j <= val; j++)
        {
            if (vec2[i] + j <= val && memo[j] < MM) vec3.push_back({vec2[i] + j, min(memo[vec2[i] + j], memo[j] + vec1[i])});
        }
        for (auto x : vec3) memo[x.first] = x.second;
    }
    for (int x = val; x >= 0; x--)
    {
        if (memo[x] <= w)
        {
            cout << x << "\n";
            break;
        }
    }
}
