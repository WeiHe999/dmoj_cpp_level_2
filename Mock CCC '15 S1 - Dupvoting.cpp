#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int p, u, a, b, cnt = 0, y1, y2, y3;
    cin >> p >> u >> a >> b;
    set <vector <int> > s1, s2;
    for (int i = 1; i <= u; i++)
    {
        y1 = i;
        if ((y1*b) % a==0) 
        {
            y2 = (y1*b)/a;
            y3 = u - y1 - y2;
            if (y3 > 0) s1.insert({y1, y2, y3});
        }
    }
    for (auto x : s1)
    {
        if (2 * x[0] + x[1] - x[2] == p) s2.insert({x[0], x[1], x[2]});
        if (2 * x[0] + x[2] - x[1] == p) s2.insert({x[0], x[2], x[1]});
        if (2 * x[1] + x[0] - x[2] == p) s2.insert({x[1], x[0], x[2]});
        if (2 * x[1] + x[2] - x[0] == p) s2.insert({x[1], x[2], x[0]});
        if (2 * x[2] + x[0] - x[1] == p) s2.insert({x[2], x[0], x[1]});
        if (2 * x[2] + x[1] - x[0] == p) s2.insert({x[2], x[1], x[0]});
    }
    cout << s2.size() << "\n";
   
}
