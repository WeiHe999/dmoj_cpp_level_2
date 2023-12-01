#include <bits/stdc++.h>
using namespace std;

long long search(vector <long long> &vec1, long long val)
{
    long long l = 0, r = vec1.size() - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (vec1[mid] < val) l = mid + 1;
        else if (vec1[mid] > val) r = mid - 1;
        else return mid;
    }
    return -1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n;
    cin >> n;
    vector <long long> vec1(n), vec2(n);
    vector <vector <long long> > vec1_s(n);
    vector <vector <long long> > vec2_s(n);
    unordered_map <long long, long long> vec1_ind;
    unordered_map <long long, long long> vec2_ind;
    long long s1 = 0, s2 = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> vec1[i] >> vec2[i];
        if (vec1_ind.find(vec1[i]) == vec1_ind.end())
            vec1_ind[vec1[i]] = s1++;
        if (vec2_ind.find(vec2[i]) == vec2_ind.end())
            vec2_ind[vec2[i]] = s2++;
        vec1_s[vec1_ind[vec1[i]]].push_back(vec2[i]);
        vec2_s[vec2_ind[vec2[i]]].push_back(vec1[i]);
    }
    for (long long i = 0; i < n; i++)
    {
        sort(vec1_s[i].begin(), vec1_s[i].end());
        sort(vec2_s[i].begin(), vec2_s[i].end());
    }
    long long s = 0;
    for (long long i = 0; i < n; i++)
    {
        long long ind1 = search(vec1_s[vec1_ind[vec1[i]]], vec2[i]), ind2 = search(vec2_s[vec2_ind[vec2[i]]], vec1[i]);
        long long l = ind2, r = vec2_s[vec2_ind[vec2[i]]].size() - ind2 - 1, d = ind1, u = vec1_s[vec1_ind[vec1[i]]].size() - ind1 - 1;
        s += (l * d) * (u * r) + (l * u) * (r * d);
    }
    cout << s << "\n";
}
