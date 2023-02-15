#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (int x = 1; x <= 5; x++)
    {
        int r, c, m;
        cin >> r >> c;
        vector <vector <char> > grid(r + 1, vector <char>(c + 1));
        string tmp, word;
        for (int i = 1; i <= r; i++)
        {
            cin >> tmp;
            for (int j = 1; j <= c; j++) grid[i][j] = tmp[j - 1];
        }
        cin >> m; cin.ignore();
        vector <vector <bool> > vis(r + 1, vector <bool>(c + 1, false));
        set <string> s1;
        int cnt = 0;
        for (int a = 0; a < m; a++)
        {
            getline(cin, word);
            string str1;
            for (int b = 0; b < word.size(); b++) if (isalpha(word[b])) str1 += toupper(word[b]);
            cnt++;
            for (int i = 1; i <= r; i++)
            {
                for (int j = 1; j <= c; j++)
                {
                    if (grid[i][j] == str1[0])
                    {
                        vector <pair <int, int> > dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
                        for (auto k : dir)
                        {
                            bool flag = true;
                            vector <pair <int, int> > recall = {{i, j}};
                            int x1 = i, y1 = j;
                            for (int ind = 1; ind < str1.size(); ind++)
                            {
                                x1 += k.first;
                                y1 += k.second;
                                if (x1 == 0 || x1 > r || y1 == 0 || y1 > c || grid[x1][y1] != str1[ind]) 
                                {
                                    flag = false;
                                    break;
                                }
                                recall.push_back({x1, y1});
                            }
                            if (flag)
                            {
                                s1.insert(str1);
                                for (auto l : recall) vis[l.first][l.second] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) if (!vis[i][j]) cout << grid[i][j];
        cout << "\n";
    }
}
