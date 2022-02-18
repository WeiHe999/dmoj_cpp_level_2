#include <bits/stdc++.h>
using namespace std;

void permute(long long n, vector <char> a, string prefix, string max_string, long long &count)
{
    if (prefix.size() == n)
    {
        if (prefix <= max_string) count++;
        return;
    }
    else
    {
        for (int x = 0; x < a.size(); x++)
        {
            string new_prefix = prefix + a[x];
            permute(n, a, new_prefix, max_string, count);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long s = 0;
    string str1;
    cin >> str1;
    for (long long x = 1; x < str1.size(); x++)
    {
        s += pow(2, x);
    }
    vector <char> a = {'2', '3'};
    permute(str1.size(), a, "", str1, s);
    cout << s << endl;
}
