#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, s = 0;
    cin >> n;
    vector <int> vec1;
    unordered_set <int> s1;
    unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
        s1.insert(a);
        m1[a]++;
    }
    
    for (int b = 0; b < vec1.size(); b++)
    {
        for (int c = b + 1; c < vec1.size(); c++)
        {
            if (vec1[b]!=vec1[c] && (vec1[b] + vec1[c]) % 2 == 0 && m1.count((vec1[b] + vec1[c]) / 2))
            {
                s = max(vec1[b] + vec1[c] + (vec1[b] + vec1[c]) / 2, s);
            }
            if (vec1[b]==vec1[c] && m1[(vec1[b] + vec1[c])/2]>=3)
            {
                s = max(vec1[b] + vec1[c] + (vec1[b] + vec1[c]) / 2, s);
            }
        }
    }
    cout << s << "\n";
}
