#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

vector <string> split (string str1)
{
    vector <string> vv;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vv.emplace_back(word);
    return vv;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, b;
    cin >> n >> m; cin.ignore();
    string a, str1, str2;
    getline(cin, a);
    vector <vector <int> > vec1;
    for (int x = 0; x < m; x++)
    {
        cin >> b;
        vec1.push_back({b, x + 1});
    }
    stable_sort(vec1.rbegin(), vec1.rend(), [](vector <int> a, vector <int> b){return a[0] < b[0];});
    int k = 0;
    for (int c = 0; c < a.size(); c++)
    {
        if (flag && a[c] == '0')
        {
            k++;
            if (k == vec1[0][1]) flag = false;
        }
        else if (flag) str2 += a[c];
        else str1 += a[c];
    }
    cout << str1 + str2 << endl;
}
