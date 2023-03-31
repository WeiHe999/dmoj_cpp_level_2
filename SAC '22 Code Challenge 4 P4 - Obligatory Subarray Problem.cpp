#include <bits/stdc++.h>
using namespace std;

long long find(long long num, vector <long long> vec1, long long n)
{
    long long s = 0, left = 1, right = 1, mx = INT_MIN, mn = INT_MAX;
    vector<pair<long long, long long> > v1;
    set<pair<long long, long long> > s1;
    s1.insert({vec1[1], 1});
    while (left < n )
    {
        mx = (s1.rbegin())->first, mn = (s1.begin())->first;
        if (mx - mn <= num )
        {
            // move right pointer
            if (right==n) break;
            right ++;
            s1.insert({vec1[right], right});
        }
        else 
        {
            s1.erase({vec1[right], right});
            v1.push_back({left, right-1});
            // move left pointer
            while (left < right)
            {
                left ++;
                s1.erase({vec1[left-1], left-1});
                if(s1.size()==0) 
                {
                    s1.insert({vec1[left], left});
                    break;
                }
                else
                {
                    mx = max((s1.rbegin())->first, vec1[right]), mn = min((s1.begin())->first, vec1[right]);
                    if (mx - mn <= num) 
                    {
                        s1.insert({vec1[right], right});
                        break;
                    }                    
                }

            }
        }
    }
    v1.push_back({left, right});
    long long n1 = v1[0].second - v1[0].first + 1;
    s += (1+n1)*n1/2;
    for (long long i=1; i<v1.size(); i++)
    {
        n1 = v1[i].second - v1[i].first + 1;
        s += (1+n1)*n1/2;
        if (v1[i].first<=v1[i-1].second) 
        {
            n1 = v1[i-1].second-v1[i].first + 1;
            s -= (1+n1)*n1/2;
        }
    }
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, b, t;
    cin >> n >> b >> t;
    vector <long long> vec1(n + 1);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    if (b == 0) cout << find(t, vec1, n) << "\n";
    else cout << find(t, vec1, n) - find(b - 1, vec1, n) << "\n";
}
