#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    unordered_map <int, char> m1 = {{0, 'O'}, {1, 'l'}, {3, 'E'}, {4, 'A'}, {5, 'S'}, {6, 'G'}, {8, 'B'}, {9, 'g'}};
    for (auto a : str1)
    {
        if (m1.count(a - '0')) cout << m1[a - '0'];
        else cout << a;
    }
    cout << endl;
}
