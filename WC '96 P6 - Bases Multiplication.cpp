#include <bits/stdc++.h>
using namespace std;

long long to_decimal(string str1, int base)
{
    long long power = 1, num = 0;
    for (long long i = str1.size() - 1; i >= 0; i--)
    {
        num += (str1[i] - '0') * power;
        power = power * base;
    }
    return num;
}

string convert(long long num, int base)
{
    string str1;
    while (num > 0)
    {
        str1 += to_string(num % base);
        num /= base;
    }
    reverse(str1.begin(), str1.end());
    return str1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (int i = 1; i <= 5; i++)
    {
        string str1, str2;
        int base1, base2, base3;
        cin >> str1 >> base1 >> str2 >> base2 >> base3;
        cout << convert(to_decimal(str1, base1) * to_decimal(str2, base2), base3) << "\n";
    }
}
