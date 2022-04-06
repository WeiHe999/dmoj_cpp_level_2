#include <bits/stdc++.h>
using namespace std;

string construct(string str1, long long size)
{
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    if (size & 1) return str1 + str2.substr(1);
    return str1 + str2;
}

long long generate(long long lower, long long upper)
{
    long long count = stol(to_string(upper).substr(0, ceil(to_string(lower).size() / 2.0))) - stol(to_string(lower).substr(0, ceil(to_string(lower).size() / 2.0))) - 1;
    if (stol(construct(to_string(stol(to_string(lower).substr(0, ceil(to_string(lower).size() / 2.0)))), to_string(lower).size())) >= lower) count++;
    if (stol(construct(to_string(stol(to_string(upper).substr(0, ceil(to_string(lower).size() / 2.0)))), to_string(lower).size())) <= upper) count++;
    return count;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long l, r, s = 0, size_lower, size_upper;
    cin >> l >> r;
    size_lower = to_string(l).size();
    size_upper = to_string(r).size();
    for (long long x = size_lower; x <= size_upper; x++)
    {
        long long lower = l;
        if (to_string(l).size() < x)
        {
            string lower_s = "";
            for (long long y = 0; y < x; y++) lower_s += "0";
            lower_s[0] = '1';
            lower = stol(lower_s);
        }
        long long upper = r;
        if (to_string(r).size() > x)
        {
            string upper_s = "";
            for (long long y = 0; y < x; y++) upper_s += "9";
            upper = stol(upper_s);
        }        
        s += generate(lower, upper);
    }
    cout << s << endl;
}
