#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, s = 0;
    cin >> n;
    vector <int> vec1, vec2;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec2.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (vec1[i] > vec2[j]) j++;
        else
        {
            s++;
            i++;
            j++;
        }
    }
    cout << s << "\n";
}
