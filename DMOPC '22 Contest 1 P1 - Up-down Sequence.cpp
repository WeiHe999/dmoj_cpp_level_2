#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        vector <int> vec1(n);
        for (int x = 0; x < n; x++) cin >> vec1[x];
        bool flag = false;
        string dir = "none";
        char cur_dir;
        for (int i = 0; i < n - 1; i++)
        {
            if (vec1[i] == 0 || vec1[i + 1] == 0) continue;
            if (vec1[i] == vec1[i + 1])
            {
                flag = true;
                break;
            }
            if ((vec1[i] < vec1[i + 1] && i % 2 == 0) || (vec1[i] > vec1[i + 1] && i % 2 == 1)) dir = "ud";
            else dir = "du";
        }
        if (flag)
        {
            cout << "NO\n";
            continue;
        }
        if (dir == "none")
        {
            cout << "YES\n";
            continue;
        }
        cur_dir = dir[1];
        for (int i = 0; i < n - 1; i++)
        {
            if (cur_dir == 'u') cur_dir = 'd';
            else cur_dir = 'u';
            if (vec1[i] == 0 || vec1[i + 1] == 0) continue;
            if ((cur_dir == 'u' && vec1[i] > vec1[i + 1]) || (cur_dir == 'd' && vec1[i] < vec1[i + 1])) flag = true;
        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }
}
