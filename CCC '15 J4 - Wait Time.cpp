#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, t = -1, f, k;
    char l;
    cin >> m;
    vector <vector <int> > vec1;
    bool flag;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> f;
        if (l == 'W') t += f - 1;
        else t++;
        if (l != 'W')
        {
            flag = false;
            k = 0;
            while (!flag && k < vec1.size())
            {
                if (f == vec1[k][0]) flag = true;
                else k++;
            }
        }
        if (l == 'R')
        {
            if (flag) vec1[k][1] = t;
            else vec1.push_back({f, t, 0});
        }
        else if (l == 'S')
        {
            vec1[k][2] += t - vec1[k][1];
            vec1[k][1] = -1;
        }
    }
    for (int i = 0; i < vec1.size() - 1; i++)
    {
        for (int j = i + 1; j < vec1.size(); j++)
        {
            if (vec1[i][0] > vec1[j][0])
            {
                vector <int> tmp = vec1[i];
                vec1[i] = vec1[j];
                vec1[j] = tmp;
            }
        }
    }
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i][1] == -1) cout << vec1[i][0] << " " << vec1[i][2] << endl;
        else cout << vec1[i][0] << " " << -1 << endl;
    }
}
