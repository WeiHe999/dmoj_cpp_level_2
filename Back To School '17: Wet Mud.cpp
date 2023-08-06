#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, j, p, t, pos = 0;
    cin >> n >> m >> j;
    vector <long long> vec1(1e6 + 1, -1);
    for (long long i = 1; i <= m; i++)
    {
        cin >> p >> t;
        vec1[t] = p;
    }
    if (j>n)
    {
        cout << 0 << endl;
        return 0;
    }
    set <long long> s1;
    for (long long i = 1; i <= 1e6; i++)
    {
        if (vec1[i] == -1) continue;
        if (vec1[i] > pos) s1.insert(vec1[i]);
        else continue;
        
        long long cnt = 0;
        for (auto x : s1)
        {
            if (pos + j >= x) 
            {
                cnt++;
                pos = x;
                if (pos + j > n)
                {
                    cout << i << endl;
                    return 0;
                }
            }
            else break;
        }

        for (long long i = 1; i <= cnt; i++) s1.erase(s1.begin());
 
    }
    cout << "-1\n";
}
