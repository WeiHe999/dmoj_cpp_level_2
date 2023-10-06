#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << "\n";
}

vector <vector <long long> > bit(5001, vector <long long>(5001));
vector <long long> vec1(1e5 + 1), dp(1e5 + 1);
const long long MM = 5001;


void update(long long x, long long y, long long ind)
{
    for (long long i = x; i <= 5000; i += (i & -i)) 
    {
        for (long long j = y; j <= 5000; j += (j & -j)) 
        {
            if (dp[ind] > dp[bit[i][j]]) bit[i][j] = ind;
        }
    }
}

long long query(long long x, long long y)
{
    long long s = 0;
    for (long long i = x; i >= 1; i -= (i & -i)) 
    {
        for (long long j = y; j >= 1; j -= (j & -j)) 
        {
            if (dp[s] < dp[bit[i][j]]) s = bit[i][j];
            
        }
    }
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, b, c, d, max_value=-1, max_ind=-1;
    cin >> n;
    vector <vector <long long> > towers(n, vector <long long>(5));
    for (long long i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        towers[i][0] = MM - c; // height
        towers[i][1] = MM - max(a, b); // length
        towers[i][2] = MM - min(a, b); // width
        towers[i][3] = d; // value
        towers[i][4] = i + 1; // id
    }
    sort(towers.begin(), towers.end());
    for (long long i = 1; i <= n; i++)
    {
        vec1[i] = query(towers[i - 1][1], towers[i - 1][2]);
        dp[i] = dp[vec1[i]] + towers[i - 1][3];
        if (dp[i] > max_value)
        {
            max_value = dp[i];
            max_ind = i;
        }
        update(towers[i - 1][1], towers[i - 1][2], i);
    }
    cout << max_value << "\n";
    vector <long long> vec2;
    while (max_ind != 0)
    {
        vec2.push_back(towers[max_ind - 1][4]);
        max_ind = vec1[max_ind];
    }
    cout << vec2.size() << "\n";
    for (int x = vec2.size() - 1; x >= 0; x--) cout << vec2[x] << " ";
    cout << "\n";
}
