#include <bits/stdc++.h>
using namespace std;

long long to_base10(long long b1, string num)
{
    long long b10_num = 0;
    long long p = 1;
    for (long long a = num.size() - 1; a >= 0; a--)
    {
        b10_num += (num[a] - '0') * p;
        p = p*b1;
    }
    return b10_num;
}


string from_base10(long long b2, long long n)
{
    string str1 = "";
    while (n != 0)
    {
        str1 += to_string(n % b2);
        n /= b2;
    }
    reverse(str1.begin(), str1.end());
    return str1;
}


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long q, b1, b2;
    string n;
    cin >> q;
    for (long long x = 0; x < q; x++)
    {
        cin >> b1 >> n >> b2;
        cout << from_base10(b2, to_base10(b1, n)) << endl;
    }
}
