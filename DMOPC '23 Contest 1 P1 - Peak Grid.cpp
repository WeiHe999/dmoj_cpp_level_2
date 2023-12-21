#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if (k > n)
    {
        cout << "-1\n";
        return 0;
    }
    vector <vector <int> > vec1(n, vector <int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) vec1[i][j] = i * n + j + 1;
    for (int i = 1; i < k; i++)
    {
        int tmp = vec1[n - 1][n - i - 1];
        vec1[n - 1][n - i - 1] = vec1[n - i - 1][n - i - 1];
        vec1[n - i - 1][n - i - 1] = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << vec1[i][j] << " ";
        cout << "\n";
    }
}
