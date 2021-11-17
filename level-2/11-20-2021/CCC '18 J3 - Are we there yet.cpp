#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a, i = 0, j = 0;
    vector <int> dist, pos(5, 0);
    for (int x = 0; x < 4; x++)
    {
        cin >> a;
        dist.emplace_back(a);
    }
    for (int y = 1; y < 5; y++) pos[y] = pos[y - 1] + dist[y - 1];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) cout << abs(pos[j] - pos[i]) << " ";
        cout << endl;
    }
}
