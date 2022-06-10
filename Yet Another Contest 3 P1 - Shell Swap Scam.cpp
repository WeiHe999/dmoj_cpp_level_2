#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b, c, d, current, cur_back;
    cin >> n >> m >> a >> b;
    vector <pair <int, int> > vec1 = {{0, 0}};
    vector <int> vec2(m + 1), vec3(m + 1);
    vec2[0] = a;
    vec3.back() = b;
    current = a;
    for (int x = 1; x <= m; x++)
    {
        cin >> c;
        if (c != -1)
        {
            cin >> d;
            vec1.push_back({c, d});
            if (c == current)
            {
                vec2[x] = d;
                current = d;
            }
            else if (d == current)
            {
                vec2[x] = c;
                current = c;
            }
            else vec2[x] = current;
        }
        else
        {
            vec1.push_back({-1, -1});
            vec2[x] = 0;
        }
    }
    cur_back = b;
    for (int y = m - 1; y >= 0; y--)
    {
        if (cur_back == vec1[y + 1].second)
        {
            vec3[y] = vec1[y + 1].first;
            cur_back = vec1[y + 1].first;
        }
        else if (cur_back == vec1[y + 1].first)
        {
            vec3[y] = vec1[y + 1].second;
            cur_back = vec1[y + 1].second;
        }
        else vec3[y] = cur_back;
    }
    bool flag = true;
    for (int z = 1; z < vec2.size(); z++)
    {
        if (vec2[z] != 0)
        {
            cout << vec1[z].first << " " << vec1[z].second << "\n";
        }
        else
        {
            if (flag)
            {
                flag = false;
                if (vec2[z - 1] != vec3[z])
                {
                    cout << vec2[z - 1] << " " << vec3[z] << "\n";
                    continue;
                }
            }
            if (vec3[z] == 1) cout << 2 << " " << 3 << "\n";
            else if (vec3[z] == 2) cout << 1 << " " << 3 << "\n";
            else cout << 1 << " " << 2 << "\n";
        }
    }
}
