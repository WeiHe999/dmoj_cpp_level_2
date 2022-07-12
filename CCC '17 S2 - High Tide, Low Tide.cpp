#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n);
    for (int i = 0; i < n; i++) cin >> vec1[i];
    sort(vec1.begin(), vec1.end());
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++) cout << vec1[n / 2 - i - 1] << " " << vec1[n / 2 + i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= n / 2; i++) cout << vec1[n / 2 - i + 1] << " " << vec1[n / 2 + i] << " ";
        cout << vec1[0] << "\n";
    }
}
