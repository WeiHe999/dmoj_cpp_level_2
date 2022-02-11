#include <bits/stdc++.h>
using namespace std;

bool debug = 0;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    unordered_map <char, int> m1, m2, m3;
    vector <vector <char> > vec1;
    vector <char> vec2;
    char a;
    for (int x = 0; x < 3; x++)
    {
        vec2 = {};
        for (int y = 0; y < 3; y++)
        {
            cin >> a;
            m1[a]++;
            vec2.emplace_back(a);
        }
        vec1.push_back(vec2);
    }
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cin >> a;
            if (vec1[x][y] == a) 
            {
                if (debug) cout << "added 1: " << a << "at x=" << x << ", y=" << y << endl;
                m2[a]++;
            }
            else if (m1.count(a))
            {
                if (m3[a] < (m1[a] - m2[a]))
                {
                    if (debug) 
                    {
                        cout << "a=" << a << endl;
                        cout << "m1[a]=" << m1[a] << ", m2[a]=" << m2[a] << endl;
                        cout << "m3[a] = " << m3[a] << endl;
                    }
                    m3[a]++;
                }
            }
        }
    }
    if (debug)
    {
        cout << "map 1" << endl;
        for (auto z : m1)
        {
            cout << z.first << " " << z.second << endl;
        }
        cout << endl << "map 2" << endl;
        for (auto z : m2)
        {
            cout << z.first << " " << z.second << endl;
        }
        cout << endl << "map 3" << endl;
        for (auto z : m3)
        {
            cout << z.first << " " << z.second << endl;
        }
        cout << endl;
    }
    int s = 0;
    for (auto z : m2)
    {
        s += z.second;
    }
    cout << s << endl;
    s = 0;
    for (auto b : m3)
    {
        s += min(b.second, m1[b.first] - m2[b.first]);
    }
    cout << s << endl;
}
