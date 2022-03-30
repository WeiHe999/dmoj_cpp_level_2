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
    long long n, k, a1, a2, b1, b2;
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    vector <long long> vec1 = {0};
    unordered_map <long long, long long> m1;
    for (long long x = 1; x <= n; x++)
    {
        vec1.emplace_back(x);
    }
    unordered_set <long long> visited;
    vector <long long> ans(n + 1);
    reverse(vec1.begin() + a1, vec1.begin() + a2 + 1);
    // print(vec1);
    reverse(vec1.begin() + b1, vec1.begin() + b2 + 1);
    // print(vec1);
    for (long long b = 1; b < vec1.size(); b++)
    {
        m1[vec1[b]] = b;
    }
    for (long long i = 1; i <= n; i++)
    {
        if (visited.count(i)) continue;
        vector <long long> vec3;
        for (long long cur = i; !visited.count(cur); cur = m1[cur])
        {
            vec3.emplace_back(cur);
            visited.insert(cur);
        }
        long long rem = k % vec3.size();
        for (long long j = 0; j < vec3.size(); j++)
        {
            ans[vec3[(j + rem) % vec3.size()]] = vec3[j];
        }
    }
    for (long long g = 1; g < ans.size(); g++)
    {
        cout << ans[g] << endl;
    }
}
