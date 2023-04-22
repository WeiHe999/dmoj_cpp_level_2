#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (int i = 1; i <= 10; i++)
    {
        unordered_map <string, int> m1;
        string str1;
        cin >> str1;
        while (str1 != "end")
        {
            m1[str1]++;
            cin >> str1;
        }
        cin >> str1 >> str1;
        cout << ceil(m1["orange"] / 7.0) * 13 + ceil(m1["blue"] / 7.0) * 13 + ceil(m1["green"] / 7.0) * 13 + ceil(m1["yellow"] / 7.0) * 13 +
        ceil(m1["pink"] / 7.0) * 13 + ceil(m1["violet"] / 7.0) * 13 + ceil(m1["brown"] / 7.0) * 13 + m1["red"] * 16 << "\n";
    }
}
