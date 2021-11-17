#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, t, c;
    string s;
    cin >> n >> t;
    vector <vector <string> > combinations;
    vector <pair <string, int> > choices;
    vector <string> tmp;
    for (int x = 0; x < n; x++)
    {
        cin >> s >> c;
        choices.push_back({s, c});
    }
    sort(choices.begin(), choices.end());
    for (int a = 0; a < choices.size(); a++)
    {
        for (int b = a + 1; b < choices.size(); b++)
        {
            for (int c = b + 1; c < choices.size(); c++)
            {
                if (choices[a].second + choices[b].second + choices[c].second <= t)
                {
                    tmp = {choices[a].first, choices[b].first, choices[c].first};
                    sort(tmp.begin(), tmp.end());
                    combinations.push_back(tmp);
                }
            }
        }
    }
    sort(combinations.begin(), combinations.end());
    for (auto d : combinations) cout << d[0] << " " << d[1] << " " << d[2] << endl;
}
