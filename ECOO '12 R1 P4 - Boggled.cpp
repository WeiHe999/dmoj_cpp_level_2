#include <bits/stdc++.h>
using namespace std;

bool check_existence(pair <int, int> d, vector <vector <char> > table, string word, int ind, set <pair <int, int> > &visited)
{
    if (ind == word.size())
    {
        return true;
    }
    vector <pair <int, int> > check = {{d.first - 1, d.second - 1}, {d.first - 1, d.second}, {d.first - 1, d.second + 1}, {d.first, d.second - 1},
    {d.first, d.second + 1}, {d.first + 1, d.second - 1}, {d.first + 1, d.second}, {d.first + 1, d.second + 1}};
    for (auto e : check)
    {
        if (e.first >= 0 && e.first < 4 && e.second >= 0 && e.second < 4)
        {
            if (table[e.first][e.second] == word[ind] && !visited.count(make_pair(e.first, e.second)))
            {
                set <pair <int, int> > visited1 = visited;
                visited1.insert({e.first, e.second});
                if (check_existence(e, table, word, ind + 1, visited1)) return true;
            }
        }
    }
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string word;
    char c;
    int t = 5, n;
    for (int i=0; i<t; i++)
    {
        int score = 0;
        vector <vector <char> > table;
        unordered_map <char, vector <pair<int, int> > > m1;
        unordered_map <int, int> m2;
        unordered_set <string> visited;
        for (int i=0; i<4; i++)
        {
            vector<char> tmp;
            for (int j=0; j<4; j++)
            {
                cin >> c;
                tmp.push_back(c);
                m1[c].push_back({i, j});
            }
            table.push_back(tmp);
        }
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> word;
            if (word.size() < 3) m2[0]++;
            else if (visited.count(word)) m2[1]++;
            else
            {
                visited.insert(word);
                bool found = false;
                for (auto d : m1[word[0]])
                {
                    set <pair <int, int> > visited1 = {{d.first, d.second}};
                    if (check_existence(d, table, word, 1, visited1))
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    m2[3]++;
                    if (word.size() == 3 || word.size() == 4) score++;
                    else if (word.size() == 5) score += 2;
                    else if (word.size() == 6) score += 3;
                    else if (word.size() == 7) score += 4;
                    else score += 11;
                }
                else m2[2]++;
            }
        }
        cout << "Your score: " << score << " (" << m2[3] << " good, " << m2[2] << " not found, " << m2[0] << " too short, " << m2[1] << " repeated)" << endl;
    }
}
