#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << "\n";
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    string str1;
    cin >> n >> str1;
    vector <int> psa1(1), psa2(1);
    for (int a = 0; a < str1.size(); a++)
    {
        if (str1[a] == 'b')
        {
            psa1.emplace_back(psa1.back() + 1);
            psa2.emplace_back(psa2.back());
        }
        else
        {
            psa1.emplace_back(psa1.back());
            psa2.emplace_back(psa2.back() + 1);
        }
    }
    //cout << "b: ";
    //print(psa1);
    //cout << "r: ";
    //print(psa2);
    int mina = INT_MAX;
    for (int x = 1; x <= str1.size(); x++)
    {
        //cout << psa1[x-1] + psa2.back() - psa2[x-1] << "\n";
        // cout << psa1[x + 1] << " " << psa2.back() << " " << psa2[x] << "\n";
        mina = min(psa1[x-1] + psa2.back() - psa2[x-1], mina);
    }
    mina = min(psa1[str1.size()], mina);
    cout << mina << "\n";
}
