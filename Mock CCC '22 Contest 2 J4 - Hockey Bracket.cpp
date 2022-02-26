#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s, a, b, t;
    cin >> n >> s;
    vector <int> scores(n + 1, 0);
    unordered_map <int, vector <int> > group_id;
    //tot_teams: n, tot_num_groups : 
    for (int x = 1; x <= (n / s); x++) //groups
    {
        for (int y = 0; y < s; y++) //teams in a group
        {
            cin >> a;
            group_id[x].emplace_back(a);
        }
    }
    // for (auto f : group_id)
    // {
    //     cout << "group " << f.first << ": ";
    //     for (auto g : f.second) cout << g << " ";
    //     cout << endl;
    // }
    char r;
    for (int i = 0; i < ((n * s - n) / 2); i++)
    {
        cin >> a >> b >> r;
        if (r == 'W') scores[a] += 3;
        else if (r == 'L') scores[b] += 3;
        else
        {
            scores[a] += 1;
            scores[b] += 1;
        }
    }
    // for (auto h : scores) cout << h << " ";
    cin >> t;
    for (int j = 1; j <= (n / s); j++)
    {
        vector <pair <int, int> > vec1;
        for (auto k : group_id[j])
        {
            vec1.push_back({scores[k], -1 * k});
        }
        sort(vec1.rbegin(), vec1.rend());
        // cout << vec1.size() << endl;
        if (j == (n / s)) cout << vec1[t - 1].second * -1 << endl;
        else cout << vec1[t - 1].second * -1 << " ";
    }
}
