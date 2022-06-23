#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <int> vec1(n), vec2(n);
    vector <pair <int, int> > vec3;
    for (int x = 0; x < n; x++) cin >> vec1[x];
    for (int y = 0; y < n; y++)
    {
        cin >> vec2[y];
        vec3.push_back({vec2[y] - vec1[y], y});
    }
    sort(vec3.rbegin(), vec3.rend());
    int s = 0;
    for (int a = 0; a < vec3.size(); a++)
    {
        if (a < m)
        {
            s += vec2[vec3[a].second];
        }
        else
        {
            s += vec1[vec3[a].second];
        }
    }
    cout << s << "\n";
}
