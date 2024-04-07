#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k; 
    cin >> n >> k;
    vector <int> vec1(n);
    vector <vector <int> > vec2;
    for (int i = 0; i < n; i++) cin >> vec1[i];
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
    for (int i = 0; i < k; i++) pq.push({vec1[i], i});
    int cur = k;
    pair <int, int> p1;
    while (true)
    {
        vector <pair <int, int> > tmp;
        do
        {
            tmp.push_back(pq.top());
            pq.pop();
        } while (!pq.empty() && pq.top().first == tmp[0].first);
        if (tmp.size() > 1)
        {
            vector <int> vec3;
            for (auto x : tmp) vec3.push_back(x.second);
            vec2.push_back(vec3);
        }
        if (cur + tmp.size() > n)
        {
            p1 = tmp[0];
            break;
        }
        for (auto x : tmp)
        {
            pq.push({x.first + vec1[cur], x.second});
            cur++;
        }
    }
    cout << p1.first << "\n";
    vector <bool> vec4(k, false);
    vec4[p1.second] = true;
    for (int i = vec2.size() - 1; i >= 0; i--)
    {
        bool flag = false;
        for (int j : vec2[i])
        {
            if (vec4[j])
            {
                flag = true;
                break;
            }
        }
        if (flag) for (auto j : vec2[i]) vec4[j] = true;
    }
    vector <int> ans;
    for (int i = 0; i < k; i++) cout << vec4[i];
    cout << "\n";
}
