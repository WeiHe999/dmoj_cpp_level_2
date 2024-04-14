#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    vector <pair <int, int> > vec1(p);
    for (int i = 0, a, b; i < p; i++)
    {
        cin >> a >> b;
        vec1[i] = {a, b};
    }
    vector <vector <int> > vec2(1001, vector <int>(1001, -1));
    int s = 0;
    auto walk_segment = [&](const pair<int, int>& start, const pair<int, int>& end)
    {
        int start_x = get<0>(start), start_y = get<1>(start);
        int end_x = get<0>(end), end_y = get<1>(end);
        int dif_x = end_x - start_x, dif_y = end_y - start_y;
        int dist = abs(dif_x) + abs(dif_y);
        int dir_x = dif_x / dist, dir_y = dif_y / dist;
        for (int _ = 0; _ < dist; ++_)
        {
            vec2[start_x][start_y] = s;
            s++;
            start_x += dir_x;
            start_y += dir_y;
        }
    };
    for (int i = 0; i < p; i++) walk_segment(vec1[i], vec1[(i + 1) % p]);
    for (int x = 0; x < n; x++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int p1 = vec2[x1][y1];
        int p2 = vec2[x2][y2];
        int dist = abs(p2 - p1);
        dist = min(dist, s - dist);
        cout << dist << endl;
    }
}
