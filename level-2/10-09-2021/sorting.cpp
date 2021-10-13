#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector <int> vec1;
    vector <int> min;
    vector <int> max;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (int x = 0; x < vec1.size(); x++)
    {
        if (vec1[x] == 0)
        {
            if (x == 0 || vec1[x - 1] == 0) min.emplace_back(INT_MIN);
            else min.emplace_back(vec1[x - 1]);
            if (x == vec1.size() - 1 || vec1[x + 1] == 0) max.emplace_back(INT_MAX);
            else max.emplace_back(vec1[x + 1]);
            continue;
        }
        if (x == vec1.size() - 1) break;
        if (vec1[x + 1] != 0 && vec1[x] > vec1[x + 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    int max_min = INT_MIN;
    int min_max = INT_MAX;
    for (int a = 0; a < min.size(); a++)
    {
        if (min[a] > max_min) max_min = min[a];
        if (max[a] < min_max) min_max = max[a];
    }
    if (min_max < max_min) cout << "NO" << endl;
    else cout << "YES" << endl;
}
