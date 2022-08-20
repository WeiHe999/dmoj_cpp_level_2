#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(551);
    for (int x = 2; x <= 550; x++)
    {
        if (vec1[x] == 0)
        {
            for (int y = x * 2; y <= 550; y += x)
            {
                vec1[y]++;
            }
        }
    }
    int s = 2;
    while (n > 0)
    {
        if (vec1[s] == 0)
        {
            cout << s << "\n";
            n--;
        }
        s++;
    }
}
