#include <bits/stdc++.h>
using namespace std;

long long find_num_palindromes(long long n, unordered_map <long long, long long> &memo)
{
    if (n == 1 || n == 0)
    {
        memo[n] = 1;
        return 1;
    }
    long long s = 0;
    for (long long x = 1; x * 2 <= n; x++)
    {
        if (memo.count(n - (x * 2))) s += memo[n - (x * 2)];
        else s += find_num_palindromes(n - (x * 2), memo);
    }
    memo[n] = s + 1;
    return s + 1;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    unordered_map <long long, long long> memo;
    cout << find_num_palindromes(n, memo);
}
