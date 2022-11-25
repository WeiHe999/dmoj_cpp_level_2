#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <char> vec1 = {'*', 'x', '*'}, vec2 = {' ', 'x', 'x'}, vec3 = {'*', ' ', '*'};
    int n;
    cin >> n;
    for (int y = 0; y < n; y++)
    {
        for (auto x : vec1)
        {
            for (int z = 0; z < n; z++)
            {
                cout << x;
            }
        }
        cout << "\n";
    }
    for (int y = 0; y < n; y++)
    {
        for (auto x : vec2)
        {
            for (int z = 0; z < n; z++)
            {
                cout << x;
            }
        }
        cout << "\n";
    }
    for (int y = 0; y < n; y++)
    {
        for (auto x : vec3)
        {
            for (int z = 0; z < n; z++)
            {
                cout << x;
            }
        }
        cout << "\n";
    }
}
