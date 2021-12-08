#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m, f;
    vector <int> vec1(151), vec2(151), g(101);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    { 
        cin >> vec1[i] >> vec2[i];
        if (vec1[i] > vec2[i]) swap(vec1[i], vec2[i]);
    }
    bool flag;
    for (int i = 1; i <= n; i++)
    {
        for (f = 1; f <= 4; f++)
        {
            flag = true;
            for (int j = 0; j < m; j++) if (vec2[j] == i && g[vec1[j]] == f) flag = false;
            if (flag) break;
        }
        g[i] = f;
        cout << f;
    }
    cout << endl;
}
