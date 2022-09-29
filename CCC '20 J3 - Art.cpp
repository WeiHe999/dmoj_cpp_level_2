#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    int min1 = INT_MAX, max1 = INT_MIN, min2 = INT_MAX, max2 = INT_MIN;
    string a;
    int b, c;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        if (isdigit(a[1]))
        {
            b = stoi(a.substr(0, 2));
            c = stoi(a.substr(3));
        }
        else
        {
            b = stoi(a.substr(0, 1));
            c = stoi(a.substr(2));
        }
        min1 = min(b, min1);
        max1 = max(b, max1);
        min2 = min(c, min2);
        max2 = max(c, max2);
    }
    cout << min1 - 1 << "," << min2 - 1 << "\n" << max1 + 1 << "," << max2 + 1;
}
