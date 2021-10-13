#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    int ans = 0, low = 0, high = n - 1;
    while (low < high)
    {
        if (vec1[low] == vec1[high])
        {
            low++; high--;
            continue;
        }
        if (vec1[low] < vec1[high])
        {
            vec1[low + 1] += vec1[low];
            low++;
        }
        else
        {
            vec1[high - 1] += vec1[high];
            high--;
        }
        ans++;
    }
    cout << ans << endl;
}
