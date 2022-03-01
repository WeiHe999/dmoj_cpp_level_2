#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, t, a, b, maxa = INT_MIN;
    cin >> n >> t;
    vector <pair <int, int> > trees = {{0, 0}, {n + 1, n + 1}};
    for (int x = 0; x < t; x++)
    {
        cin >> a >> b;
        trees.push_back({a, b});
    }
    sort(trees.begin(), trees.end());
    //for (auto c : trees) cout << c.first << " " << c.second << endl;
    vector <int> vec1;
    for (int c = 0; c < trees.size(); c++)
    {
        for (int d = c + 1; d < trees.size(); d++)
        {
            int delta_x = trees[d].first - trees[c].first - 1;
            vec1 = {};
            for (int e = 0; e < trees.size(); e++)
            {
                if (trees[e].first > trees[c].first && trees[e].first < trees[d].first)
                {
                    vec1.push_back(trees[e].second);
                }
            }
            vec1.emplace_back(0);
            vec1.emplace_back(n + 1);
            sort(vec1.begin(), vec1.end());
            int maxb = INT_MIN;
            // for (auto g : vec1) cout << g << " ";
            // cout << endl;
            for (int f = 0; f < vec1.size() - 1; f++) maxb = max(vec1[f + 1] - vec1[f] - 1, maxb);
            maxa = max(min(maxb, delta_x), maxa);
        }
    }
    cout << maxa << endl;
}
