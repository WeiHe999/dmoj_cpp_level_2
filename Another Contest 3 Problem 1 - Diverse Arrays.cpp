#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, l = 1, s = 0;
    cin >> n >> k;
    vector <long long> vec1(n + 1);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    unordered_map <long long, long long> m1;
    for (long long r = 1; r <= n; r++)
    {
        m1[vec1[r]]++;
        if (m1.size() >= k) 
        {
            s += n - r + 1;
            while (m1.size() >= k)
            {
                m1[vec1[l]]--;
                if (m1[vec1[l]] == 0) m1.erase(vec1[l]);
                l++;
                if (m1.size() >= k) s += n - r + 1;
            }
        }
    }
    cout << s << "\n";
}
