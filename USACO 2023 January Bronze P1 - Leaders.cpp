#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, g_left = -1, g_right = -1, h_left = -1, h_right = -1, s = 0;
    string str1;
    cin >> n >> str1;
    vector <int> vec1(n);
    for (int x = 0; x < n; x++) 
    {
        cin >> vec1[x];
        vec1[x]--;
        if (str1[x] == 'G' && g_left == -1) g_left = x;
        if (str1[x] == 'H' && h_left == -1) h_left = x;
    }
    for (int x = n - 1; x >= 0; x--)
    {
        if (str1[x] == 'G' && g_right == -1) g_right = x;
        if (str1[x] == 'H' && h_right == -1) h_right = x;
        if (g_right != -1 && h_right != -1) break;
    }
    if (g_left == -1 || g_right == -1 || h_left == -1 || h_right == -1)
    {
        cout << "0\n";
        return 0;
    }
    if (vec1[g_left] >= g_right)
    {
        for (int i = 0; i < g_left; i++)
        {
            if (i == h_left) continue;
            if (str1[i] == 'H' && vec1[i] >= g_left) s++;
        }
    }
    if (vec1[h_left] >= h_right)
    {
        for (int i = 0; i < h_left; i++)
        {
            if (i == g_left) continue;
            if (str1[i] == 'G' && vec1[i] >= h_left) s++;
        }
    }
    if ((vec1[g_left] >= g_right || (g_left < h_left && vec1[g_left] >= h_left)) &&
    (vec1[h_left] >= h_right || (h_left < g_left && vec1[h_left] >= g_left))) s++;
    cout << s << "\n";
}
