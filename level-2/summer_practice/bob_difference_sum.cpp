#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    long long n;
    cin >> n;
    vector <int> vec1;
    long long s = 0;
    for (long long x = 0; x < n; x++)
    {
        int a;
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.rbegin(), vec1.rend());
    for (long long b = 0; b < n; b++)
    {
        s += (vec1[b] * (n - b - 1)) - b * vec1[b];
    }
    cout << s << endl;
}
