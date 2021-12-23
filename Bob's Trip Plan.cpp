#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, cost = 0, c2;
    cin >> n;
    vector <int> vec1 = {0};
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    vec1.emplace_back(0);
    for (int b = 1; b < vec1.size(); b++) cost += abs(vec1[b] - vec1[b - 1]);
    for (int c = 1; c < vec1.size() - 1; c++)
    {
        c2 = cost;
        c2 -= abs(vec1[c] - vec1[c - 1]) + abs(vec1[c] - vec1[c + 1]) - abs(vec1[c - 1] - vec1[c + 1]);
        cout << c2 << endl;
    }
}
