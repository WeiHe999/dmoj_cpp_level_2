#include <bits/stdc++.h>
using namespace std;



void permutation(string prefix, int current, int len, vector<string> &result)
{
    if (prefix.size() == len)
    {
        result.push_back(prefix);
        return;
    }
    vector<char> r = {'W', 'L', 'T'};
    for (int i=0; i<3; i++)
    {
        string new_prefix = prefix;
        new_prefix += r[i];
        permutation(new_prefix, current+1, len, result);
    }
    
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int f_team, games, a, b, c, d;
    unordered_map<int, int> scores, scores1;
    set<pair<int, int> > all_games = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {2, 3}, {1, 4}};
    vector<pair<int, int> > v_games = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {2, 3}, {1, 4}};
    set<pair<int, int> > done_games;
    vector<pair<int, int> > left_games;
    cin >> f_team;
    cin >> games;
    vector<char> r = {'W', 'L', 'T'};
    for (int i=0; i<games; i++)
    {
        cin >> a >> b >> c >> d;
        if (c>d) scores[a] += 3;
        else if (c<d) scores[b] += 3;
        else
        {
            scores[b]+=1;
            scores[a]+=1;
        }
        done_games.insert({min(a, b), max(a, b)});
    }
    for (auto x: all_games)
    {
        if (!done_games.count(x)) left_games.push_back(x);
    }
   
    // check all games
   vector<string> result;
   string prefix;
   permutation(prefix, 0, left_games.size(), result);
   int ans = 0;
   for (int x = 0; x < result.size(); x++)
   {
        scores1 = scores;
        for (int y = 0; y < left_games.size(); y++)
        {
          if (result[x][y] == 'W') scores1[left_games[y].first] += 3;
          else if (result[x][y] == 'L') scores1[left_games[y].second] += 3;
          else
          {
              scores1[left_games[y].first] += 1;
              scores1[left_games[y].second] += 1;
          }
        }
        vector<pair<int, int> > vt;
        for (auto x: scores1)
        {
            vt.push_back({x.second, x.first});
        }
        sort(vt.rbegin(), vt.rend());
        if (vt[0].second==f_team && vt[0].first!=vt[1].first) ans++;
   }
    cout << ans << endl;
}
