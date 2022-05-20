#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int l, r;
    cin >> l >> r;
    vector <int> vec1(r + 1);
    for (int i = 2; i <= r; i++)
    {
        if (vec1[i] == 0) for (int x = i; x <= r; x += i) vec1[x]++;
    }
    for (int y = l; y <= r; y++)
    {
        cout << vec1[y] << "\n";
    }
}
