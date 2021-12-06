#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    long long n, q, a;
    cin >> n >> q;
    vector <long long> values;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        if(a > 0) values.emplace_back(a);
    }
    sort(values.rbegin(), values.rend());
    vector <long long> vec1;
    for(long long i = 0; i < values.size(); i++)
    {
        if(i == 0) vec1.push_back(values[i]);
        else vec1.push_back(vec1[i - 1] + values[i]);
    }
    for (long long b = 0; b < q; b++)
    {
        cin >> a;
        if(a >= values.size()) cout << vec1.back() << endl;
        else cout << vec1[a - 1] << endl;
    }
}
