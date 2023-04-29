#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    unordered_map <string, int> m1 = {{"C", 1}, {"C#", 2}, {"D", 3}, {"D#", 4}, {"E", 5}, {"F", 6}, {"F#", 7},
    {"G", 8}, {"G#", 9}, {"A", 10}, {"A#", 11}, {"B", 12}};
    for (int i = 1; i <= n; i++)
    {
        string n1, n2, n3, n4;
        cin >> n1 >> n2 >> n3 >> n4;
        int s1 = m1[n2] - m1[n1], s2 = m1[n3] - m1[n2], s3 = m1[n4] - m1[n3];
        if (s1 < 0) s1 += 12;
        if (s2 < 0) s2 += 12;
        if (s3 < 0) s3 += 12;
        if (s1 == 4 && s2 == 3 && s3 == 3) cout << "root\n";
        else if (s1 == 3 && s2 == 3 && s3 == 2) cout << "first\n";
        else if (s1 == 3 && s2 == 2 && s3 == 4) cout << "second\n";
        else if (s1 == 2 && s2 == 4 && s3 == 3) cout << "third\n";
        else cout << "invalid\n";
    }
}
