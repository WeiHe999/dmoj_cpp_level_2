#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, b, most = 0, s = 0, prev = 1000001;
    cin >> n;
    vector <int> vec1, vec2, differences;
    for (int a = 0; a < n; a++)
    {
        cin >> b;
        vec1.emplace_back(b);
    }
    for (int a = 0; a < n; a++)
    {
        cin >> b;
        vec2.emplace_back(b);
        differences.emplace_back(vec2[a] - vec1[a]);
    }
    sort(differences.begin(), differences.end());
    for (int x = 0; x < differences.size(); x++)
    {
        if (differences[x] != prev)
        {
            if (most < s) most = s;
            s = 1;
            prev = differences[x];
        }
        else s++;
        if (x == differences.size() - 1) if (most < s) most = s;
    }
    cout << most << endl;
}
