#include <bits/stdc++.h>
using namespace std;

void find_combinations(vector <int> vec1, int index, int n, int x, int &s)
{
    if (x < 0) return;
    if (x == 0)
    {
        if (index == 1) return;
        s++;
        cout << n << "=";
        for (int i = 0; i < index; i++)
        {
            if (i == index - 1) cout << vec1[i] << endl;
            else cout << vec1[i] << "+";
        }
        return;
    }
    int prev;
    if (index == 0) prev = 1;
    else prev = vec1[index - 1];
    for (int k = prev; k <= n; k++)
    {
        vec1[index] = k;
        find_combinations(vec1, index + 1, n, x - k, s);
    }
}

int main()
{
    int n, s = 0;
    cin >> n;
    vector <int> vec1(n);
    find_combinations(vec1, 0, n, n, s);
    cout << "total=" << s << endl;
}
