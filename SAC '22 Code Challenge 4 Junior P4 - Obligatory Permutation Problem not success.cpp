#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

long long lcm(long long a, long long b)
{
    return (a * b) / __gcd(a, b);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, a;
    cin >> n >> k;
    vector <long long> original;
    unordered_map <long long, vector <long long> > ma;
    unordered_map <long long, long long> m_n;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        original.emplace_back(a);
        m_n[x+1] = a;
    }
    
    // for (auto x: m_n)
    // {
    //     cout << x.first << " : " << x.second << endl;
    // }
    
    // find the period for each digit
    for (long long i=0; i<original.size(); i++)
    {
        long long cnt = 0;
        //cout << original[i] << endl;
        ma[original[i]].push_back(i+1);
        long long next_pos = m_n[i+1];
        while (i+1!=next_pos )
        {
            cnt++;
            //cout << "cnt=" << cnt << endl; 
            if (cnt>k) break;
            ma[original[i]].push_back(next_pos);
            next_pos = m_n[next_pos];
  
        }
    }
    // for (auto x: ma)
    // {
    //     cout << x.first << ":";
    //     for (auto y: x.second) cout << y << ", ";
    //     cout << endl;
    // }
    
    // final vector
    vector <long long> vec_final(n, 0);
    for (auto c : original)
    {
        vec_final[ ma[c] [k % ma[c].size()]-1 ] = c;
    }
    for (int h=0; h<n; h++)
    {
        if (h<n-1) cout << vec_final[h] << " ";
        else cout << vec_final[h] << endl;
    }
}
