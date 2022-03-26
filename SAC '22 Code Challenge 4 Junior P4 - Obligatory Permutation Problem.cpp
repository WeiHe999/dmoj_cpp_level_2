#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, a;
    cin >> n >> k;
    vector <long long> vec1 = {0};
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    vector <bool> vec2(n + 1, false);
    vector <long long> ans(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        if (vec2[i]) continue;
        vector <long long> vec3;
        for (int cur = i; !vec2[cur]; cur = vec1[cur])
        {
            vec3.emplace_back(cur);
            vec2[cur] = 1;
        }
        long long rem = k % vec3.size();
        for (int j = 0; j < vec3.size(); j++)
        {
            int cur = vec3[j], nxt = vec3[(j + rem) % vec3.size()];
            ans[nxt] = vec1[cur];
        }
    }
    for (long long g = 1; g < ans.size(); g++) cout << ans[g] << " ";
    cout << endl;
}
