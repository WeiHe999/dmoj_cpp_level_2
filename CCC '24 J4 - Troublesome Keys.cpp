#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, str2;
    cin >> str1 >> str2;
    char silly1 = '-', silly2 = '-', quiet = '-';
    int ind = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] == quiet)
        {
            ind++;
            continue;
        }
        if (i - ind >= str2.size())
        {
            quiet = str1[i];
            break;
        }
        if (str1[i] != str2[i - ind] && (str1[i] != silly1 || str2[i - ind] != silly2))
        {
            if (i + 1 >= str1.size())
            {
                silly1 = str1[i];
                silly2 = str2[i - ind];
                break;
            }
            int j = i + 1;
            while (str1[j] == str1[j - 1]) j++;
            if (str1[j] != str2[i - ind])
            {
                silly1 = str1[i];
                silly2 = str2[i - ind];
                if (quiet != '-') break;
            }
            else
            {
                quiet = str1[i];
                ind++;
                if (silly1 != '-') break;
            }
        }
    }
    cout << silly1 << " " << silly2 << "\n" << quiet << "\n";
}
