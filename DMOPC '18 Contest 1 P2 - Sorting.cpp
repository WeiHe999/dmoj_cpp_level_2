#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a;
    cin >> n >> k;
    vector <int> vec1, sorted;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
        sorted.emplace_back(x + 1);
    }
    bool flag = true;
    for (int b = 0; b < vec1.size(); b++)
    {
        if (abs(b + 1 - sorted[vec1[b] - 1]) % k != 0)
        {
            flag = false;
            break;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
