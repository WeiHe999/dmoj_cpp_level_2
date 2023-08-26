#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0, ind = -1;
    cin >> n;
    vector <long long> vec1(n + 1), order(n + 1), even, odd;
    bool flag = false;
    for (long long i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        if (vec1[i] % 2 == 1)
        {
            if (!flag) ind = i;
            else odd.emplace_back(i);
            flag = true;
        }
        else even.emplace_back(i);
    }
    if (flag)
    {
        order[1] = ind;
        s += (vec1[ind] - 1) / 2;
        for (long long i = 2; i <= even.size() + 1; i++)
        {
            order[i] = even[i - 2];
            s += (vec1[even[i - 2]] / 2) - 1;
        }
        for (long long i = even.size() + 2; i <= n; i++)
        {
            order[i] = odd[i - even.size() - 2];
            s += (vec1[odd[i - even.size() - 2]] - 1) / 2;
        }
    }
    else
    {
        for (long long i = 1; i <= n; i++)
        {
            order[i] = i;
            s += vec1[i] / 2;
        }
    }
    cout << s << "\n";
    for (long long i = 1; i <= n; i++) cout << order[i] << " ";
    cout << "\n";
}
