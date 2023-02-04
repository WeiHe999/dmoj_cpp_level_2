#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, r, s, d;
    cin >> n;
    vector <pair <int, string> > vec1;
    string name, str1, str2;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> r >> s >> d;
        vec1.push_back({2 * r + 3 * s + d, name});
    }
    sort(vec1.begin(), vec1.end(), [](pair <int, string> a, pair <int, string> b){if (a.first == b.first) return a.second < b.second; else return a > b;});
    if (vec1.size() == 1) cout << vec1[0].second << "\n";
    else if (vec1.size() > 1) cout << vec1[0].second << "\n" << vec1[1].second << "\n";
}
