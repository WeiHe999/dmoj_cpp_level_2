#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    string str1, a, cur;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        str1 += a + 'a';
    }
    vector <string> vec1;
    bool flag = false;
    for (int x = 0; x < str1.size(); x++)
    {
        if (flag)
        {
            if (isdigit(str1[x])) cur += str1[x];
            else
            {
                int ind = 0;
                while (ind < cur.size() && cur[ind] == '0') ind++;
                if (ind == cur.size()) ind--;
                vec1.emplace_back(cur.substr(ind));
                cur = "";
                flag = false;
            }
        }
        else if (isdigit(str1[x]))
        {
            flag = true;
            cur += str1[x];
        }
    }
    sort(vec1.begin(), vec1.end(), [](string a, string b){if (a.size() != b.size()) return a.size() < b.size(); else return a < b;});
    for (auto x : vec1) cout << x << "\n";
}
