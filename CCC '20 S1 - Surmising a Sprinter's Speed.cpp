#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    double min_speed = 0;
    cin >> n;
    vector <pair <int, int> > vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        vec1.push_back({a, b});
    }
    sort(vec1.begin(), vec1.end());
    for (int k = 0; k < vec1.size() - 1; k++)
    {
        min_speed = max(min_speed, abs(vec1[k].second - vec1[k + 1].second) / (abs(vec1[k].first - vec1[k + 1].first) * 1.0));
    }
    cout << setprecision(5) << fixed << min_speed << "\n";
}
