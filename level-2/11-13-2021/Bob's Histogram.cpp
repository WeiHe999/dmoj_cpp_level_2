#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, average = 0, s = 0;
    cin >> n;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
        average += a;
    }
    float b = average / (n * 1.0);
    int c = round(b);
    for (auto a : vec1) s += pow(a - c, 2);
    cout << s << endl;
}
