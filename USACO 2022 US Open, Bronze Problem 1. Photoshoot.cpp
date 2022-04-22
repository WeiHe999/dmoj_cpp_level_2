#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    string str1;
    cin >> n >> str1;
    vector <char> vec1;
    for (int x = 0; x < str1.size(); x += 2)
    {
        if (str1[x] == str1[x + 1]) continue;
        if (str1[x] == 'G' && str1[x + 1] == 'H')
        {
            if (vec1.size() == 0 || vec1.back() == 'T') vec1.emplace_back('F');
        }
        if (str1[x] == 'H' && str1[x + 1] == 'G')
        {
            if (vec1.size() == 0 || vec1.back() == 'F') vec1.emplace_back('T');
        }
    }
    if (vec1.back() == 'T') cout << vec1.size() - 1 << endl;
    else cout << vec1.size() << endl;
}
