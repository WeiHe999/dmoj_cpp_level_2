#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    string str1;
    while (true)
    {
        getline(cin, str1);
        if (str1 == "EOF") break;
        int count = 0, count2 = 0;
        while (str1 != "CLOSE")
        {
            if (str1 == "TAKE") count++;
            if (str1 == "SERVE") count2++;
            getline(cin, str1);
        }
        cout << count << " " << count - count2 << " ";
        n += count;
        if (n>999)
        {
            int k = n/999;
            n = n - k*999;
        }
        cout << n << endl;
    }
}
