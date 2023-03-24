#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, mina = INT_MAX;
    string str1;
    cin >> n >> k >> str1;
    bool flag = false;
    unordered_map <char, int> m1;
    char c;
    for (int i = 0; i < str1.size(); i++) m1[str1[i]]++;
    for (int i = 0; i < 26; i++)
    {
        if (!m1.count('a' + i))
        {
            c = 'a' + i;
            flag = true;
            break;
        }
        else if (m1['a' + i] < mina)
        {
            mina = m1['a' + i];
            c = 'a' + i;
        }
    }
    if (flag)
    {
        if (0 <= k && k <= n)
        {
            for (int i = 1; i <= n - k; i++) cout << c;
            for (int i = n - k + 1; i <= n; i++) cout << str1[i - 1];
        }
        else cout << "WRONGANSWER";
    }
    else
    {
        if (mina <= k && k <= n)
        {
            string str2;
            for (int i = 1; i <= n; i++) str2 += c;
            int cnt = 0;
            for (int i = n; i >= 1; i--)
            {
                if (str1[i - 1] == c) continue;
                str2[i - 1] = str1[i - 1];
                cnt++;
                if (cnt == k - mina) break;
            }
            cout << str2;
        }
        else cout << "WRONGANSWER";
    }
    cout << "\n";
}
