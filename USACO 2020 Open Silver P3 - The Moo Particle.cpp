#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 1;
    cin >> n;
    vector <int> vec1(n), vec2(n), min_l(n), max_r(n);
    vector <vector <int> > vec3;
    for (int i = 0; i < n; i++)
    {
        cin >> vec1[i] >> vec2[i];
        vec3.push_back({vec1[i], vec2[i], i});
    }
    sort(vec3.begin(), vec3.end());
    min_l[0] = vec2[vec3[0][2]];
    for (int i = 1; i < n; i++) min_l[i] = min(min_l[i - 1], vec2[vec3[i][2]]);
    max_r[n - 1] = vec2[vec3[n - 1][2]];
    for (int i = n - 2; i >= 0; i--) max_r[i] = max(max_r[i + 1], vec2[vec3[i][2]]);
    for (int i = 0; i < n - 1; i++) if (min_l[i] > max_r[i + 1]) s++;
    cout << s << "\n";
}
