#include <bits/stdc++.h>
using namespace std;

void window(vector <int> vec1, int n, vector <int> &vec2_max, vector <int> &vec2_min)
{
    deque <pair <int, int> > q1, q2;
    for (int j = 0; j < n - 1; j++)
    {
        while (!q1.empty() && q1.back().first <= vec1[j]) q1.pop_back();
        while (!q2.empty() && q2.back().first >= vec1[j]) q2.pop_back();
        q1.push_back({vec1[j], j});
        q2.push_back({vec1[j], j});
    }
    for (int j = 0; j + n - 1 < vec1.size(); j++)
    {
        int k = j + n - 1;
        while (!q1.empty() && q1.back().first <= vec1[k]) q1.pop_back();
        while (!q2.empty() && q2.back().first >= vec1[k]) q2.pop_back();
        q1.push_back({vec1[k], k});
        q2.push_back({vec1[k], k});
        if (q1.front().second < j) q1.pop_front();
        if (q2.front().second < j) q2.pop_front();
        vec2_max.emplace_back(q1.front().first);
        vec2_min.emplace_back(q2.front().first);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int h, w, n, s = INT_MAX;
    cin >> h >> w >> n;
    vector <vector <int> > vec1(h, vector <int>(w)), vec2_max, vec2_min, vec2, vec3_max, vec3_min;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> vec1[i][j];
    for (int i = 0; i < h; i++)
    {
        vector <int> max1, min1;
        window(vec1[i], n, max1, min1);
        vec2_max.push_back(max1);
        vec2_min.push_back(min1);
    }
    for (int col = 0; col < vec2_max[0].size(); col++)
    {
        vector <int> tmp1, tmp2, tmp1_max, tmp2_max, tmp1_min, tmp2_min;
        for (int row = 0; row < vec2_max.size(); row++)
        {
            tmp1.emplace_back(vec2_max[row][col]);
            tmp2.emplace_back(vec2_min[row][col]);
        }
        window(tmp1, n, tmp1_max, tmp1_min);
        vec3_max.push_back(tmp1_max);
        window(tmp2, n, tmp2_max, tmp2_min);
        vec3_min.push_back(tmp2_min);
    }
    for (int i = 0; i < vec3_max.size(); i++) for (int j = 0; j < vec3_max[0].size(); j++) s = min(vec3_max[i][j] - vec3_min[i][j], s); 
    cout << s << "\n";
}
