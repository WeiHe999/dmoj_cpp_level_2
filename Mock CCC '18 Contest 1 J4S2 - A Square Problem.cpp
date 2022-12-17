#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    bool flag = true, flag2 = true;
    char a;
    vector <char> vec1 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D',
    'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    unordered_map <char, unordered_set <int> > row, col;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            if (i == 0) if (vec1[j] != a) flag2 = false;
            if (j == 0) if (vec1[i] != a) flag2 = false;
            if (row[i].count(a)) flag = false;
            else row[i].insert(a);
            if (col[j].count(a)) flag = false;
            else col[j].insert(a);
        }
    }
    if (!flag) cout << "No\n";
    else
    {
        if (!flag2) cout << "Latin\n";
        else cout << "Reduced\n";
    }
}
