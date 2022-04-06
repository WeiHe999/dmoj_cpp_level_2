#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}
int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, s = 0;
    cin >> n;
    unordered_map <int, int> m1;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        m1[a]++;
        vec1.emplace_back(a);
    }
    for (auto b : vec1)
    {
        for (int i = 1; i <= sqrt(b); i++)
        {
            if (b % i == 0)
            {
                if (b == i * i)
                {
                    if (m1.count(i)) s += m1[i];
                }
                else
                {
                    if (m1.count(i)) s += m1[i];
                    if (m1.count(b / i)) s += m1[b / i];
                }
            }
        }
        s--;
    }
    cout << s << endl;
}
