#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = -1;
    cin >> n;
    string str1;
    vector <int> vec1(5), vec2;
    for (int x = 1; x <= n; x++)
    {
        cin >> str1;
        for (int y = 0; y < 5; y++) if (str1[y] == 'Y') vec1[y]++;
    }
    for (int i = 0; i < 5; i++)
    {
        if (vec1[i] > s)
        {
            s = vec1[i];
            vec2 = {i + 1};
        }
        else if (vec1[i] == s) vec2.emplace_back(i + 1);
    }
    cout << vec2[0];
    for (int i = 1; i < vec2.size(); i++) cout << "," << vec2[i];
    cout << "\n";
}
