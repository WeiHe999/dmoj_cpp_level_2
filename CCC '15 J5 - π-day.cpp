#include <bits/stdc++.h>
using namespace std;

int rec(int pieces, int people, map <pair <int, int>, int> &memo)
{
    if (pieces < people) return 0;
    if (people == 1 || pieces == people) return 1;
    if (memo.count({pieces, people})) return memo[{pieces, people}];
    return memo[{pieces, people}] = rec(pieces - 1, people - 1, memo) + rec(pieces - people, people, memo);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    map <pair <int, int>, int> memo;
    cout << rec(n, k, memo) << "\n";
}
