#include <bits/stdc++.h>
using namespace std;

bool check(vector <vector <int> > &board, set <int> &s1)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (s1.count(board[i][j])) board[i][j] = 0;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 && board[i][3] == 0 && board[i][4] == 0) return true;
    }
    for (int i = 0; i < 5; i++)
    {
        if (board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 && board[3][i] == 0 && board[4][i] == 0) return true;
    }
    if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) return true;
    if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0) return true;
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a;
    string str1;
    cin >> n;
    vector <string> vec1;
    vector <vector <vector <int> > > boards(n, vector <vector <int> >(5, vector <int>(5)));
    for (int i = 0; i < n; i++)
    {
        cin >> str1;
        vec1.push_back(str1);
        for (int j = 0; j < 5; j++) for (int k = 0; k < 5; k++) cin >> boards[i][j][k];
    }
    cin >> m;
    set <int> s1;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        s1.insert(a);
    }
    vector <string> bingo;
    for (int i = 0; i < n; i++)
    {
        if (check(boards[i], s1)) bingo.push_back(vec1[i]);
    }
    cout << bingo.size() << "\n";
    for (auto x : bingo) cout << x << "\n";
}
