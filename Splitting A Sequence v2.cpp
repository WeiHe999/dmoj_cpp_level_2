#include <bits/stdc++.h>
using namespace std;

long long check(vector <long long> &vec1, long long q, long long m)
{
    long long s = 0;
    long long divide = m - 1;
    bool flag = false;
    for (long long x = 0; x < vec1.size(); x++)
    {
        if (s + vec1[x] > q)
        {
            divide--;
            s = vec1[x];
            if (s > q) return 1;
        }
        else s += vec1[x];
        if (s == q) flag = true;
    }
    if (divide == 0)
    {
        if (flag) return 0;
        return -1;
    }
    if (divide > 0) return -1;
    return 1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, sum = 0, maxa = 0;
    cin >> n >> m;
    vector <long long> vec1(n);
    for (long long x = 0; x < n; x++)
    {
        cin >> vec1[x];
        sum += vec1[x];
        maxa = max(vec1[x], maxa);
    }
    long long low = 0, high = sum, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int a = check(vec1, mid, m);
        if (a == 0)
        {
            cout << mid << "\n";
            return 0;
        }
        else if (a == -1) high = mid - 1;
        else if (a == 1) low = mid + 1;
    }
    cout << maxa << "\n";
}
