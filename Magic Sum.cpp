#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, b, s = 0;
    cin >> n;
    unordered_set <long long> s1;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
           a = i;
           b = n / i;
           if ((b - 1) != 0 && n / (b - 1) == (n % (b-1))) 
           {
               s1.insert(b-1);
           }
           a = n / i;
           b = i;
           if ((b - 1) != 0 && n / (b - 1) == (n % (b-1))) 
           {
               s1.insert(b-1);
           }
        }
    }
    for (auto x : s1) s += x;
    cout << s << "\n";
}
