#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, b, s = 0;
    cin >> n >> m;
    vector <vector <char> > board(n, vector <char>(n, 'F'));
    vector <vector <int> > queens;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        board[a - 1][b - 1] = 'Q';
        queens.push_back({a - 1, b - 1});
    }
    for (auto e : queens)
    {
        for (int c = 0; c < board.size(); c++)
        {
            for (int d = 0; d < board[c].size(); d++)
            {
                if (c == e[0])
                {
                    board[c][d] = 'O';
                    continue;
                }
                if (d == e[1] || board[c][d] == 'Q')
                {
                    board[c][d] = 'O';
                    continue;
                }
                if (abs(e[0] - c) == abs(e[1] - d))
                {
                    board[c][d] = 'O';
                }
            }
        }
    }
    for (auto f : board) for (auto g : f) if (g == 'F') s++;
    cout << s << endl;
}
