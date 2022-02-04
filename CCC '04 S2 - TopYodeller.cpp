#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a, rank, prev, tmp;
    cin >> n >> k;
    vector<int> scores(n, 0), worst_ranks(n, 0);
    vector<pair<int, int> > vec1;
    vector <vector <int> > vec2; 
    for (int x = 0; x < k; x++)
    {
        vec1 = {};
        for (int y = 1; y <= n; y++)
        {
            cin >> a;
            scores[y-1] += a; //tot score
            vec1.push_back({scores[y-1], y});
        }
        vector<int> ranks(n, 0);
        sort(vec1.rbegin(), vec1.rend());
        rank = 1;
        prev = vec1[0].first;
        ranks[vec1[0].second-1] = rank;
        for (int z = 1; z < vec1.size(); z++)
        {
            if (vec1[z].first != prev) rank = z + 1;
            ranks[vec1[z].second-1] = rank;
            prev = vec1[z].first;
        }
        for (int i=0; i<n; i++)
        {
            worst_ranks[i] = max(worst_ranks[i], ranks[i]);
        }

    }

    for (int i=0; i<n; i++) vec2.push_back({scores[i], (i+1) * -1, worst_ranks[i]});
    sort(vec2.rbegin(), vec2.rend());
    for (int j = 0; j < vec2.size(); j++)
    {
        if (j == 0) tmp = vec2[j][0];
        else if (tmp > vec2[j][0]) break;
        cout << "Yodeller " << vec2[j][1] * -1 << " is the TopYodeller: score " << vec2[j][0] << ", worst rank " << vec2[j][2] << endl;
    }
}
