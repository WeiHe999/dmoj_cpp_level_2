#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, k, a, b, max = INT_MIN, ind;
    cin >> n >> k;
    vector <vector <int> > vec1;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec1.push_back({a, b, i + 1});
    }
    sort(vec1.rbegin(), vec1.rend());
    for (int a = 0; a < k; a++)
    {
        if (max < vec1[a][1])
        {
            max = vec1[a][1];
            ind = vec1[a][2];
        }
    }
    cout << ind << endl;
}

fork us on Github | like us on Facebook | help us translate | terms of service | 
English (en)
