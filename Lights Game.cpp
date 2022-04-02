#include <bits/stdc++.h>
using namespace std;

int fun(long long n)
{
    return static_cast<int>(sqrt(n));
}

int main()
{
    long long n;
    cin >> n;
    cout << fun(n) << endl;
}
