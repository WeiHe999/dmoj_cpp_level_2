#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long low = 1, high = 2 * (pow(10, 9)), mid;
    string a;
    while (low < high)
    {
        mid = (low + high) / 2;
        cout << mid << endl << flush;
        cin >> a;
        if (a == "SINKS") low = mid + 1;
        else if (a == "FLOATS") high = mid - 1;
        else break;
    }
}
