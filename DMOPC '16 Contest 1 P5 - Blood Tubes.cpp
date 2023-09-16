#include <bits/stdc++.h>
using namespace std;

void update(int num, vector <vector <int> > &bit)
{
    for (int x = num; x < bit[1].size(); x += (x & (-x))) bit[0][x]++;
    for (int x = bit[1].size() - num; x < bit[1].size(); x += (x & (-x))) bit[1][x]++;
}

int query(int num, vector <vector <int> > &bit)
{
    int s1 = 0, s2 = 0;
    for (int x = num; x >= 1; x -= (x & (-x))) s1 += bit[0][x];
    for (int x = bit[0].size() - num; x >= 1; x -= (x & (-x))) s2 += bit[1][x];
    return min(s1, s2);
}

int main() 
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, s = 0;
    cin >> n;
    vector <vector <int> > bit(2, vector <int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        s += query(a, bit);
        update(a, bit);
    }
    cout << s << "\n";
}
