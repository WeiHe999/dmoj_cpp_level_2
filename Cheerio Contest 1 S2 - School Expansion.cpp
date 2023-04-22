#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, b, s = 0;
    cin >> n >> a >> b;
    priority_queue <vector <long long>, vector <vector <long long> >, greater <vector <long long> > > pq;
    pq.push({a + b, 0});
    for (long long i = 1; i <= n; i++)
    {
        vector <long long> current = pq.top();
        pq.pop();
        s += current[0];
        if (current[1] == 0) pq.push({current[0] + a, 0});
        pq.push({current[0] + b, 1});
    }
    cout << s << "\n";
}
