#include <bits/stdc++.h>
using namespace std;

double find_median(vector <int> vec1)
{
    if (vec1.size() % 2 == 1)
    {
        return vec1[vec1.size() / 2];
    }
    else
    {
        return (vec1[vec1.size() / 2 - 1] + vec1[vec1.size() / 2]) * 0.5;
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1, vec2, vec3;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec2.emplace_back(a);
    }
    sort(vec2.begin(), vec2.end());
    for (int x = 0; x < n; x++)
    {
        if (x < floor(n * 0.5)) vec1.emplace_back(vec2[x]);
        if (x >= n - floor(n * 0.5)) vec3.emplace_back(vec2[x]);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec3.begin(), vec3.end());
    cout << vec2[0] << " " << vec2.back() << " " << fixed << setprecision(1) << find_median(vec1) << " " << fixed << setprecision(1) << find_median(vec2) << " " << fixed << setprecision(1) <<find_median(vec3) << endl;
}
