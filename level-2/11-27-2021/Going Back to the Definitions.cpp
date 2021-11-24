#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a;
    cin >> n;
    vector <string> vec1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(to_string(a));
    }
    sort(vec1.rbegin(), vec1.rend(), [](string a, string b){return a + b < b + a;});
    for (auto b : vec1) cout << b;
    cout << endl;
    
}
