#include <bits/stdc++.h>
using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, w, a, s = 0, num;
    cin >> n >> w;
    vector <long long> vec1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    for(long long i = 0; i < vec1.size(); i++)
    {
        num = upper_bound(vec1.begin(), vec1.end(), w - vec1[i]) - vec1.begin();
        if (num > i) s += num - i - 1;
    }
    cout << s << endl;
}
