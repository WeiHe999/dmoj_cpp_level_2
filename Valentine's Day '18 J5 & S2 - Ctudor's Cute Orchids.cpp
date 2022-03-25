#include <bits/stdc++.h>
using namespace std;

void combinations(int ind, vector <int> vec1, vector <int> vec2, vector <int> reg_costs, vector <int> deal_costs,
vector <vector <int> > deals, vector <int> tot_items, int &min_cost)
{
    if (vec2.size() > 0 && vec2.size() <= vec1.size())
    {
        int cost = 0;
        vector <int> rem_items = tot_items;
        bool flag = false;
        for (int y = 0; y < vec2.size(); y++)
        {
            cost += deal_costs[vec2[y] - 1];
            for (int m = 0; m < tot_items.size(); m++)
            {
                rem_items[m] -= deals[vec2[y] - 1][m];
                if (rem_items[m] < 0)
                {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag)
        {
            for (int z = 0; z < rem_items.size(); z++)
            {
                cost += reg_costs[z] * rem_items[z];
            }
            min_cost = min(cost, min_cost);
        }
    }
    if (vec2.size() > vec1.size()) return;
    for (int x = ind + 1; x < vec1.size(); x++)
    {
        vector <int> vec3 = vec2;
        vec3.emplace_back(vec1[x]);
        combinations(x, vec1, vec3, reg_costs, deal_costs, deals, tot_items, min_cost);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, c, b, d;
    cin >> n >> m;
    vector <int> reg_costs, deal_costs, tmp, vec1;
    vector <vector <int> > deals;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        reg_costs.emplace_back(a);
    }
    for (int y = 0; y < m; y++)
    {
        vec1.emplace_back(y + 1);
        tmp = {};
        cin >> c;
        deal_costs.emplace_back(c);
        for (int z = 0; z < n; z++)
        {
            cin >> b;
            tmp.emplace_back(b);
        }
        deals.push_back(tmp);
    }
    int min_cost;
    vector <int> tot_items, vec2;
    for (int e = 0; e < n; e++)
    {
        cin >> d;
        tot_items.emplace_back(d);
        min_cost += reg_costs[e] * d;
    }
    combinations(-1, vec1, vec2, reg_costs, deal_costs, deals, tot_items, min_cost);
    cout << min_cost << endl;
}
