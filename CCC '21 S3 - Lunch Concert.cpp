#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <pair <long long, pair <bool, long long> > > vec1;
    long long a, x, y, z, left = 0, right = 0, ans = 0, tmp;
    cin >> a;
    for (long long i = 0; i < a; i++)
    {
        cin >> x >> y >> z;
        vec1.push_back(make_pair(max(0LL,x-z),make_pair(false,y)));
        vec1.push_back(make_pair(x + z,make_pair(true, y)));
        ans += max(0LL,x - z) * y;
        right += y;
    }
    sort(vec1.begin(), vec1.end(), [](pair <long long, pair <bool, long long> > a, pair <long long, pair <bool, long long> > b)
    {if (a.first < b.first) return true; else return false;});
    vec1.insert(vec1.begin(), make_pair(0LL, make_pair(false, 0LL)));
    tmp = ans;
    for (long long i = 1; i < vec1.size();i++)
    {
        while (i < vec1.size() && vec1[i - 1].first == vec1[i].first)
        {
            if (vec1[i].second.first) left += vec1[i].second.second;
            else right -= vec1[i].second.second;
            i++;
        }
        tmp += (left - right) * (vec1[i].first - vec1[i - 1].first);
        ans = min(tmp, ans);
        if (vec1[i].second.first) left += vec1[i].second.second;
        else right -= vec1[i].second.second;
    }
    cout << ans << "\n";
}
