#include <bits/stdc++.h>
using namespace std;

string dec_to_binary_reverse(int n)
{
    string str1;
    while (n > 0)
    {
        str1 += to_string(n % 2);
        n /= 2;
    }
    return str1;
}

int binary_to_dec(string str1)
{
    int n = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        n += pow(2, (str1.size() - i - 1)) * (str1[i] - '0');
    }
    return n;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        string str1 = dec_to_binary_reverse(n);
        cout << binary_to_dec(str1) << "\n";
    }
}
