#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    long long h, v, a, s = 0;
    cin >> h >> v;
    vector <long long> ver_lines, hor_lines;
    unordered_map <long long, long long> m1;
    for (long long x = 0; x < h; x++)
    {
        cin >> a;
        hor_lines.emplace_back(a);
    }
    for (long long x = 0; x < v; x++)
    {
        cin >> a;
        ver_lines.emplace_back(a);
    }
    for (long long a = 0; a < h; a++) for (long long b = a + 1; b < h; b++) m1[abs(hor_lines[a] - hor_lines[b])]++;
    for (long long a = 0; a < v; a++) for (long long b = a + 1; b < v; b++) s += m1[abs(ver_lines[a] - ver_lines[b])];
    cout << s << endl;
}
