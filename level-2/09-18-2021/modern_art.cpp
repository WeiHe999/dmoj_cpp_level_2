#include <bits/stdc++.h>

using namespace std;

int main() {  
    cin.sync_with_stdio(0);
    cin.tie(0); 
    int r, c, k;
    cin >> r >> c >> k;
    vector <int> row;
    vector <int> col;
    row.assign(r, 0);
    col.assign(c, 0);
    for (int a = 0; a < k; a++)
    {
        char b;
        int d;
        cin >> b >> d;
        if (b == 'R') row[d - 1]++;
        if (b == 'C') col[d - 1]++;
    }
    vector <vector <int> > vec1;
    vec1.assign(r, vector <int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) vec1[i][j] += row[i];
    }
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++) vec1[i][j] += col[j];
    }
    int s = 0;
    for (auto i : vec1)
    {
        for (auto j : i)
        {
            if (j % 2 == 1) s++;
        }
    } 
    cout << s << endl;
}
